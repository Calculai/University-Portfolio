import os
import numpy as np


# =============================================================================
# CONFIGURATION: Set to True/False to enable/disable each part
#
# Tip: while debugging, turn off parts you don't need so output stays readable.
# =============================================================================
SHOW_PART_A = True
SHOW_PART_B = True
SHOW_PART_C = True
SHOW_PART_D = True
SHOW_PART_E = True
# =============================================================================


try:
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except Exception:
    HAVE_MPL = False


LOT_HEIGHT = 20
LOT_WIDTH = 30
TARGET_ILLUMINATION = 1.0


def get_lamp_data():
    # lamp positions stored as a matrix
    return np.array([
        [2.0, 4.0, 3.0],
        [4.0, 13.0, 3.7],
        [4.0, 19.0, 3.0],
        [11.0, 5.0, 3.5],
        [12.0, 12.0, 4.0],
        [13.0, 18.0, 3.6],
        [16.0, 2.0, 4.5],
        [16.0, 16.0, 3.0],
        [20.0, 4.0, 3.1],
        [23.0, 12.0, 4.0],
        [13.0, 16.0, 3.6],
        [28.0, 9.0, 3.4],
    ], dtype=float)


def get_square_centers():
    # generate evenly spaced array starting at 0.5, stepping by 1.0, up to width/height
    x_centers = np.arange(0.5, LOT_WIDTH, 1.0)
    y_centers = np.arange(0.5, LOT_HEIGHT, 1.0)

    # generate a meshgrid of x and y centers to get all combinations of (x, y) pairs
    X, Y = np.meshgrid(x_centers, y_centers)

    # use ravel to reformat to 600,2 matrix of (x,y) pairs, that represent center of each square
    centers = np.column_stack((X.ravel(), Y.ravel()))
    return centers


def build_coefficient_matrix(lamp_data):
    # generate square center matrix
    centers = get_square_centers()

    # formatting
    # separate x and y coordinates of square centers into column vectors with shape (600, 1)
    square_x = centers[:, 0][:, None]
    square_y = centers[:, 1][:, None]

    # make lamp data into row vectors with shape (1, 12)
    lamp_x = lamp_data[:, 0][None, :]
    lamp_y = lamp_data[:, 1][None, :]
    lamp_h = lamp_data[:, 2][None, :]

    # broadcasting now computes all 600x12 pairwise distances
    # we get delta values for squre_x to lamp_x by subtracting which python broadcasts so it 
    # subtracts the lamp x values from each square x value and the same for y and h (height of parking lot is 0)
    # this delta is then squared for purpose of pythagorean distance like our equation from the assignment uses
    squared_distances = (square_x - lamp_x) ** 2 + (square_y - lamp_y) ** 2 + lamp_h ** 2
    # so we make a 600x12 matrix where each column is the distance from 1 lamp to all 600 squares

    # the linear system is the x/d^2 contribution from each lamp, so our coefficient are reciprocals of the squared distances
    A = 1.0 / squared_distances
    return A


def improved_gram_schmidt_qr(A):
    # use shape of coefficient matrix to set out amount of equations (m) and unknowns (n)
    m, n = A.shape

    # generate V to ensure float type 
    V = A.astype(float).copy()

    # make corresponding Q and R matrices 
    Q = np.zeros((m, n), dtype=float)
    R = np.zeros((n, n), dtype=float)

    for i in range(n):
        # length of current vector becomes diagonal R entry
        R[i, i] = np.linalg.norm(V[:, i])
        if R[i, i] == 0.0:
            raise ValueError("Matrix is rank-deficient; QR solve requires full column rank.")

        # normalize to get i-th orthonormal basis vector
        Q[:, i] = V[:, i] / R[i, i]

        for j in range(i + 1, n):
            # project remaining vectors onto q_i and subtract projection
            # (improved Gram-Schmidt step)
            R[i, j] = np.dot(Q[:, i], V[:, j])
            V[:, j] -= R[i, j] * Q[:, i]

    return Q, R


def back_substitution(R, b):
    
    n = R.shape[0]
    x = np.zeros(n, dtype=float)

    # solve from bottom row upward because R is upper triangular
    for i in range(n - 1, -1, -1):
        if R[i, i] == 0.0:
            raise ValueError("Upper-triangular solve failed because R has a zero diagonal entry.")
        x[i] = (b[i] - np.dot(R[i, i + 1:], x[i + 1:])) / R[i, i]

    return x


def solve_least_squares_qr(A, b):
    # Least squares with reduced QR:
    # A = Q R  ->  minimize ||Q R x - b||
    # equivalent to solving R x = Q^T b
    Q, R = improved_gram_schmidt_qr(A)
    rhs = Q.T @ b
    x = back_substitution(R, rhs)
    return x


def solve_least_squares_svd(A, b):
    # us numpy SVD
    U, s, Vt = np.linalg.svd(A, full_matrices=False)
    # compute coefficients of b in U basis, then divide by singular values to get coefficients in V basis
    coeffs = (U.T @ b) / s
    # reconstruct solution in original variable space by multiplying by V^T
    x = Vt.T @ coeffs
    return x


def reshape_to_lot(values):
    # reshape a 600 length vector to a 20x30 matrix
    return np.asarray(values).reshape(LOT_HEIGHT, LOT_WIDTH)


def save_heatmap(values, title, filename, vmin=None, vmax=None, cmap='viridis'):
    if not HAVE_MPL:
        print('matplotlib not available; skipping plot:', filename)
        return

    # fromat for lot setup
    image = reshape_to_lot(values)

    # generate output path
    out = os.path.join(os.path.dirname(__file__), filename)

    plt.figure(figsize=(10, 6))
    # imshow draws a matrix as an image. Using cmap to color code the values
    plt.imshow(
        image,
        origin='lower',
        extent=[0, LOT_WIDTH, 0, LOT_HEIGHT],
        aspect='equal',
        cmap=cmap,
        # sets limits for colors to handle outliers if needed
        vmin=vmin,
        vmax=vmax,
    )
    plt.colorbar(label='Illumination')
    plt.xlabel('x-position [m]')
    plt.ylabel('y-position [m]')
    plt.title(title)
    plt.tight_layout()
    plt.savefig(out, dpi=200)
    plt.close()
    print('Saved plot to', out)


def save_deviation_heatmaps(deviation_qr, deviation_svd):
    if not HAVE_MPL:
        print('matplotlib not available; skipping part (d) comparison plots.')
        return

    # reformat deviation values to 20x30 matrices for plotting
    dev_qr = reshape_to_lot(deviation_qr)
    dev_svd = reshape_to_lot(deviation_svd)

    # find the max value in both deviation matrices and use it for the limits
    # this way the color is scaled consistently so a strength of blue in one plot
    # means the same deviation as the same strength of blue in the other plot
    vmax = max(np.max(np.abs(dev_qr)), np.max(np.abs(dev_svd)))

    # generate path for output
    out = os.path.join(os.path.dirname(__file__), 'part_d_deviation_comparison.png')

    # create figure with two subplot for side-by-side comparison
    fig, axes = plt.subplots(1, 2, figsize=(12, 5), constrained_layout=True)

    # use imshow to plot deviation matrices as heatmaps, cmap makes is color coded
    im0 = axes[0].imshow(
        dev_qr,
        origin='lower',
        extent=[0, LOT_WIDTH, 0, LOT_HEIGHT],
        aspect='equal',
        cmap='coolwarm',
        # using found vmax
        vmin=-vmax,
        vmax=vmax,
    )
    axes[0].set_title('QR deviation from target 1.0')
    axes[0].set_xlabel('x-position [m]')
    axes[0].set_ylabel('y-position [m]')
    axes[1].imshow(
        dev_svd,
        origin='lower',
        extent=[0, LOT_WIDTH, 0, LOT_HEIGHT],
        aspect='equal',
        cmap='coolwarm',
        # using found vmax
        vmin=-vmax,
        vmax=vmax,
    )
    axes[1].set_title('SVD deviation from target 1.0')
    axes[1].set_xlabel('x-position [m]')
    axes[1].set_ylabel('y-position [m]')

    fig.colorbar(im0, ax=axes, shrink=0.9, label='Deviation from 1.0')
    plt.savefig(out, dpi=200)
    plt.close(fig)
    print('Saved plot to', out)


def part_a():
    # Part (a): build the linear system y = A x.
    lamp_data = get_lamp_data()
    centers = get_square_centers()
    A = build_coefficient_matrix(lamp_data)

    # A is out coefficients matrix storing the distances
    # which can then describe any y_j as sum of A[j, i] x_i where x_i is the strength of the lamp i
    # so given a strength vector x we can compute the illumination array for all points in the grid Y by doing A @ x

    if SHOW_PART_A:
        print('Constructed coefficient matrix A for y = A x')
        print('Lamp data shape:', lamp_data.shape)
        print('A shape:', A.shape)
        print('Number of parking squares:', centers.shape[0])
        print('First lamp [x, y, h]:', lamp_data[0])
        print('First square center [x, y]:', centers[0])

    return A


def part_b(A):
    # Part (b): all lamps set to identical strength 20.0.
    # make a vector of length 12 with lamp strengths (all set to 20)
    x_all_on = np.full(A.shape[1], 20.0)

    # multiply our coefficient matrix A by strength vector to get illumination at each square
    illumination = A @ x_all_on

    if SHOW_PART_B:
        print('All lamps turned on with strength 20.0.')
        print('Illumination statistics:')
        print(f'  min  = {illumination.min():.6f}')
        print(f'  max  = {illumination.max():.6f}')
        print(f'  mean = {illumination.mean():.6f}')
        save_heatmap(
            illumination,
            title='Part (b): illumination when all lamp strengths are 20.0',
            filename='part_b_heatmap.png',
        )

    return None


def part_c(A):
    # Part (c): target illumination is 1.0 in every square.

    # make a target vector
    b = np.full(A.shape[0], TARGET_ILLUMINATION)

    # solve the same LS problem by the two methods.
    x_qr = solve_least_squares_qr(A, b)
    x_svd = solve_least_squares_svd(A, b)

    # determine illumination with solutions from each method
    y_qr = A @ x_qr
    y_svd = A @ x_svd

    if SHOW_PART_C:
        print('Least-squares lamp strengths for target illumination 1.0:')
        print('\n(i) Improved Gram-Schmidt QR solution:')
        print(x_qr)
        print(f'All strengths positive? {bool(np.all(x_qr > 0.0))}')

        print('\n(ii) SVD solution:')
        print(x_svd)
        print(f'All strengths positive? {bool(np.all(x_svd > 0.0))}')

        print('\nDifference between QR and SVD solutions:')
        print(f'  ||x_qr - x_svd||_2 = {np.linalg.norm(x_qr - x_svd):.6e}')

    return x_svd, y_qr, y_svd


def part_d(y_qr, y_svd):
    # Part (d): compare each method's achieved illumination against target 1.0.

    # determine deviation from target for each method
    b = np.full(y_qr.shape[0], TARGET_ILLUMINATION)
    deviation_qr = y_qr - b
    deviation_svd = y_svd - b

    # extract max deviation for each method
    max_dev_qr = np.max(np.abs(deviation_qr))
    max_dev_svd = np.max(np.abs(deviation_svd))

    # find the largest pointwise difference between the two methods
    method_difference = np.max(np.abs(y_qr - y_svd))

    if SHOW_PART_D:
        print('Deviation from the target illumination 1.0:')
        print(f'  QR  max deviation  = {max_dev_qr:.6e}')
        print(f'  SVD max deviation  = {max_dev_svd:.6e}')
        print(f'  max |y_qr - y_svd| = {method_difference:.6e}')
        print('Large difference between methods?', 'No' if method_difference < 1e-10 else 'Investigate further')

        save_deviation_heatmaps(deviation_qr, deviation_svd)
        save_heatmap(
            y_qr,
            title='Part (d): illumination using QR least-squares strengths',
            filename='part_d_qr_illumination.png',
            vmin=TARGET_ILLUMINATION - max_dev_qr,
            vmax=TARGET_ILLUMINATION + max_dev_qr,
            cmap='viridis',
        )
        save_heatmap(
            y_svd,
            title='Part (d): illumination using SVD least-squares strengths',
            filename='part_d_svd_illumination.png',
            vmin=TARGET_ILLUMINATION - max_dev_svd,
            vmax=TARGET_ILLUMINATION + max_dev_svd,
            cmap='viridis',
        )


def part_e(A, x_reference):
    # Part (e): conditioning/sensitivity diagnostics.

    # make a target vector
    b = np.full(A.shape[0], TARGET_ILLUMINATION)

    Ax = A @ x_reference
    residual = b - Ax

    # singular values give the 2-norm condition number.
    svals = np.linalg.svd(A, compute_uv=False)
    kappa_A = svals[0] / svals[-1]

    # theta is angle between b and its projection Ax.
    # clip prevents tiny floating-point overshoots beyond [0,1].
    cos_theta = np.linalg.norm(Ax) / np.linalg.norm(b)
    cos_theta = float(np.clip(cos_theta, 0.0, 1.0))
    sin_theta = np.linalg.norm(residual) / np.linalg.norm(b)
    sin_theta = float(np.clip(sin_theta, 0.0, 1.0))
    theta = np.arctan2(sin_theta, cos_theta)

    # eta describes scaling between A, x, and Ax.
    eta = np.linalg.norm(A, 2) * np.linalg.norm(x_reference) / np.linalg.norm(Ax)

    cond_bound_A = kappa_A + (kappa_A ** 2) * np.tan(theta) / eta

    if SHOW_PART_E:
        print('Conditioning quantities for the least-squares problem:')
        print(f'  kappa(A)   = {kappa_A:.6e}')
        print(f'  cos(theta) = {cos_theta:.6e}')
        print(f'  eta        = {eta:.6e}')
        print(f'  theta      = {theta:.6e} rad')
        print(f'  Upper bound for sensitivity to perturbations in A = {cond_bound_A:.6e}')
        print('Interpretation: if A is perturbed by a small relative amount eps,')
        print('the relative error in x can be expected to be on the order of cond_bound_A * eps.')


def main():
    print('=== Part (a) ===')
    A = part_a()

    print('\n=== Part (b) ===')
    part_b(A)

    print('\n=== Part (c) ===')
    x_svd, y_qr, y_svd = part_c(A)

    print('\n=== Part (d) ===')
    part_d(y_qr, y_svd)

    print('\n=== Part (e) ===')
    part_e(A, x_svd)


if __name__ == '__main__':
    main()
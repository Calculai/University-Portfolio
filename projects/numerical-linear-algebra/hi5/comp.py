import os
import numpy as np


# =============================================================================
# CONFIGURATION: Set to True/False to enable/disable each part
# =============================================================================
SHOW_PART_A = True
SHOW_PART_B = True
SHOW_PART_C = True
SHOW_PART_D = True
SHOW_PART_E = True
SHOW_PART_F = True
SHOW_PART_G = True
# =============================================================================


try:
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except Exception:
    HAVE_MPL = False


def part_a(num_plot_points):
    # linspace of t values to generate the curve
    t = np.linspace(0, 2 * np.pi, num_plot_points, endpoint=False)

    # calculate x
    x = 4 * np.cos(t)
    # calculate y
    y = np.sin(2 * t)

    # stack x and y as rows in a 2xM array
    curve = np.vstack((x, y))

    # print curve info 
    if SHOW_PART_A:
        print(f'Generated curve with {num_plot_points} points.')
        if HAVE_MPL:
            out = os.path.join(os.path.dirname(__file__), 'part_a.png')
            plt.figure()
            plt.plot(curve[0, :], curve[1, :], '-', lw=1)
            plt.axis('equal')
            plt.title('Figure-eight curve')
            plt.savefig(out)
            plt.close()
            print('Saved plot to', out)
        else:
            print('matplotlib not available; skipping plot.')

    return curve, t


def part_b(curve, rng=None):
    # generate rng object if not provided
    if rng is None:
        rng = np.random.default_rng()

    # using .uniform generate angle theta in [pi/7, 6*pi/7]
    theta = rng.uniform(np.pi / 7, 6 * np.pi / 7)

    # make rotation variables
    c, s = np.cos(theta), np.sin(theta)

    # create rotation matrix R and rotate the curve
    R = np.array([[c, -s], [s, c]])

    # rotate the curve
    rotated = R @ curve

    # print rotated curve info
    if SHOW_PART_B:
        print(f'Rotation angle theta = {theta:.4f} rad')
        if HAVE_MPL:
            out = os.path.join(os.path.dirname(__file__), 'part_b.png')
            plt.figure()
            plt.plot(rotated[0, :], rotated[1, :], '.', ms=1)
            plt.axis('equal')
            plt.title('Rotated figure-eight')
            plt.savefig(out)
            plt.close()
            print('Saved plot to', out)

    return rotated, R, theta


def part_c(rotated_curve, n=2000, rng=None):
    # generate rng object if not provided
    if rng is None:
        rng = np.random.default_rng()

    # extract number of columns M from rotated_curve shape
    M = rotated_curve.shape[1]

    # generate sampler
    idx = rng.integers(0, M, size=n)

    #sample n columns from rotated_curve using the sampler
    samples = rotated_curve[:, idx]

    #add Gaussian noise (sigma=0.1)
    noise = rng.normal(0.0, 0.1, samples.shape)
    A = samples + noise

    if SHOW_PART_C:
        print(f'Sampled {n} columns (with noise sigma=0.1).')
        if HAVE_MPL:
            out = os.path.join(os.path.dirname(__file__), 'part_c.png')
            plt.figure(figsize=(6, 6))
            plt.scatter(A[0, :], A[1, :], s=2)
            plt.axis('equal')
            plt.title('Noisy sampled rotated points (A)')
            plt.savefig(out)
            plt.close()
            print('Saved scatter to', out)

    return A, idx


def part_d(A):
    # axis = 1 to compute mean of each row, keepdims=True to maintain 2D shape
    row_means = A.mean(axis=1, keepdims=True)
    # subtract row means from each row to get B
    B = A - row_means

    if SHOW_PART_D:
        print('Subtracted row means; each row now has mean:', B.mean(axis=1))
    return B, row_means


def part_e(B):
    # perform SVD on B
    U, s, Vt = np.linalg.svd(B, full_matrices=False)

    if SHOW_PART_E:
        print('Left singular vectors U:')
        print(U)
        print('\nSingular values:')
        print(s)
        # Check orthogonality
        I_approx = U.T @ U
        diff = np.abs(I_approx - np.eye(I_approx.shape[0]))
        max_err = float(np.max(diff))
        tol = 1e-10
        if max_err < tol:
            print(f'U^T U is within tolerance {tol:.1e} of the identity matrix.')
        else:
            print('\nU^T U (max error {:.3e}):'.format(max_err))
            print(I_approx)
    return U, s, Vt


def part_f(s):
    
    
    return s


def part_g(B, U, curve, idx):
    
    # rotate B by U^T to align principal direction with x-axis
    B_rot = U.T @ B

    # center original curve and sample the same columns to get original samples
    curve_centered = curve - curve.mean(axis=1, keepdims=True)
    orig_samples = curve_centered[:, idx]

    # compute relative error
    rel_err = np.linalg.norm(B_rot - orig_samples) / (np.linalg.norm(orig_samples) + 1e-12)

    if SHOW_PART_G:
        print(f'Relative alignment error after rotating by U^T: {rel_err:.4e}')
        if HAVE_MPL:
            out = os.path.join(os.path.dirname(__file__), 'part_g_before_after.png')
            plt.figure(figsize=(10, 5))
            plt.subplot(1, 2, 1)
            plt.scatter(B[0, :], B[1, :], s=2)
            plt.axis('equal')
            plt.title('Original noisy rotated points (B)')

            plt.subplot(1, 2, 2)
            plt.scatter(B_rot[0, :], B_rot[1, :], s=2)
            plt.axis('equal')
            plt.title('After rotation by U^T (B_rot)')

            plt.savefig(out)
            plt.close()
            print('Saved before/after plot to', out)

    return B_rot, rel_err


def main():
    rng = np.random.default_rng(12345)

    print('=== Part (a) ===')
    curve, t = part_a(2000)

    print('\n=== Part (b) ===')
    rotated_curve, R, theta = part_b(curve, rng=rng)

    print('\n=== Part (c) ===')
    A, idx = part_c(rotated_curve, n=2000, rng=rng)

    print('\n=== Part (d) ===')
    B, row_means = part_d(A)

    print('\n=== Part (e) ===')
    U, s, Vt = part_e(B)

    print('\n=== Part (f) ===')
    part_f(s)

    print('\n=== Part (g) ===')
    B_rot, rel_err = part_g(B, U, curve, idx)


if __name__ == '__main__':
    main()
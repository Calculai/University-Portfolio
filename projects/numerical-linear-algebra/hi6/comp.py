import os
import numpy as np

# CONFIGURATION
SHOW_PART_D = True

try:
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except Exception:
    HAVE_MPL = False


def inner_product(f_vals, g_vals, x):
    return np.trapezoid(f_vals * g_vals, x)
    # using trapezoidal rule via numpy (making my own would be pointless)


def target_function(x):
    return (np.exp(x) - np.exp(-x)) * (np.exp(np.pi - x) - np.exp(x - np.pi))
    # the function implemented


def part_d(num_points=20001):
    # define an x grid
    x = np.linspace(0.0, np.pi, num_points)
    # evaluate the function over the x grid
    f = target_function(x)

    # from part (c): this function is orthogonal to sin(x), sin(2x), sin(3x), sin(4x)
    y = 1.0 - (4.0 / np.pi) * np.sin(x) - (4.0 / (3.0 * np.pi)) * np.sin(3.0 * x)

    # construct a basis of functions to approximate with
    # these are not dynamic function but arrays of the function evaluated over the x grid
    basis_names = [
        'y(x)',
        'sin(x)',
        'sin(2x)',
        'sin(3x)',
        'sin(4x)',
    ]
    basis_values = [
        y,
        np.sin(x),
        np.sin(2.0 * x),
        np.sin(3.0 * x),
        np.sin(4.0 * x),
    ]

    # build the Gram matrix and right-hand side for the best L2 approximation
    n_basis = len(basis_values)
    G = np.zeros((n_basis, n_basis))
    b = np.zeros(n_basis)
    
    for i in range(n_basis):
        # constructing b by taking inner product of f with each basis function
        b[i] = inner_product(f, basis_values[i], x)
        for j in range(n_basis):
            # constructing Gram matrix by taking inner product of each pair of basis functions
            G[i, j] = inner_product(basis_values[i], basis_values[j], x)

    # solving the linear system G * coeffs = b to find the coefficients of the best approximation
    # now we have out projection coefficients
    coeffs = np.linalg.solve(G, b)

    # build the approximation by summing coeffs[i] * basis_values[i] for each basis function
    approximation = np.zeros_like(f)
    for coeff, vals in zip(coeffs, basis_values):
        approximation += coeff * vals

    # compute errors
    rel_err = np.linalg.norm(f - approximation) / np.linalg.norm(f)
    max_err = np.max(np.abs(f - approximation))
    orth_err = np.max(np.abs(G - np.diag(np.diag(G))))

    if SHOW_PART_D:
        print('Computed best L2 approximation in span{y, sin(x), sin(2x), sin(3x), sin(4x)}')
        print('\nBasis coefficients:')
        for name, coeff in zip(basis_names, coeffs):
            print(f'  {name:8s}: {coeff:.10f}')

        print(f'\nMax off-diagonal Gram entry: {orth_err:.3e}')
        print(f'Relative L2 error: {rel_err:.6e}')
        print(f'Max pointwise error on grid: {max_err:.6e}')

        if HAVE_MPL:
            out = os.path.join(os.path.dirname(__file__), 'part_d.png')
            plt.figure(figsize=(12, 5))

            plt.subplot(1, 2, 1)
            plt.plot(x, f, label='f(x)', linewidth=2)
            plt.xlabel('x')
            plt.ylabel('y')
            plt.title('Real function f(x)')
            plt.grid(True, alpha=0.3)
            plt.legend()

            plt.subplot(1, 2, 2)
            plt.plot(x, approximation, '--', label='Best approximation', linewidth=2)
            plt.xlabel('x')
            plt.ylabel('y')
            plt.title('Approximation')
            plt.grid(True, alpha=0.3)
            plt.legend()

            plt.tight_layout()
            plt.savefig(out)
            plt.close()
            print('Saved plot to', out)
        else:
            print('matplotlib not available; skipping plot.')

    return x, f, approximation, coeffs, G


def main():
    print('=== Part (d) ===')
    part_d()


if __name__ == '__main__':
    main()

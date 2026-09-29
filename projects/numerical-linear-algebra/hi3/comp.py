import numpy as np
import matplotlib.pyplot as plt

# =============================================================================
# CONFIGURATION: Set to True/False to enable/disable each part
# =============================================================================
SHOW_PART_A = True   # Plot raw data points
SHOW_PART_B = True   # Quadratic through last three points (row operations)
SHOW_PART_C = True   # Polynomial through all points (minimal degree)
SHOW_PART_D = True   # Set up piecewise-cubic linear system
SHOW_PART_E = True   # Show non-uniqueness of part (d)
SHOW_PART_F = True   # Add derivative condition and solve uniquely
# =============================================================================

def poly_value(coeffs, x):
    x = np.asarray(x, dtype=float) # sanitize input
    y = np.zeros_like(x, dtype=float) # initialize output array
    for power, coefficient in enumerate(coeffs): # loop through coefficients and powers
        y += coefficient * x**power # evaluate each term
    return y 

def solve_by_row_operations(augmented, tol=1e-12):
    matrix = augmented.astype(float).copy()
    row_count, col_count = matrix.shape
    variable_count = col_count - 1
    pivot_row = 0

    for column in range(variable_count):
        best_row = None
        best_abs = 0.0
        for row in range(pivot_row, row_count):
            value = abs(matrix[row, column])
            if value > best_abs:
                best_abs = value
                best_row = row

        if best_row is None or best_abs < tol:
            continue

        if best_row != pivot_row:
            matrix[[pivot_row, best_row]] = matrix[[best_row, pivot_row]]

        pivot = matrix[pivot_row, column]
        matrix[pivot_row] /= pivot

        for row in range(row_count):
            if row == pivot_row:
                continue
            factor = matrix[row, column]
            if abs(factor) > tol:
                matrix[row] -= factor * matrix[pivot_row]

        pivot_row += 1
        if pivot_row == row_count:
            break

    solution = matrix[:, -1]
    return solution, matrix

def smallest_exact_degree(x, y, tol=1e-10):
    for degree in range(len(x) - 1): # check degrees from 0 to n-2 (we know n-1 always works)
        vand = np.vander(x, degree + 1, increasing=True) # vandermonde matrix
        coeffs, *_ = np.linalg.lstsq(vand, y) # solves for coefficients 
        if np.linalg.norm(vand @ coeffs - y, ord=np.inf) < tol: # checks evaluated polynomial vs actual y values
            return degree, vand, coeffs
        
    # default return if no degree from 0 to n-2 works
    vand = np.vander(x, len(x), increasing=True) 
    coeffs, *_ = np.linalg.lstsq(vand, y)  
    return len(x) - 1, vand, coeffs 


def part_a_plot(times, temperatures):
    plt.figure(figsize=(8, 5))
    plt.plot(times, temperatures, 'o-', linewidth=2, label='Measured data')
    plt.xlabel('Time (min)')
    plt.ylabel('Temperature (°C)')
    plt.title('(a) Temperature measurements')
    plt.grid(True, alpha=0.3)
    plt.legend()
    plt.tight_layout()
    plt.savefig('part_a_data.pdf', bbox_inches='tight')
    plt.close()
    print('Saved: part_a_data.pdf')


def part_b_quadratic(times, temperatures):
    x = times[2:]
    y = temperatures[2:]
    matrix = np.column_stack([np.ones_like(x), x, x**2])
    augmented = np.column_stack([matrix, y])
    coeffs, rref = solve_by_row_operations(augmented)

    print('\n(b) Quadratic through last three points')
    print('Linear system [a, b, c]^T for p(x)=a+bx+cx^2:')
    print(augmented)
    print('RREF:')
    print(np.round(rref, 8))
    print(f'Coefficients: a={coeffs[0]:.8f}, b={coeffs[1]:.8f}, c={coeffs[2]:.8f}')

    grid = np.linspace(times.min(), times.max(), 500)
    values = poly_value(coeffs, grid)

    plt.figure(figsize=(8, 5))
    plt.plot(times, temperatures, 'o', label='Data points')
    plt.plot(grid, values, '-', label='Quadratic (part b)')
    plt.xlabel('Time (min)')
    plt.ylabel('Temperature (°C)')
    plt.title('(b) Quadratic fit through last three points')
    plt.grid(True, alpha=0.3)
    plt.legend()
    plt.tight_layout()
    plt.savefig('part_b_quadratic.pdf', bbox_inches='tight')
    plt.close()
    print('Saved: part_b_quadratic.pdf')

    return coeffs


def part_c_global_polynomial(times, temperatures):
    degree, _, coeffs = smallest_exact_degree(times, temperatures)

    print('\n(c) Polynomial through all 5 points')
    print(f'Smallest exact degree: {degree}')

    x = np.linspace(times.min(), times.max(), 600)
    values = poly_value(coeffs, x)

    plt.figure(figsize=(8, 5))
    plt.plot(times, temperatures, 'o', label='Data points')
    plt.plot(x, values, '-', label=f'Global polynomial degree {degree}')
    plt.xlabel('Time (min)')
    plt.ylabel('Temperature (°C)')
    plt.title('(c) Global interpolation polynomial')
    plt.grid(True, alpha=0.3)
    plt.legend()
    plt.tight_layout()
    plt.savefig('part_c_global_poly.pdf', bbox_inches='tight')
    plt.close()
    print('Saved: part_c_global_poly.pdf')

    return coeffs, degree


def part_d(times, temperatures):
    
    # making main system of equations
    V1 = np.vander(times[:3], 4, increasing=True) # Vandermonde for p1
    V2 = np.vander(times[2:], 4, increasing=True) # Vandermonde for p2
    system_matrix = np.zeros((7, 8), dtype=float)
    system_matrix[:3, :4] = V1
    system_matrix[3:6, 4:] = V2

    x0 = times[2]

    # our last equation for the derivatives is inserted
    # p_1'
    system_matrix[6,1] = 1
    system_matrix[6,2] = 2 * x0
    system_matrix[6,3] = 3 * x0**2
    # p_2'
    system_matrix[6,5] = -1
    system_matrix[6,6] = -2 * x0
    system_matrix[6,7] = -3 * x0**2

    rhs = np.array([
        temperatures[0], 
        temperatures[1], 
        temperatures[2], 
        temperatures[2], 
        temperatures[3], 
        temperatures[4], 
        0])

    coeffs, *_ = np.linalg.lstsq(system_matrix, rhs, rcond=None)

    # I split the coeff and plot the two polynomials
    p1 = coeffs[:4]
    p2 = coeffs[4:]

    x1 = np.linspace(times[0], times[2], 400)
    x2 = np.linspace(times[2], times[-1], 300)
    values1 = poly_value(p1, x1)
    values2 = poly_value(p2, x2)

    plt.figure(figsize=(8, 5))
    plt.plot(times, temperatures, 'o', label='Data points')
    plt.plot(x1, values1, '-', label='p1 on [2,9]')
    plt.plot(x2, values2, '-', label='p2 on [9,12]')
    plt.xlabel('Time (min)')
    plt.ylabel('Temperature (°C)')
    plt.title('(d) Two part piecewise cubic')
    plt.grid(True, alpha=0.3)
    plt.legend()
    plt.tight_layout()
    plt.savefig('part_d_two_part_piecewise_cubic.pdf', bbox_inches='tight')
    plt.close()
    print('Saved: part_d_two_part_piecewise_cubic.pdf')

    return system_matrix, rhs


def part_f_unique_piecewise(times, temperatures, system_matrix, rhs):
    # Extra condition: p1'(0)=0  -> a1 = 0

    # we make an extra row with only the new condition and add it to the system making it 8 equations with 8 unknowns
    extra_row = np.array([0, 1, 0, 0, 0, 0, 0, 0], dtype=float)
    full_matrix = np.vstack([system_matrix, extra_row])

    # we add the new conditon to our rhs vector as well completing the augmented matrix for the new system
    full_rhs = np.append(rhs, 0.0)

    # we then sovle the new system
    coeffs = np.linalg.solve(full_matrix, full_rhs)

    # and plot it
    p1 = coeffs[:4]
    p2 = coeffs[4:]

    print('\n(f) Unique piecewise cubic after adding p1\'(0)=0')
    print('p1 coefficients [a0,a1,a2,a3]:', np.round(p1, 8))
    print('p2 coefficients [b0,b1,b2,b3]:', np.round(p2, 8))
    print('Reason for condition: smooth start near t=0 before major heating response.')

    grid1 = np.linspace(times[0], times[2], 400)
    grid2 = np.linspace(times[2], times[-1], 300)
    values1 = poly_value(p1, grid1)
    values2 = poly_value(p2, grid2)

    plt.figure(figsize=(8, 5))
    plt.plot(times, temperatures, 'o', label='Data points')
    plt.plot(grid1, values1, '-', label='p1 on [2,9]')
    plt.plot(grid2, values2, '-', label='p2 on [9,12]')
    plt.xlabel('Time (min)')
    plt.ylabel('Temperature (°C)')
    plt.title('(f) Piecewise cubic with unique solution')
    plt.grid(True, alpha=0.3)
    plt.legend()
    plt.tight_layout()
    plt.savefig('part_f_piecewise_unique.pdf', bbox_inches='tight')
    plt.close()
    print('Saved: part_f_piecewise_unique.pdf')

    return p1, p2



def main():
    times = np.array([2.0, 6.0, 9.0, 11.0, 12.0], dtype=float)
    temperatures = np.array([25.0, 35.0, 45.0, 65.0, 70.0], dtype=float)

    system_matrix = None
    rhs = None

    if SHOW_PART_A:
        part_a_plot(times, temperatures)

    if SHOW_PART_B:
        part_b_quadratic(times, temperatures)

    if SHOW_PART_C:
        part_c_global_polynomial(times, temperatures)

    if SHOW_PART_D or SHOW_PART_E:
        system_matrix, rhs = part_d(times, temperatures)

    if SHOW_PART_F:
        if system_matrix is None or rhs is None:
            system_matrix, rhs = part_d(times, temperatures)
        part_f_unique_piecewise(times, temperatures, system_matrix, rhs)

if __name__ == '__main__':
    main()

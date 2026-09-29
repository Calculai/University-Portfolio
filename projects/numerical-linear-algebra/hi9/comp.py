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
# =============================================================================

try:
    import matplotlib.pyplot as plt
    HAVE_MPL = True
except Exception:
    HAVE_MPL = False


# PARAMETERS  (from Hand-in Assignment 9)
V_A     = 300.0   # liters in tank A (kept constant)
V_B     = 100.0   # liters in tank B (kept constant)

A_FLOW  = 30.0    # a: outside -> A   (l/min)
B_FLOW  = 15.0    # b: B -> A         (l/min)

X_A0    = 84.0    # initial salt in A (g)
X_B0    = 36.0    # initial salt in B (g)

T_END   = 80.0    # simulation end time
N_PTS   = 1200    # number of time points for plotting/solution


def build_flows():
    # part (a): volume balance with the naming convention
    # A: inflow a and b, outflow c  => c = a + b
    # B: inflow c, outflow b and d  => d = c - b
    c_flow = A_FLOW + B_FLOW
    d_flow = c_flow - B_FLOW
    return c_flow, d_flow


def build_system(c_flow, d_flow):
    # part (b): derive system for salt amounts x_A(t), x_B(t)
    # concentration in A = x_A / V_A, concentration in B = x_B / V_B
    #
    # x_A' = b*(x_B/V_B) - c*(x_A/V_A)
    # x_B' = c*(x_A/V_A) - b*(x_B/V_B) - d*(x_B/V_B)
    M = np.array([
        [-c_flow / V_A,              B_FLOW / V_B],
        [ c_flow / V_A,  -(B_FLOW + d_flow) / V_B],
    ], dtype=float)
    return M


def part_a(c_flow, d_flow):
    if SHOW_PART_A:
        print("Part (a): flow rates for constant volumes")
        print(f"  a = {A_FLOW:.1f} l/min")
        print(f"  b = {B_FLOW:.1f} l/min")
        print(f"  c = a + b = {c_flow:.1f} l/min")
        print(f"  d = c - b = {d_flow:.1f} l/min")
    return c_flow, d_flow


def part_b(M):
    if SHOW_PART_B:
        print("Part (b): coefficient matrix for x' = Mx")
        print(M)
        expected = np.array([[-0.15, 0.15], [0.15, -0.45]])
        print("\nExpected matrix from assignment:")
        print(expected)
        print(f"\nDifference norm ||M - expected|| = {np.linalg.norm(M - expected):.2e}")
    return M


def part_c(M):
    # part (c): eigenvalues/eigenvectors
    eigvals, eigvecs = np.linalg.eig(M)
    if SHOW_PART_C:
        print("Part (c): eigen-analysis of M")
        print("Eigenvalues:", eigvals)
        print("Eigenvectors (as columns):")
        print(eigvecs)
    return eigvals, eigvecs


def part_d(eigvals, eigvecs):
    # part (d): solve for coefficients c in V c = x(0)
    x0 = np.array([X_A0, X_B0], dtype=float)
    coeff = np.linalg.solve(eigvecs, x0)

    if SHOW_PART_D:
        v1 = eigvecs[:, 0]
        v2 = eigvecs[:, 1]
        l1, l2 = eigvals[0], eigvals[1]
        c1, c2 = coeff[0], coeff[1]
    
        print(f"\n  x_A(t) = {c1:.1f}*exp({l1:.1f}*t)*{v1[0]:.1f}  +  {c2:.1f}*exp({l2:.1f}*t)*{v2[0]:.1f}")
        print(f"  x_B(t) = {c1:.1f}*exp({l1:.1f}*t)*{v1[1]:.1f}  +  {c2:.1f}*exp({l2:.1f}*t)*{v2[1]:.1f}")

    return coeff


def compute_trajectory(eigvals, eigvecs, coeff):
    # make time array
    t = np.linspace(0.0, T_END, N_PTS)
    # make solution array
    x = np.zeros((len(t), 2), dtype=float)

    # compute x(t) = V diag(exp(eigvals * t)) coeff over time array
    for i, ti in enumerate(t):
        exp_diag = np.diag(np.exp(eigvals * ti))
        x[i] = np.real_if_close(eigvecs @ exp_diag @ coeff)

    return t, x


def part_e(eigvals, eigvecs, coeff):
    t, x = compute_trajectory(eigvals, eigvecs, coeff)
    x_A = x[:, 0]
    x_B = x[:, 1]

    if SHOW_PART_E:
        if HAVE_MPL:
            fig, axes = plt.subplots(1, 2, figsize=(12, 5))

            # plot x_A(t), x_B(t) versus t
            axes[0].plot(t, x_A, label='x_A(t)', linewidth=2)
            axes[0].plot(t, x_B, label='x_B(t)', linewidth=2)
            axes[0].set_xlabel('t (minutes)')
            axes[0].set_ylabel('salt amount (g)')
            axes[0].set_title('x_A(t) and x_B(t)')
            axes[0].grid(True, alpha=0.3)
            axes[0].legend()

            # phase plot x_A versus x_B
            axes[1].plot(x_A, x_B, linewidth=2)
            axes[1].set_xlabel('x_A (g)')
            axes[1].set_ylabel('x_B (g)')
            axes[1].set_title('Phase plot: x_B versus x_A')
            axes[1].grid(True, alpha=0.3)

            plt.tight_layout()

            import os
            out = os.path.join(os.path.dirname(__file__), 'part_e.png')
            plt.savefig(out)
            print(f"Part (e): plots saved to {out}")
            plt.show()
        else:
            print("Part (e): matplotlib not available; skipping plots")


def part_f(eigvals, eigvecs, coeff):
    # part (f): limit of x_B(t)/x_A(t) as t -> infinity
    t, x = compute_trajectory(eigvals, eigvecs, coeff)
    # dominated by eigenvector corresponding to eigenvalue with largest real part
    idx = int(np.argmax(eigvals.real))
    v_dom = np.real_if_close(eigvecs[:, idx]).astype(float)
    ratio_limit = v_dom[1] / v_dom[0]

    if SHOW_PART_F:
        ratios = x[:, 1] / x[:, 0]
        print("Part (f): limit of x_B(t)/x_A(t)")
        print(f"  dominant eigenvalue = {eigvals[idx]:.8f}")
        print(f"  ratio from dominant eigenvector = {ratio_limit:.12f}")
        print(f"  ratio at final time t={T_END} = {ratios[-1]:.12f}")

    return ratio_limit


def main():
    c_flow, d_flow = build_flows()
    M = build_system(c_flow, d_flow)

    print("=== Part (a): Flow balance ===")
    part_a(c_flow, d_flow)

    print("\n=== Part (b): ODE system ===")
    part_b(M)

    print("\n=== Part (c): Eigenvalues and eigenvectors ===")
    eigvals, eigvecs = part_c(M)

    print("\n=== Part (d): Coefficients ===")
    coeff = part_d(eigvals, eigvecs)

    print("\n=== Part (e): Plots ===")
    part_e(eigvals, eigvecs, coeff)

    print("\n=== Part (f): Limit ratio ===")
    part_f(eigvals, eigvecs, coeff)


if __name__ == '__main__':
    main()

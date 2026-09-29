import numpy as np


# =============================================================================
# CONFIGURATION: Set to True/False to enable/disable each part
# =============================================================================
SHOW_PART_A = True
SHOW_PART_B = False  
SHOW_PART_C = True  
SHOW_PART_D = False   
# =============================================================================

def part_a(v0, v1, v2):
    # stack vectors as rows in a matrix
    A = np.array([
        v0,
        v1,
        v2,
    ])
    
    # compute the Gram matrix of (v1, v2, v3)
    G = A @ A.T

    # print the Gram matrix
    if SHOW_PART_A:
        print("Gram matrix G:")
        print(G)

        print("\nChecking orthogonality:")
        print("v0 · v1 =", np.dot(v0, v1))
        print("v0 · v2 =", np.dot(v0, v2))
        print("v1 · v2 =", np.dot(v1, v2))

        if (np.isclose(np.dot(v0, v1), 0) and
            np.isclose(np.dot(v0, v2), 0) and
            np.isclose(np.dot(v1, v2), 0)):
            print("\nThe vectors v0, v1, v2 are orthogonal.")
        else:
            print("\nThe vectors are NOT orthogonal.")

    return G

def part_b(v0, v1, v2, x):
    # projection coefficients
    c0 = np.dot(x, v0) / np.dot(v0, v0)
    c1 = np.dot(x, v1) / np.dot(v1, v1)
    c2 = np.dot(x, v2) / np.dot(v2, v2)

    # projection
    Px = c0*v0 + c1*v1 + c2*v2
    if SHOW_PART_B:
        print("Projection Px =", Px)

    return Px

def part_c(v0, v1, v2, x, Px):
    # compute v3
    v3 = x - Px

    # check orthogonality
    if SHOW_PART_C:
        print("v3 · v0 =", np.dot(v3, v0))
        print("v3 · v1 =", np.dot(v3, v1))
        print("v3 · v2 =", np.dot(v3, v2))

        if (np.isclose(np.dot(v3,v0),0) & 
            np.isclose(np.dot(v3,v1),0) & 
            np.isclose(np.dot(v3,v2),0)):
            print("\nv3 is orthogonal to v0, v1, v2")
        else:
            print("\nv3 is not orthogonal to v0, v1, v2")

    return v3

def part_d(v0, v1, v2, v3):
    u0 = v0 / np.linalg.norm(v0)
    u1 = v1 / np.linalg.norm(v1)
    u2 = v2 / np.linalg.norm(v2)
    u3 = v3 / np.linalg.norm(v3)
    
    U = np.column_stack((u0, u1, u2, u3))
    if SHOW_PART_D:
        print(U)

    return U

def main():
    v0 = np.array([1.0, -1.0, 1.0, -1.0])
    v1 = np.array([1.0, 1.0, -1.0, -1.0])
    v2 = np.array([0.0, 2.0, 2.0, 0.0])
    x = np.array([4.0, 3.0, 2.0, 1])

    print("=== Part (a) ===")
    G = part_a(v0, v1, v2)

    print("\n=== Part (b) ===")
    Px = part_b(v0, v1, v2, x)

    print("\n=== Part (c) ===")
    v3 = part_c(v0, v1, v2, x, Px)

    print("\n=== Part (d) ===")
    U = part_d(v0,v1,v2,v3)



if __name__ == '__main__':
    main()
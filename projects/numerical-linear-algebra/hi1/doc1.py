import numpy as np
import matplotlib.pyplot as plt


def main():
    # (a)
    # chosen based on origin to the points based off the figure
    A = np.array([1, 3])
    B = np.array([2, 3.1])
    C = np.array([2.2, 2.3])
    P = np.array([2.1, 2.0])

    # vectors connected in order A -> B -> C -> D like in the figure
    a = A
    b = B - A
    c = C - B
    d = P - C

    # matrix of vectors
    S = np.array([a, b, c, d])

    offseta = np.array([
    [0.05,  0.05],   # O
    [0.05,  0.05],   # A
    [0.05,  0.03],   # B
    [0.05,  0.05],   # C
    [0.07,  -0.07]    # P
    ])

    plot_matrix(
        S,
        labels=["O", "A", "B", "C", "P"],
        offset=offseta
    )


    # (b)
    # to find the OP vector we simply add the vectors together
    sum = 0
    for i in range(len(S)):
        sum += S[i]

    print("OP vector:", sum)


    # (c)
    # that is the case because when we apply a rotation matrix to d 
    # we take the last part of our arm and turn it. The other vectors
    # are independant of the d vector while if we rotated the first
    # vector we would have to move the origin of the next vector and
    # so on if we wish to keep the points connected

    # 90 degree rotation matrix
    rM = np.array([
        [0, -1],
        [1,  0]
    ])

    # applying the rotation to the d vector
    S_c = S.copy()
    S_c[3] = rM @ S_c[3]

    offsetc = np.array([
    [0.05,  0.05],   # O
    [0.05,  0.05],   # A
    [0.05,  0.03],   # B
    [0.05,  0.05],   # C
    [0.05,  0.05]    # P
    ])

    plot_matrix(
        S_c,
        labels=["O", "A", "B", "C", "P'"],
        offset=offsetc
    )


    # (d)
    offsetd = np.array([
    [0.05,  0.05],   # O
    [0.05,  0.05],   # A
    [0.05,  0.05],   # B
    [0.05,  0.05],   # C
    [-0.05,  -0.05]    # P
    ])

    # applying the rotation to the b vector without modyfing the original S matrix
    S_d0 = S.copy()
    S_d0[1] = rM @ S_d0[1]

    # starting points for each vector
    starts = np.array([
        [0, 0],  
        A,       
        B,       
        C        
    ])
    # formatting for quiver plot
    x0 = starts[:, 0]
    y0 = starts[:, 1]

    # find new joint B
    sum = 0
    for i in range(2):
        sum += S_d0[i]

    # reformatting with rotation applied
    u = S_d0[:, 0]
    v = S_d0[:, 1]

    # plot modified vectors
    plt.quiver(
        x0, y0, u, v,
        angles='xy',
        scale_units='xy',
        scale=1,
        color='black'
    )

    # plot the points and new end point
    plt.scatter([A[0], B[0], C[0], P[0], sum[0]],
                [A[1], B[1], C[1], P[1], sum[1]],
                color='black')

    # added labels for points including new end point
    plt.text(A[0], A[1]+0.1, 'A')
    plt.text(B[0], B[1]+0.1, 'B')
    plt.text(C[0]+0.1, C[1], 'C')
    plt.text(P[0]+0.1, P[1]-0.1, 'P')
    plt.text(sum[0]+0.1, sum[1]-0.1, "B'")

    plt.axis('equal')
    plt.show()


    offsetd = np.array([
    [0.05,  0.05],   # O
    [0.05,  0.05],   # A
    [-0.05,  0.05],   # B
    [0.05,  0.05],   # C
    [0.07,  -0.07]    # P
    ])

    # applying the rotation to the b vector bending around the A point
    S_d = S.copy()
    S_d[1] = rM @ S_d[1]
    S_d[2] = rM @ S_d[2]
    S_d[3] = rM @ S_d[3]

    

    plot_matrix(
        S_d,
        labels=["O", "A", "B'", "C'", "P'"],
        offset=offsetd
    )


    # (e)
    offsete = np.array([
    [0.05,  0.05],   # O
    [0.05,  0.05],   # A
    [-0.05,  0.05],   # B
    [0.07,  -0.07],   # C
    [0.05,  0.05]    # P
    ])

    S_e1 = S.copy()
    # bendA
    S_e1[1] = rM @ S_e1[1]
    S_e1[2] = rM @ S_e1[2]
    S_e1[3] = rM @ S_e1[3]

    # bendC
    S_e1[3] = rM @ S_e1[3]

    plot_matrix(
        S_e1,
        labels=["O", "A", "B'", "C'", "P''"],
        offset=offsete
    )

    S_e2 = S.copy()
    # bendC
    S_e2[3] = rM @ S_e2[3]

    # bendA
    S_e2[1] = rM @ S_e2[1]
    S_e2[2] = rM @ S_e2[2]
    S_e2[3] = rM @ S_e2[3]

    plot_matrix(
        S_e2,
        labels=["O", "A", "B'", "C'", "P''"],
        offset=offsete
    )


# plotting function
def plot_matrix(S, labels, offset):

    # compute cumulative points O -> A -> B -> C -> P
    # makes makes sure the vectors are connected
    points = [np.array([0.0, 0.0])]
    for v in S:
        points.append(points[-1] + v)

    points = np.array(points)

    # starting points for each vector
    starts = points[:-1]

    # formatting for quiver plot
    x0 = starts[:, 0]
    y0 = starts[:, 1]
    u = S[:, 0]
    v = S[:, 1]

    # plot vectors
    plt.quiver(
        x0, y0, u, v,
        angles='xy',
        scale_units='xy',
        scale=1,
        color='black'
    )

    # plot the points
    plt.scatter(points[:, 0], points[:, 1], color='black')

    # offset the points for better visibility of labels
    points[:,0] += offset[:, 0]
    points[:,1] += offset[:, 1]

    # added labels for points
    for p, lab in zip(points, labels):
        plt.text(p[0], p[1], lab)

    plt.axis('equal')
    plt.show()


if __name__ == "__main__":
    main()

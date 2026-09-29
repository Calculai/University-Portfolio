import numpy as np
import matplotlib.pyplot as plt

# =============================================================================
# CONFIGURATION: Set to True/False to enable/disable each part
# =============================================================================
SHOW_PART_A = False  # Plot original signal
SHOW_PART_B = False  # Plot noisy signal
SHOW_PART_C = False  # Show matrix A construction 
SHOW_PART_D = False  # Plot A vs noisy comparison
SHOW_PART_E_Plot = False   # Plot A vs B comparison
SHOW_PART_E_Print = False  # Print quantitative comparison results
# =============================================================================


def main():
    #(a)
    n = 200  
    # using linspace to generate n evenly distributed points between 0 and 12
    x = np.linspace(0, 12, n)

    # generate the y array based on our linspace vector
    y = 12 * np.sin(x) - 4 * np.cos(8 * x)

    if SHOW_PART_A:
        # plot the clean signal
        plt.figure(figsize=(12, 5))
        plt.plot(x, y, label='Original signal y(x)', linewidth=2)
        plt.xlabel('x')
        plt.ylabel('y(x)')
        plt.title('(a) Original Signal: y(x) = 12*sin(x) - 4*cos(8x)')
        plt.legend()
        plt.grid(True)
        plt.savefig('figure1_signal.pdf', bbox_inches='tight')
        plt.close()
        print("Saved: figure1_signal.pdf")

    #(b)
    # do as assignment specifies
    # np.random.default_rng() generate an rng object with methods
    rng = np.random.default_rng()
    # rng.standard_normal uses the rng object to generate an array of n random numbers
    # the numbers are standard normally distributed so 68% is [-1,1], 95% is [-2,2], 99.7% is [-3,3] 
    # so most numbers are the same order of magnitude as the values found in part (a)
    noise = rng.standard_normal(n)

    # since both arrays are length n we can just add them
    y_noisy = y + noise

    if SHOW_PART_B:
        plt.figure(figsize=(12, 5))
        plt.plot(x, y_noisy, label='Noisy y(x)', linewidth=2)
        plt.xlabel('x')
        plt.ylabel('y(x)')
        plt.title('(b) Noisy Signal: y(x) = 12*sin(x) - 4*cos(8x)')
        plt.legend()
        plt.grid(True)
        plt.savefig('figure2_noisy.pdf', bbox_inches='tight')
        plt.close()
        print("Saved: figure2_noisy.pdf")

    # (c)
    # np.diag takes an array and put it on the diagonal assigned with a value
    # 0 is the main diagonal, 1 is above the main diagonal and -1 is below 
    # and so on
    # we need to remember the diagonal gets one shorter as we deviate from
    # the main diagonal so we shorten the vector by 1
    # diagonal determine the size of the matricies so we can just add them

    A = (np.diag(np.ones(n) / 3, 0)
        + np.diag(np.ones(n-1) / 3, 1)
        + np.diag(np.ones(n-1) / 3, -1))


    if SHOW_PART_C:
        print("Matrix A (first 5 rows):\n", A[:5, :5])

    # (d)
    # assignment asks us to plot the matrix multiplied by the noisy signal
    y_smoothed_A = A @ y_noisy

    if SHOW_PART_D:
        # Use subplots to clearly show before and after
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))
        
        # Left plot: Original vs Noisy (shows the problem)
        ax1.plot(x, y, label='Original signal', linewidth=2, alpha = 0.4, color='teal')
        ax1.plot(x, y_noisy, label='Noisy signal', linewidth=1, alpha=1, color='salmon')
        ax1.set_xlabel('x')
        ax1.set_ylabel('y')
        ax1.set_title('Before: Noisy Signal')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Right plot: Original vs Smoothed (shows the solution)
        ax2.plot(x, y, label='Original signal', linewidth=2, alpha = 0.4, color='teal')
        ax2.plot(x, y_smoothed_A, label='Smoothed with A', linewidth=1, color='salmon')
        ax2.set_xlabel('x')
        ax2.set_ylabel('y')
        ax2.set_title('After: Noise Reduction with Matrix A')
        ax2.legend()
        ax2.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.savefig('figure3_A.pdf', bbox_inches='tight')
        plt.close()
        print("Saved: figure3_A.pdf")

    # (e)
    B = (np.diag(np.ones(n) * 6/16, 0) +        # main diagonal: current point 
         np.diag(np.ones(n-1) * 4/16, 1) +       # superdiagonal 1: right neighbor 
         np.diag(np.ones(n-1) * 4/16, -1) +      # subdiagonal 1: left neighbor 
         np.diag(np.ones(n-2) * 1/16, 2) +       # superdiagonal 2: 2nd right neighbor 
         np.diag(np.ones(n-2) * 1/16, -2))      # subdiagonal 2: 2nd left neighbor 
    
    y_smoothed_B = B @ y_noisy

    if SHOW_PART_E_Plot:
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))

        # left plot: Original vs Smoothed (shows the solution)
        ax1.plot(x, y, label='Original signal', linewidth=2, alpha = 0.4, color='teal')
        ax1.plot(x, y_smoothed_A, label='Smoothed with A', linewidth=1, color='salmon')
        ax1.set_xlabel('x')
        ax1.set_ylabel('y')
        ax1.set_title('After: Noise Reduction with Matrix A')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Right plot: Original vs Smoothed (shows the solution)
        ax2.plot(x, y, label='Original signal', linewidth=2, alpha = 0.4, color='teal')
        ax2.plot(x, y_smoothed_B, label='Smoothed with B', linewidth=1, color='salmon')
        ax2.set_xlabel('x')
        ax2.set_ylabel('y')
        ax2.set_title('After: Noise Reduction with Matrix B')
        ax2.legend()
        ax2.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.savefig('figure4_B.pdf', bbox_inches='tight')
        plt.close()
        print("Saved: figure4_B.pdf")
    if SHOW_PART_E_Print:
        # Quantify which noise reduction is better
        compare_noise_reduction(y, y_noisy, y_smoothed_A, y_smoothed_B)
    
    # winner counters
    A_wins = 0
    B_wins = 0
    Tie = 0

    for _ in range(1000):
        # generate new rng object
        rng = np.random.default_rng()
        # generate new random number arrays
        noise = rng.standard_normal(n)
        # regenerate datasets
        y_noisy = y + noise
        y_smoothed_A = A @ y_noisy
        y_smoothed_B = B @ y_noisy
        # compare them
        AB_equal, A_better, B_better = compare_noise_reduciton_noprint(y, y_noisy, y_smoothed_A, y_smoothed_B)

        # tally winner
        if AB_equal:
            Tie += 1
        elif A_better:
            A_wins += 1
        elif B_better:
            B_wins += 1

    # print results
    print(f"A wins: {A_wins}")
    print(f"B wins: {B_wins}")
    print(f"Ties: {Tie}")


def compare_noise_reduction(y_original, y_noisy, y_smoothed_A, y_smoothed_B):
    """
    Quantify and compare how close the smoothed signals are to the original.
    
    - y_original: the true clean signal
    - y_noisy: the corrupted signal with noise
    - y_smoothed_A: signal smoothed with matrix A
    - y_smoothed_B: signal smoothed with matrix B
    """
    # using L2 norm to quantify error between original, noisy and smoothed signals
    error_noisy = np.linalg.norm(y_noisy - y_original)
    error_A = np.linalg.norm(y_smoothed_A - y_original)
    error_B = np.linalg.norm(y_smoothed_B - y_original)
    
    print("\n" + "="*60)
    print("QUANTITATIVE COMPARISON OF NOISE REDUCTION")
    print("="*60)
    print(f"L2 Norm Error:")
    print(f"  Noisy signal:           {error_noisy:.4f}")
    print(f"  Matrix A smoothing:     {error_A:.4f}")
    print(f"  Matrix B smoothing:     {error_B:.4f}")
    print()
    
    # calculate improvement of each matrix compared to noisy signal
    improvement_A = ((error_noisy - error_A) / error_noisy) * 100
    improvement_B = ((error_noisy - error_B) / error_noisy) * 100
    improvement_B_over_A = ((error_A - error_B) / error_A) * 100
    
    print(f"Percentage Improvements:")
    print(f"  A reduces error by:     {improvement_A:.2f}%")
    print(f"  B reduces error by:     {improvement_B:.2f}%")
    print(f"  B improves over A by:   {improvement_B_over_A:.2f}%")
    print()
    
    # determine which is better
    if error_B < error_A:
        print(f"Matrix B is BETTER (error B: {error_B:.4f} < error A: {error_A:.4f})")
    elif error_A < error_B:
        print(f"Matrix A is BETTER (error A: {error_A:.4f} < error B: {error_B:.4f})")
    else:
        print(f"  Both matrices perform equally")
    print("="*60 + "\n")

def compare_noise_reduciton_noprint(y_original, y_noisy, y_smoothed_A, y_smoothed_B):
    """
    Quantify and compare how close the smoothed signals are to the original.
    
    - y_original: the true clean signal
    - y_noisy: the corrupted signal with noise
    - y_smoothed_A: signal smoothed with matrix A
    - y_smoothed_B: signal smoothed with matrix B
    """
    # using L2 norm to quantify error between original and smoothed signals
    error_A = np.linalg.norm(y_smoothed_A - y_original)
    error_B = np.linalg.norm(y_smoothed_B - y_original)

    A_better = False
    B_better = False
    AB_equal = False

    # determine which is better
    if error_B < error_A:
        B_better = True
    elif error_A < error_B:
        A_better = True
    else:
        AB_equal = True

    return AB_equal, A_better, B_better

if __name__ == "__main__":
    main()

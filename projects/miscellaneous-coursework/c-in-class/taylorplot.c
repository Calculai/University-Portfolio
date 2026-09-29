#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "taylor_sine.h"

// 🔹 Main plotting function
int main(void) {
    FILE *fp = fopen("sine_data.txt", "w");
    if (!fp) {
        perror("Error creating file");
        return 1;
    }

    // Write header for clarity (optional)
    // Columns: x sin(x) taylor1 taylor2 taylor3 taylor4 taylor5
    fprintf(fp, "# x sin(x) T1 T2 T3 T4 T5\n");

    // Generate data points for x ∈ [-2π, 2π]
    int terms[] = {1, 2, 3, 7, 12}; // Number of Taylor terms
    int n_terms = sizeof(terms)/sizeof(terms[0]);
    double threshold = 3.0;

    for (double x = -15; x <= 15; x += 0.01) {
        double real_sin = sin(x);
        double t1 = taylor_sine(x, 1);
        double t2 = taylor_sine(x, 2);
        double t3 = taylor_sine(x, 3);
        double t4 = taylor_sine(x, 7);
        double t5 = taylor_sine(x, 12);

    // Replace values that exceed threshold with NaN
    if (fabs(t1) > threshold) t1 = NAN;
    if (fabs(t2) > threshold) t2 = NAN;
    if (fabs(t3) > threshold) t3 = NAN;
    if (fabs(t4) > threshold) t4 = NAN;
    if (fabs(t5) > threshold) t5 = NAN;

    fprintf(fp, "%lf %lf %lf %lf %lf %lf %lf\n", x, real_sin, t1, t2, t3, t4, t5);
}
    fclose(fp);

    printf("Data written to sine_data.txt\n");

    // 🔸 Build dynamic Gnuplot command
    char gnuplot_cmd[1024] = "gnuplot -persist -e \"set title 'Taylor Series Approximations of y=sin(x)'; set xlabel 'x'; set ylabel 'y'; set key outside; plot 'sine_data.txt' using 1:2 with lines lw 2 title 'sin(x)'";
    for (int i = 0; i < n_terms; i++) {
        char buf[128];
        snprintf(buf, sizeof(buf), ", 'sine_data.txt' using 1:%d with lines lw 2 title '%d terms'", i+3, terms[i]);
        strncat(gnuplot_cmd, buf, sizeof(gnuplot_cmd) - strlen(gnuplot_cmd) - 1);
    }
    strncat(gnuplot_cmd, "\"", sizeof(gnuplot_cmd) - strlen(gnuplot_cmd) - 1);

    system(gnuplot_cmd);

    return 0;
}
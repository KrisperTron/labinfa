#include <stdio.h>
#include <math.h>

// рекуртивное
double sum_recurrent(double x, int N) {
    if (N <= 0) return 0.0;

    double a = 1.5 * x * x;  // a1 = 3/2 * x^2
    double S = a;

    for (int n = 1; n < N; n++) {
        double factor = (2.0 * n + 3.0) * x * x /
                        (2.0 * (n + 1.0) * (2.0 * n + 1.0));
        a *= factor;
        S += a;
    }
    return S;
}

// по формуле
double sum_direct(double x, int N) {
    double S = 0.0;
    for (int n = 1; n <= N; n++) {
        double term = (2.0 * n + 1.0);
        term *= pow(x, 2*n) / (pow(2.0, n) * tgamma(n+1));
        S += term;
    }
    return S;
}


int main() {
    double x;
    int N;

    printf("Input x (|x| < 1): ");
    scanf("%lf ", &x);
    printf("Input N: ");
    scanf("%d ", &N);

    double s_rec = sum_recurrent(x, N);
    double s_dir = sum_direct(x, N);

    printf("\n--- Results ---\n");
    printf("Recurrent sum:    %.10f\n", s_rec);
    printf("Direct calculation:     %.10f\n", s_dir);

    return 0;
}

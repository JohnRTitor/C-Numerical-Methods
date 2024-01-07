#include <stdio.h>
#include <math.h>

#define epsilon 1e-6
#define max_iteration 100

double function(double x) {
    // Define the function for which you want to find the root
    return x*log10(x) - 1.2;
}

double derivative(double x) {
    // Define the derivative of the function
    return log10(x) + 0.43429;
}

double newton_raphson(double initialGuess) {
    double x0 = initialGuess;

    for (int i = 0; i < max_iteration; ++i) {
        double fx = function(x0);
        double dfx = derivative(x0);

        // Check for division by zero
        if (fabs(dfx) < epsilon) {
            printf("Error: Division by zero.\n");
            return NAN; // Not a Number
        }

        double x1 = x0 - fx / dfx;

        // Check for convergence
        if (fabs(x1 - x0) < epsilon) {
            return x1;
        }

        x0 = x1;
    }

    printf("Warning: Maximum number of iterations reached.\n");
    return NAN;
}

int main() {
    double initial_guess, root;

    printf("Enter the initial guess: ");
    scanf("%lf", &initial_guess);

    root = newton_raphson(initial_guess);

    if (!isnan(root)) {
        printf("Root found at: %lf\n", root);
    }

    return 0;
}

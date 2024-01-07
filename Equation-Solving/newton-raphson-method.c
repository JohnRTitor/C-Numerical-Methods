#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6
#define MAX_ITERATIONS 100

double function(double x) {
    // Define the function for which you want to find the root
    return x * x - 16;
}

double derivative(double x) {
    // Define the derivative of the function
    return 2 * x;
}

double newtonRaphson(double initialGuess) {
    double x0 = initialGuess;

    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        double fx = function(x0);
        double dfx = derivative(x0);

        // Check for small derivative value
        if (fabs(dfx) < EPSILON) {
            printf("Warning: Small derivative value encountered. Try a different initial guess.\n");
            return NAN; // Not a Number
        }

        double x1 = x0 - fx / dfx;

        // Check for convergence
        if (fabs(x1 - x0) < EPSILON) {
            return x1;
        }

        x0 = x1;
    }

    printf("Warning: Maximum number of iterations reached. The method may not have converged.\n");
    return NAN;
}

int main() {
    double initialGuess, root;

    printf("Enter the initial guess: ");
    scanf("%lf", &initialGuess);

    // Check if the initial guess is zero
    if (initialGuess == 0) {
        printf("Warning: The Newton-Raphson method may not converge with an initial guess of zero.\n");
        return 1;
    }

    root = newtonRaphson(initialGuess);

    if (!isnan(root)) {
        printf("Root found at: %lf\n", root);
    }

    return 0;
}

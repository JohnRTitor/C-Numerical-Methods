#include <stdio.h>
#include <math.h>

int sign (double x)
{
    if (x > 0)
        return 1;
    else if (x < 0)
        return -1;
    else
        return 0;
}
// Function for which we are finding the root
double function(double x)
{
    return x * x - 4; // Change this function as needed
}

// Find initial interval [a, b] with sign change
void findInitialInterval(double *a, double *b, double step)
{
    double x = *a;

    while (function(x) * function(x + step) >= 0)
    {
        x += step;
    }

    *a = x;
    *b = x + step;
}

// Bisection method implementation
double bisection(double a, double b, double tol)
{
    double c;

    while ((b - a) >= tol)
    {
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (function(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main() {
    double a, b, tol, step;

    // Set initial values for step and tolerance
    step = 0.1;
    tol = 0.00001;

    // Find initial interval [a, b] with sign change
    findInitialInterval(&a, &b, step);

    // Call the bisection method and print the result
    printf("Root: %lf\n", bisection(a, b, tol));

    return 0;
}

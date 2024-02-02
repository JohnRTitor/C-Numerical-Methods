#include <stdio.h>
#include <math.h>

#define MAX_SIZE 50

#define dY_dX F
#define F(x, y) (x + y)

int main ()
{
    double d1, d2, d3, d4;
    double x[MAX_SIZE], y[MAX_SIZE], h, a;
    int i;

    printf("Enter x[0], y[0]:");
    scanf("%lf %lf", &x[0], &y[0]);
    printf("Enter h (step length):");
    scanf("%lf", &h);
    printf("Enter a (the value to calculate):");
    scanf("%lf", &a);

    while (x[i] < a)
    {
        d1 = h * f(x[i], y[i]);
        d2 = h * f(x[i] + h/2, y[i] + d1/2);
        d3 = h * f(x[i] + h/2, y[i] + d2/2);
        d4 = h * f(x[i] + h, y[i] + d3);
        y[i + 1] = y[i] + (d1 + 2*d2 + 2*d3 + d4)/6;
        x[i + 1] = x[i] + h;
        i++;
    }

    printf("The value of y at x = %lf is %lf\n", a, y[i]);

    return 0;
}
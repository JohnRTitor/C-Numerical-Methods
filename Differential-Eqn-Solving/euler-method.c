#include <stdio.h>
#include <math.h>

#define MAX_SIZE 50

#define dY_dX F
#define F(x, y) (x + y)

int main ()
{
    double x[MAX_SIZE], y[MAX_SIZE], h, a;
    int i;

    printf("Enter x[0], y[0]: ");
    scanf("%lf %lf", &x[0], &y[0]);
    printf("Enter h (step length): ");
    scanf("%lf", &h);
    printf("Enter a (the value to calculate): ");
    scanf("%lf", &a);

    i = 0;
    while (x[i] < a)
    {
        y[i + 1] = y[i] + h * F(x[i], y[i]);
        x[i + 1] = x[i] + h;
        i++;
    }

    printf("The value of y at x = %.2lf is %.4lf\n", a, y[i]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x)
// we want to integrate F(x)

int main ()
{
    int i, n;
    double a, b, result, h, x[100], y[100];

    printf("Enter lower bound of integration: ");
    scanf("%lf", &a);
    printf("Enter upper bound of integration: ");
    scanf("%lf", &b);
    printf("Enter number of subintervals: ");
    scanf("%d", &n);
    if (n % 2 != 0 || n < 1)
    {
        printf("Number of subintervals must be non-negative even. ");
        exit(0);
    }

    h = (b - a) / n;
    
    for (i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = F(x[i]);
        // first and last terms are added as it is
        if (i == 0 || i == n)
            result += y[i];
        // odd terms are clubbed and multiplied by 4
        else if (i % 2 != 1)
            result += 4 * y[i];
        // even terms are clubbed and multiplied by 2
        else
            result += 2 * y[i];
    }

    result *= h / 3;

    printf("The integral evaluated is: %lf\n", result);
}
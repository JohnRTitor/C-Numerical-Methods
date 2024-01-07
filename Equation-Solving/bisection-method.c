#include <stdio.h>
#include <math.h>

#define MAX_ITERATION 100

double FUNC (double x)
{
    return x*x*x - 9*x + 1;
}

double bisectionMethod (double a, double b);
void swap (double *p_x, double *p_y);

int main ()
{
    double a, b, root;
    printf("Enter the initial interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    
    root = bisectionMethod(a, b);
    if (!isnan(root))
        printf("Root found at: %.4lf\n", root);
    else
        printf("Root not found in the [%.2lf, %.2lf] interval\n", a, b);

}

double bisectionMethod (double a, double b)
{
    double c;

    // Check if the interval is valid
    if (FUNC(a) * FUNC(b) > 0)
    {
        printf("Invalid interval, no sign change of F(x) between interval bounds\n");
        return NAN;
    }
    // Check if the interval bounds are the root
    else if (FUNC(a) == 0)
        return a;
    else if (FUNC(b) == 0)
        return b;

    // Check and swap intervals if necessary
    if (FUNC(a) > FUNC(b))
        swap(&a, &b);
    
    for (int i = 0; i < MAX_ITERATION; i++)
    {
        c = (a + b) / 2;
        // Check if the root is found, or if the interval is small enough
        if (FUNC(c) == 0 || fabs(a - b) < 1e-6)
            return c;
        // there lies a root in the [a, c] interval
        else if (FUNC(a) * FUNC(c) < 0)
            b = c;
        // there lies a root in the [c, b] interval
        else
            a = c;
    }
    return NAN;
}

void swap (double *p_x, double *p_y)
{
    double temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
}
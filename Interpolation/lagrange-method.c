#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10

int main ()
{
    double x[MAX_SIZE], y[MAX_SIZE], S[MAX_SIZE];
    int i, j, n;
    double a, fA;

    printf("Enter the values of x[i] and y[i]: (type -999 -999 to stop) \n");
    i = 0;
    while (true)
    {
        printf("%d: ", i);
        scanf("%lf %lf", &x[i], &y[i]);
        if (x[i] == -999 && y[i] == -999)
        {
            n = i;
            break;
        }
        i++;
    }

    printf("Enter the value of a: ");
    scanf("%lf", &a);


    for (i = 0; i <= n; i++)
    {
        S[i] = 1;
        for (j = 0; j <= n; j++)
        {
            if (i != j)
            {
                S[i] *= (a - x[j]) / (x[i] - x[j]);
            }
        }
    }

    fA = 0;
    for (i = 0; i <= n; i++)
    {
        fA += y[i] * S[i];
    }

    printf("f(%.3lf) = %lf\n", a, fA);

    return 0;
}
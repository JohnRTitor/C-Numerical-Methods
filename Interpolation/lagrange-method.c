#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10

int main ()
{
    int x[MAX_SIZE], y[MAX_SIZE], S[MAX_SIZE];
    int i, j;
    int a, n;
    double fA;

    printf("Enter the values of x[i] and y[i]: (type -999 -999 to stop)");
    i = 0;
    while (true)
    {
        printf("%d: ", i);
        scanf("%d %d", &x[i], &y[i]);
        if (x[i] == -999 && y[i] == -999)
        {
            n = i;
            break;
        }
    }

    printf("Enter the value of a: ");
    scanf("%d", &a);


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

    printf("f(%d) = %lf\n", a, fA);

    return 0;
}
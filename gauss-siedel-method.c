#include <stdio.h>
#define N_EQ 3

int main (void)
{
    int coef[N_EQ][N_EQ + 1], i, j;

    printf("*** Gauss Seidel Method ***\n");
    printf("The general format is ax + by + cz = d\n");
    for (i = 0; i < N_EQ; i++)
    {
        printf("Equation %d\n", i+1);
        printf("Enter the values of a, b, c, d (space-seperated): ");
        scanf("%lf %lf %lf %lf", &coef[0], &coef[1], &coef[2], &coef[3]);
    }
    printf("The equations are:\n");
    for (i = 0; i < N_EQ; i++)
    {
        for (j = 0; j < N_EQ + 1; j++)
        {
            printf("%lf ", coef[i][j]);
        }
        printf("\n");
    }
    return 0;
}
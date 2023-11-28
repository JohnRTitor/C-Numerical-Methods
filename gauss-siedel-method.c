#include <stdio.h>
#define N_EQ 3

int main (void)
{
    double eqn[N_EQ][N_EQ + 1];
    int i = 0, j = 0;

    printf("*** Gauss Seidel Method ***\n");
    printf("The general format is ax + by + cz = d\n");
    for (i = 0; i < N_EQ; i++)
    {
        printf("Equation %d\n", i+1);
        readEquation(eqn[i]);

    }
    printf("The equations are:\n");
    for (i = 0; i < N_EQ; i++)
    {
        printEquation(eqn[i]);
    }
    return 0;
}

void readEquation (int coeff[N_EQ + 1])
{
    printf("Enter the values of a, b, c, d (space-seperated): ");
    scanf("%lf %lf %lf %lf", &coeff[0], &coeff[1], &coeff[2], &coeff[3]);
}

void printEquation (int coeff[N_EQ + 1])
{
    // print the equation with the given coefficients, in the format ax + by + cz = d
    printf("(%.2lf)x + (%.2lf)y + (%.2lf)z = (%.2lf)\n", coeff[0], coeff[1], coeff[2], coeff[3]);
}
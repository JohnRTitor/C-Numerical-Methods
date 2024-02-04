#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20

int main()
{
    int n, i, x[MAX_SIZE], y[MAX_SIZE];
    int sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
    double a, b;
    
    printf("How many data points do you have? ");
    scanf("%d", &n);
    printf("\n Enter the values of x, y: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
    }
    a = ((sumx2 * sumy - sumx * sumxy) * 1.0 / (n * sumx2 - sumx * sumx) * 1.0);
    b = ((n * sumxy - sumx * sumy) * 1.0 / (n * sumx2 - sumx * sumx) * 1.0);
    
    printf("\nThe line is Y=%3.3f +%3.3f X", a, b);
    return 0;
}
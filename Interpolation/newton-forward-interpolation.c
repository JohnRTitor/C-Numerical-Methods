#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long long factorial(int n);

#define MAX_SIZE 25

int main ()
{
    double x[MAX_SIZE], y[MAX_SIZE], table[MAX_SIZE][MAX_SIZE];
    int n[MAX_SIZE];
    int i, order;
    double a, v, answer;

    printf("*** Newton Forward Interpolation ***\n");
    printf("Enter the values of x[i] and y[i]: (type -999 -999 to stop) \n");
    i = 0;
    while (true)
    {
        printf("%d: ", i);
        scanf("%lf %lf", &x[i], &y[i]);
        if (x[i] == -999 && y[i] == -999)
        {
            n[0] = i; // no of y terms
            break;
        }
        i++;
    }

    printf("Enter the value to interpolate: ");
    scanf("%lf", &a);

    // first copy values of y to table[0]
    order = 0; // current order is zero since we are copying y
    for (i = 0; i < n[0]; i++)
    {
        table[0][i] = y[i];
    }
    // then calculate the table
    order = 1; // start from the first order
    while (true)
    {
        n[order] = 0; // initial no of terms
        for (i = 0; i < n[order - 1] - 1; i++)
        {
            table[order][i] = table[order - 1][i + 1] - table[order - 1][i];
            n[order]++; // increase the no of terms in the current order
        }
        // after calculating the table, check if all the terms are same
        // or if there is only one term left
        if (n[order] == 1)
        {
            break;
        }
        // increase the order and calculate the next column
        order++;
    }

    // now we have the table, we can calculate the value of f(a)
    answer = 0;
    // calculate v = a - x[0] / h
    // where h = x[1] - x[0]
    v = (a - x[0]) / (x[1] - x[0]);
    answer = table[0][0];
    for (i = 1; i <= order; i++)
    {
        double temp_answer = 1;
        for (int j = 0; j < i; j++)
        {
            temp_answer *= (v - j);
        }
        answer += (temp_answer / factorial(i)) * table[i][0];
    }

    printf("The value of f(%.2lf) is %.4lf\n", a, answer);
    return 0;
}

long long factorial (int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
#include <stdio.h>

// Function to calculate the backward difference table
void calculate_backward_difference_table(float y[], int n, float b[][n]) {
    int i, j;

    // Copy the y array to the first column of the table
    for (i = 0; i < n; i++) {
        b[i][0] = y[i];
    }

    // Calculate the backward difference table
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            b[i][j] = b[i][j - 1] - b[i - 1][j - 1];
        }
    }
}

// Function to calculate the interpolation using Newton's backward formula
float interpolate_backward(float x, float x0, float h, int n, float b[][n]) {
    float result = b[n - 1][0];
    float term = (x - x0) / h;

    for (int i = 1; i < n; i++) {
        result += (term * b[n - 1][i]) / i;
        term *= (term + 1 - i) / i;
    }

    return result;
}

int main() {
    int n;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    // Input the data points
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d y%d: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Input the value to interpolate
    float xValue;
    printf("Enter the value to interpolate: ");
    scanf("%f", &xValue);

    // Calculate backward difference table
    float b[n][n];
    calculate_backward_difference_table(y, n, b);

    // Calculate interpolated value using Newton's backward formula
    float result = interpolate_backward(xValue, x[0], x[1] - x[0], n, b);

    // Display the result
    printf("Interpolated value at x = %.2f is %.6f\n", xValue, result);

    return 0;
}

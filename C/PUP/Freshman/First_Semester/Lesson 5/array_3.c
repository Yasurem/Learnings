#include <stdio.h>
#include <math.h>

void array_multiply(int X[], int Y[], int Z[], int N);
void array_sum_sqroot(int N, int Z[]);

int main ()
{
    int N = 20, i;
    int X[20], Y[20], Z[20];

    // Ask the user the quantity of values
    do
    {
        printf("Set Value Quantity (Up to 20): ");
        scanf("%d", &N);
    } 
    while (N < 0 || N > 20);
    
    // Ask user to input 20 X Values
    for (i = 0; i < N; i++)
    {
        printf("Input X Value #%d: ", i + 1);
        scanf("%d", &X[i]);
    }

     printf("\n");

    // Ask user to input 20 Y Values
    for (i = 0; i < N; i++)
    {
        printf("Input Y Value #%d: ", i + 1);
        scanf("%d", &Y[i]);
    }

    array_multiply(X, Y, Z, N);

    printf("The Products are:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d * %d = %d\n",  X[i], Y[i], Z[i]);
    }
    
    array_sum_sqroot(N, Z);
}

void array_multiply(int X[], int Y[], int Z[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        Z[i] = Y[i] * X[i];
    }
}

void array_sum_sqroot(int N, int Z[])
{
    int i, sum = 0;
    float result;

    for (i = 0; i < N; i++)
    {
        sum = sum + Z[i];
    }

    result = sqrt(sum);
    printf("Square root: %.2f\n", result);
}
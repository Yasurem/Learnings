#include <stdio.h>

int REVERSE(int X[], int Y[], int N);

int main ()
{
    int N;
    printf("Set Value Quantity: ");
    scanf("%d", &N);

    int X[N], Y[N], i;

    for (i = 0; i < N; i++)
    {
        printf("Value %d: ", i + 1);
        scanf("%d", &X[i]);
    }

    REVERSE(X, Y, N);

    for (i = 0; i < N; i++)
    {
        printf("%d ", Y[i]);
    }
}

int REVERSE(int X[],  int Y[], int N)
{
    int i, j;
    for (i = N - 1, j = 0; i >= 0; i--, j++)
    {
        Y[j] = X[i];
    } 
}
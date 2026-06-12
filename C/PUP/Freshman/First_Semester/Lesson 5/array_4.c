#include <stdio.h>

void add_pairs(int initial[], int final[], int n);
int main ()
{
    const int n = 10;
    int initial[n], final[n - 1];
    int i;

    printf("Enter eleven numbers: ");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &initial[i]);
    }

    add_pairs(initial, final, n);

    printf("SUM of TWO succeeding pairs: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", final[i]);
    }
}

void add_pairs(int initial[], int final[], int n)
{
    int i;
    final[0] = 0; 
    for (i = 0; i < n + 1; i++)
    {
        final[i] = initial[i] + initial[i + 1];
    }
}
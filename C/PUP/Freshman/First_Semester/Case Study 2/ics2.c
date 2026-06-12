#include <stdio.h>

int main(void)
{
    int m, n, i;
    m = 1;
    printf("Input Number: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) // Counter from 1 to N
    {
        m = m * i;
    }
    printf("%d",m);
}   
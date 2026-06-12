#include <stdio.h>

int main (void)
{
    int n, i, m;
    m = 1;
    printf("Input: ");
    scanf("%d", &n);

    for (i = n; i > 0; i--)
    {
        m = m * i;
    }
    printf("%d", m);
}
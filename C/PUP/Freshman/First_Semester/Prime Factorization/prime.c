#include <stdio.h>

int main (void)
{
// Initialization
    int n, i, yn;

// Do loop
    do
    {

// Input Scanner
        printf("Input number: ");
        scanf("%d", &n);

// For Loop: 
        for (i = 2; i <= n; i++)
        {

// Keep dividing until the input is not divisible by i (2)
            while ((n % i) == 0)
            {

        // Divide the input by i (2) then update the input
                n = n / i;

        // Print i until the input is divisible by i (2)
                printf("%d ", i);

            }
        }

// Process terminator
        printf("\nContinue? 1 - Yes | 0 - No\n");
        scanf("%d", &yn);
    } 
    while (yn != 0);
}
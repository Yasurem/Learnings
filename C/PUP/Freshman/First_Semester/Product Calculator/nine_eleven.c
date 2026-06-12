#include <stdio.h>

int main(void)
{
    int n;
    int FProd = 1;

    // Input Number
    do
    {
        printf("Input number (0 - terminate): ");
        scanf("%d", &n); 

        if (n == 0)
        {    
            printf("\nThe current product is: %d\n", FProd);
        }

        else if (n > 0)
        {
            FProd = FProd * n;
        }

        else
        {
            printf("\nNegative numbers are prohibited.");
            printf("\nThe current product is: %d\n", FProd);
        }
    }
    while (n != 0);
}
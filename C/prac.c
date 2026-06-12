#include <stdio.h> // standard input output . header
// #include <conio.h>

// int - integer
// float - floating point

// %d - digit
// %i - integer
// achieves the same result

// & - ampersand
int main () 
{
    int n;

    printf("Input Number: ");
    scanf("%d", &n);

    // Identify if n is an odd or even value
    while (n % 2 != 0) 
    {
        printf("Input Number: ");
        scanf("%i", &n);
    }

    if (n % 2 == 0) // n is even
    {
        printf("Even number!");
    }

    return 0;
}
#include <stdio.h>

int dwarf(int dwarfC);
int prime(int input);

int main (void)
{
    int input, dwarfC;

    printf("Input non-negative number: ");
    scanf("%d", &input);

    dwarfC = prime(input);
    dwarf(dwarfC);
}

int dwarf(int dwarfC)
{
    if (dwarfC == 1)
    {
        printf("DWARF!\n");
    }
    else
    {
        printf("NOT DWARF!\n");
    }
}

int prime(int input)
{
    int factor, i;
    float halfI;
    int sumF = 0;

    halfI = input / 2.0;
    for (factor = 1; factor < input; factor++)
    {
        if ((input % factor) == 0) // Translation: While the input is divisible by the factor (i), divide it by the factor then add the factors
        {
        // How many times it can be divided by i meaning that i is a factor
            sumF = sumF + factor; // Sum of the Factors
            printf("%d ", factor);
        } 
    }

    printf("\nThe sum of the factors is: %d\nThe half of the input is: %.2f\n", sumF, halfI);

    if (sumF > halfI)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
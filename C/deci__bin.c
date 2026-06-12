#include <math.h>
#include <stdio.h>
#include <string.h>

int deci_converter(int deci);
int bin_converter(int bin);

int main(void)
{
    int deci, bin;
    int exit = 0;
    char ans[8];
    do
    {
        printf("Note: Type 'x' to exit\n\nChoose Input: Decimal or Binary? ");
        scanf("%s", ans);

        if (strcmp(ans, "DECIMAL") == 0 || strcmp(ans, "Decimal") == 0 ||
            strcmp(ans, "decimal") == 0)
        {
            printf("Input decimal: ");
            scanf("%d", &deci);
            int fin_val = deci_converter(deci);
            printf("Binary: %d\n\n", fin_val);
        }

        else if (strcmp(ans, "binary") == 0 || strcmp(ans, "Binary") == 0 ||
                 strcmp(ans, "BINARY") == 0)
        {
            printf("Input binary: ");
            scanf("%d", &bin);
            int fin_val = bin_converter(bin);
            printf("Decimal: %d\n\n", fin_val);
        }
        else if(strcmp(ans, "x") == 0)
        {
            printf("Bye!");
            exit = 1;
        }
        else
        {
            printf("Invalid Input!\n\n");
        }
    }
    while (exit != 1);
}

int deci_converter(int deci)
{
    int fin_val = 0;
    int i, bin;
    for (i = 0; deci > 0; i++)
    {
        bin = deci % 2;
        deci = deci / 2;
        fin_val = fin_val + (bin * pow(10, i));
    }
    return fin_val;
}

int bin_converter(int bin)
{
    int fin_val = 0;
    int x = 1;
    int i, rem;
    for (i = 1; bin > 0; i++)
    {
        rem = bin % 10;
        bin = bin / 10;
        if (rem == 1)
        {
            fin_val = fin_val + x;
        }
        else if (rem == 0)
        {
            fin_val = fin_val + 0;
        }
        else
        {
            printf("Invalid! Not a binary number!\n\n");
        }
        x = x * 2;
    }
    return fin_val;
}

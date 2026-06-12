#include <stdio.h>

int main (void)
{
    int n1, n2, gcf, i, yn;
    do
    {
        // User Input
        printf("Input 1st number: ");
        scanf("%d", &n1);
        printf("Input 2nd number: ");
        scanf("%d", &n2);

        for (i = 2; i <= n1 && i <= n2; i++)
        {
            if ((n1 % i) == 0 && (n2 % i) == 0)
            {
                gcf = i;
            }    
        }
        printf("%d", gcf);
        printf("\nContinue? 1 - Yes | Else - Exit\n");
        scanf("%d", &yn); 
    } 
    while (yn == 1);
}
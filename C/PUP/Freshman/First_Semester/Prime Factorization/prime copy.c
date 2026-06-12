#include <stdio.h>

int main(void)
{
    int i, j, num, checkR, remE, remO;
    i = 1; j = 1;
    checkR = 0;
    // Input
    do
    {
        printf("Input: ");
        scanf("%d", &num);
        checkR = num % 2; 
    } while (num < 1);

    // Divide by 2
    while (checkR == 0)
    {
        checkR = num % 2;
        num = num / 2;
        i++;
    }

    printf("2, %d", i);
}
#include <stdio.h>

int main(void)
{
    int num, i, p, prime;

    do{
    printf("Enter a number: ");
    scanf("%d",&num);
    }
    while (num < 1);
    
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            prime = 1;
            for (p = 2; p <= i/2; p++)
            {
                if (i % p == 0)
                {
                    prime = 1;
                }
            }
            if (prime == 1)
            {
                printf("%d ", i);
            }
        }
    }
}
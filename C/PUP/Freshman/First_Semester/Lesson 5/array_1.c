#include <stdio.h>

int EVEN(int BSIT[]);
int main()
{
    int BSIT[20], i, ESum;
    
    for (i = 0; i < 20; i++)
    {
        printf("Input value %d: ", i + 1);
        scanf("%d", &BSIT[i]);
    }

    // Sum of all even indexes
    ESum = EVEN(BSIT);

    // Print array BSIT
    for (i = 0; i < 20; i++)
    {
        printf("%d ",  BSIT[i]);
    }

    // Print result
    printf("\nSum (Even Index): %d", ESum);
}

int EVEN(int BSIT[])
{
    int ESum = 0;
    int i;
    for (i = 1; i <= 20; i += 2)
    {
        ESum = ESum + BSIT[i];
    }
    return ESum;
}

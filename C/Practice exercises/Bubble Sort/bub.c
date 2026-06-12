#include <stdio.h>

void bub_sort(int n, int arr[]);
int main ()
{
    int a, n;

    printf("Array Size: ");
    scanf("%d", &n);

    int array[n];

    for (a = 0; a < n; a++)
    {
        printf("Value %d: ", a + 1);
        scanf("%d", &array[a]);
    }

    bub_sort(n, array);

    // Print
}

void bub_sort(int n, int arr[])
{
    int a, b, tmp, swap;


    for (a = 0; a < n; a++)
    {
        swap = 0;
        for (b = 0; b < n - a - 1;b++)
        {
            if (arr[b + 1] < arr[b])
            {
                swap = 1;

                tmp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = tmp;

                printf("| a: %d | b: %d | b + 1: %d |\n", a, b, b + 1);
            }
        }

        // prevents the code from executing further if no swaps were made
        if (swap == 0)
        {
            break;
        }
    }

    for (a = 0; a < n; a++)
    {
        printf("[%d]: %d\n", a + 1, arr[a]);
    }
}
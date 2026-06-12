#include <stdio.h>

void insertion(int arr[]);

int main()
{
    int a, b;
    int arr[] = {5, 4, 3, 2, 1};

    insertion(arr);

    for (a = 0; a < 5; a++)
    {
        printf("%d", arr[a]);
    }
}

void insertion(int arr[])
{
    int a, b, key;

    for (a = 1; a < 5; a++)
    {
        key = arr[a];
        b = a - 1;

        while (b >= 0 && arr[b] > key)
        {
            arr[b + 1] = arr[b];
            b--;
        }
        arr[b + 1] = key;
    }
}
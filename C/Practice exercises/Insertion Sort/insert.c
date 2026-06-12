#include <stdio.h>

void sort(int s, int arr[]);
int main ()
{
    int a, b, s;

    printf("Input Array Size: ");
    scanf("%d", &s);

    int arr[s];

    for (a = 0; a < s; a++)
    {
        printf("[%d]: ", a + 1);
        scanf("%d", &arr[a]);
    }

    sort(s, arr);

    for (a = 0; a < s; a++)
    {
        printf("%d ", arr[a]);
    }
}

void sort(int s, int arr[])
{
    int i, j, n, key;
    for (i = 1; i < s; i++)
    {
        key = arr[i]; // Store smallest value so far (Range: 2 values): key = 3
        j = i - 1; // i - 1 ensures that j starts at 0: j = 1, i = 2

        while (j >=0 && arr[j] > key) // if j is greater than or equal to 0 and the arr[j] is greater than the key: j == 0 and (arr[1] = 5) > (key = 3)                            
        {                               // Move the greater value up 
            arr[j + 1] = arr[j];        // Copy the value to the next index: arr[2] (3) = arr[1] (5); arr[2] = 5 [5 5 3 2 1][4 5 5 2 1]
            j--;                        // Decrement j: j = 0 - 1 = [-1] [0]
        }
                                        // if there are no more values less than the stored value, 
        arr[j + 1] = key;               // Store the smallest value so far inside that index: arr[j + 1] (arr[0]) = key (4) [4 5 3 2 1]
    }
}
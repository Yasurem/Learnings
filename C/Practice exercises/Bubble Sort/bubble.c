#include <stdio.h>

int main ()
{
    int i, j, flag, tmp;

    int arr[] = {5, 4, 3, 2, 1};

    for (i = 0; i < 5; i++)
    {
        flag = 0;
        for (j = 0; j < 5 - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                flag = 1;                
            }
        }

        if (flag == 0)
        {
            break;
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
}
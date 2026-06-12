#include <stdio.h>
#include <unistd.h>

void get_int(int array[], char letter, int n);
int merge(int A[], int B[], int C[], int n);
void printArr(int A[], int B[], int C[], int n, int s);
void AsSort(int arr[], int s);
void animate(int arr[], int h, int s, int last);

int main ()
{
    // Create arrays A, B, and C;
    int n = 5, s;
    int A[n], B[n], C[n * 2];

    // Prompt for five input for arrays A and B
    get_int(A, 'A', n);
    get_int(B, 'B', n);

    // Merge the two inputs into C
    s = merge(A, B, C, n);

    // Sort the C array
    AsSort(C, s);

    // Print with animation
    printArr(A, B, C, n, s);
}

void get_int(int array[], char letter, int n)
{
    int a;
    for (a = 0; a < n; a++)
    {
        printf("%c[%d]: ", letter, a + 1);
        scanf("%d", &array[a]);
    }
    printf("\n");
}
int merge(int A[], int B[], int C[], int n)
{
    int a, b, duplicate, size = n;
    for (a = 0; a < n; a++)
    {
        C[a] = A[a];
    }

    for (a = 0; a < n; a++)
    {
        duplicate = 0;
        for (b = 0; b < size; b++)
        {
            if (B[a] == C[b]) // Duplicate
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 0) // Not duplicate
        {
            C[size] = B[a];
            size++;
        }
    }
    return size;
}
void printArr(int A[], int B[], int C[], int n, int s)
{
    int a, b;

    printf("A: \n\t{ ");
    for (a = 0; a < n; a++)
    {
        printf("%d ", A[a]);
    }  
    printf("}\n\n");

    printf("B: \n\t{ ");
    for (a = 0; a < n; a++)
    {
        printf("%d ", B[a]);
    }
    printf("}\n\n");

    printf("C: \n\t{ ");
    for (a = 0; a < s; a++)
    {
        printf("%d ", C[a]);
    }
    printf("}\n\n");
}
void AsSort(int arr[], int s)
{
    int a, b, bigger, temp, i;

    for (a = 0; a < s; a++)
    {
        i = a; // Smallest number
        for (b = a + 1; b < s; b++)
        {
            if (arr[b] < arr[i]) // Look if there is a value smaller than a
            {
                i = b; // If there is a value smaller, the position is stored in i
                animate(arr, b, s, a);
            }
        }
            
        if (i != a) // a is no longer the smallest, swap arr[a] and arr[b]
        {  
            temp = arr[a];
            arr[a] = arr[i];
            arr[i] = temp;
        }
    }
}
void animate(int arr[], int h, int s, int last)
{
    int a;
    for (a = 0; a < s; a++) // Print the array
    {
        if (a == h || a < last)
        {
            printf(" [%d] ", arr[a]); // Print the highlighted value
        }

        else
        {
            printf(" %d ", arr[a]); // Print the other values
        }
    }
        printf("\n");
        fflush(stdout);
        usleep(500000); // 500 milliseconds delay
        system("cls"); 
}
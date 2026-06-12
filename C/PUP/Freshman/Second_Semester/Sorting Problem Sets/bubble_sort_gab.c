#include <stdio.h>
#include <unistd.h>

// Animation
void animate(int arr[], int h, int s, int last);

// Sorting
int sorting(int arr[], int s);
void AsSort(int arr[], int s);
void DesSort(int arr[], int s);

// General
void get_int(int array[], char letter, int n);
int merge(int A[], int B[], int C[], int n);
void printArr(int A[], int B[], int C[], int n, int s);

int main ()
{
    fflush(stdout);
    system("cls");
    // Create arrays A, B, and C;
    int n = 5, s, dec = 1;
    int A[n], B[n], C[n * 2];

    while (dec != 0)
    {
        // Prompt for five input for arrays A and B
        get_int(A, 'A', n);
        get_int(B, 'B', n);

        // Merge the two inputs into C
        s = merge(A, B, C, n);

        // Sort the C array
        dec = sorting(C, s);

        // Print with animation
        printArr(A, B, C, n, s);

        // Ask if the user want to repeat
        printf("Would you like to input another set of values? Yes (Type 1) | Exit (Type 0)\nInput: ");
        scanf("%d", &dec);
    }
    return 0;
}
int sorting(int arr[], int s)
{
    int choice;
    do
    {
        printf("How do you want the values to be arranged?\n\n");
        printf("Ascending [Input: 1] | Descending [Input: 2] | No need to sort, just exit [Input: 0]\n\nInput: ");
        scanf("%d", &choice);
        printf("\n\n");
    } 
    while ( choice < 0 && choice > 2);
    
    if (choice == 0)
    {
        return 0;
    }

    else if (choice == 1)
    {
        AsSort(arr, s);
    }
    
    else
    {
        DesSort(arr, s);
    }
}
void AsSort(int arr[], int s)
{
    int a, b, bigger, temp, swap;

    for (a = 0; a < s - 1; a++)
    {
        swap = 0;
        for (b = 0; b < s - a - 1; b++)
        {
            if (arr[b + 1] < arr[b]) // If the value in index b is smaller than index b + 1, swap the position 
            {
                temp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = temp;
                animate(arr, b, s, b);

                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
}
void DesSort(int arr[], int s)
{
    int a, b, swap, temp;

    for (a = 0; a < s - 1; a++)
    {
        swap = 0;
        for (b = 0; b < s - a - 1; b++)
        {
            if (arr[b] < arr[b + 1])
            {
                temp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = temp;
                animate(arr, b, s, b);

                swap = 1;
            }

        }
        if (swap != 1)
        {
            break;
        }
    }
}
void animate(int arr[], int h, int s, int last)
{
    int a;
    printf("Sorting...\n");
    for (a = 0; a < s; a++) // Print the array
    {
        
        if (a == (h + 1) || a == h)
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
void get_int(int array[], char letter, int n)
{
    int a, b, duplicate;
    printf("Input five values for array %c\n\n", letter);

    for (a = 0; a < n; a++)
    {
        do
        {
            printf("%c[%d]: ", letter, a + 1);
            while(scanf("%d", &array[a]) !=1) 
            {
                printf("[Note: Must be an integer!]\n\n");
                printf("%c[%d]: ", letter, a + 1);
                while(getchar() != '\n');
            }

            // Check for duplicates
            for (b = 0; b < a; b++)
            {
                duplicate = 0; // Assume no duplicates

                if (array[a] == array[b]) // Duplicate detected!
                {
                    duplicate = 1; // There is a duplicate
                    printf("[Note: Must not repeat a value!]\n\n"); // Print error message
                    break; // Stop checking for duplicates
                }
            }
        } 
        while (duplicate); // Repeat the loop if there is a detected duplicate    
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


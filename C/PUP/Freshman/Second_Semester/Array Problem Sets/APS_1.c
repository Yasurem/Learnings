/* Write a program that will input 5 unique integers in an array N and another 5 unique integers in an array B. 
After which call a function MERGE that will merge the two arrays in one array called MERGE_ARRAY such that all 
the values are unique (that is, no integer should appear twice). Display the three arrays.*/

#include <stdio.h>

void get_int(char prompt[], int array[]);
int MERGE(int N[], int B[], int MERGE_ARRAY[], int n);
void print_o(int N[], int B[], int MERGE_ARRAY[], int n, int s);

int main()
{
    // Initialization
    int n = 5, s;
    int N[n], B[n], MERGE_ARRAY[n * 2];

    // Input 5 unique integers (N)
    get_int("N", N);

    // Input 5 unique integers (B)
    get_int("B", B);

    // Call MERGE_ARRAY = MERGE()
    s = MERGE(N, B, MERGE_ARRAY, n);

    // Print the three arrays
    print_o(N, B, MERGE_ARRAY, n, s);

}

void get_int(char prompt[], int array[])
{
    int a, b, duplicate;

    for (a = 0; a < 5; a++)
    {
        do
        {
            // Prompt
            printf("%s[%d]: ", prompt, a + 1);
            scanf("%d", &array[a]);

            // Check for duplicates
            duplicate = 0;
            for (b = 0; b < a; b++)
            {
                if (array[a] == array[b])
                {
                    duplicate = 1;
                    printf("There must be no same inputs per array\n");
                    break;
                }
            }
        } 
        while (duplicate);       
    }
    printf("\n");
}

int MERGE(int N[], int B[], int MERGE_ARRAY[], int n)
{
    int a, b;
    int merged_size = n;

    // Add the N array to the merge
    for (a = 0; a < n; a++)
    {
        MERGE_ARRAY[a] = N[a];   
    }

    for (a = 0; a < 5; a++)
    {
        int duplicate = 0;
        for (b = 0; b < merged_size; b++)
        {
            // Only add B[b] if they are not == N[a]
            if (MERGE_ARRAY[b] == B[a])
            {
                duplicate = 1;
                break;
            }   
        }

        if (duplicate == 0)
        {
            MERGE_ARRAY[merged_size] = B[a];
            merged_size++;            
        }
    }
    return merged_size;
}

void print_o(int N[], int B[], int MERGE_ARRAY[], int n, int s)
{
    int a, b;

    printf("Array N: ");
    for (a = 0; a < 5; a++)
    {
        printf("%d ", N[a]);
    }
    printf("\n");

    printf("Array B: ");
    for (a = 0; a < 5; a++)
    {
        printf("%d ", B[a]);
    }
    printf("\n");

    printf("Merged: ");
    for (a = 0; a < s; a++)
    {
        printf("%d ", MERGE_ARRAY[a]);
    }
}
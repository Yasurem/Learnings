#include <stdio.h>

int merge(int A[], int B[][3], int index, int a);
void printArrays(int A[], int B[][3], int C[]);
int main ()
{
    int arr_i = 3, a, b, n;
    int A[arr_i], B[arr_i][arr_i], C[arr_i];

    for (a = 0, n = 0; a < 3; a++)
    {
        A[a] = a;
        for (b = 0; b < 3; b++)
        {
            B[a][b] = n;

            n++;
        }
    }

    for (a = 0; a < 3; a++)
    {
        C[a] = merge(A, B, arr_i, a);
    }

    printArrays(A, B, C);
}

int merge(int A[], int B[][3], int index, int a)
{
    int merge[index];

    merge[a] = (A[0] * B[a][0]) + (A[1] * B[a][1]) +  (A[2] * B[a][2]);
    return merge[a];
}

void printArrays(int A[], int B[][3], int C[])
{
    int i, j;

    // Array A
    printf("|---------------------|\n|\tArray A\t      |\n|     \t\t      |\n|");
    for (i = 0; i < 3; i++)
    {
        printf("   %d   ", A[i]);
    }
    printf("|");
    printf("\n|     \t\t      |\n|---------------------|\n");

    // Array B
    printf("|\tArray B\t      |\n|     \t\t      |");    
    for (i = 0; i < 3; i++)
    {
        printf("\n|");   
        for (j = 0; j < 3; j++)
        {

            printf("   %d   ", B[i][j]);
        }
        printf("|");
    }
    printf("\n|     \t\t      |\n|---------------------|\n|"); 

    // Array C
    printf("\tArray C\t      |\n|     \t\t      |\n|");  
    for (i = 0; i < 3; i++)
    {
        printf("   %d  ", C[i]);
    }
    printf(" |\n|     \t\t      |\n|_____________________|");
}
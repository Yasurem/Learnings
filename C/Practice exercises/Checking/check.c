#include <stdio.h>

void ADD(int n, int A[], int B[]);
void sort(int n, int B[]);

int main (void) {
    int n = 10;
    int i, j, Array_A[n], Array_B[n-1];

    for (i = 0; i < n; i++) {
        printf("A[%d]: \n", i+1);
        scanf("%d", &Array_A[i]);
    }

    ADD(n, Array_A, Array_B);
    sort(n, Array_B);

    printf("B: ");
    for (i = 0; i < n - 1; i++) {
        printf("%d, ", Array_B[i]);
    }
    return 0;
}

void ADD(int n, int A[], int B[])
{
    int a;
    for (a = 0; a < n - 1; a++) {
        B[a] = A[a] + A[a + 1];
    }
    printf("Array A: {\n");
    for (a = 0; a < n; a++) {
        printf("%d ", A[a]);
    }
}

void sort(int n, int B[])
{
    int i, j, flag, tmp;

    for (i = 0; i < n - 1; i++){
        flag = 0;
        for (j = 0; j < n - 1 - i - 1;j++) {
            if (B[j + 1] < B[j]){
                tmp = B[j + 1];
                B[j + 1] = B[j];
                B[j] = tmp;
            }
        }
        if (flag = 0) {
            break;
        }
    }
}
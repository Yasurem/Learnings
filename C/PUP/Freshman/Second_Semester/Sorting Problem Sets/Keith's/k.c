#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep()

void clearTerminal() 
{
    system("cls"); // Uncomment this line for Windows systems
}

void printArray(int arr[], int size, int highlight) {
    printf("Array: ");
    for (int k = 0; k < size; k++) {
        if (k == highlight) {
            printf("[%d] ", arr[k]);
        } else {
            printf("%d ", arr[k]);
        }
    }
    printf("\n");
    fflush(stdout);
    usleep(500000); // 500 milliseconds delay
    // clearTerminal();
}

void bubbleSort(int arr[], int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            printArray(arr, size, j);
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; 
    }
}

int main() {
    int arr[] = {10, 6, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array:\n");
    printArray(arr, size, -1);

    bubbleSort(arr, size);

    printf("Sorted Array:\n");
    printArray(arr, size, -1);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int target);

int main() {
    // Size of the array
    int n, target;

    while(1) {
        // Prompt user for array size and elements
        printf("Enter the number of elements in the sorted array: ");
        if(scanf("%d", &n) == -1) {
            // Handle invalid input
            printf("Invalid input. Please enter an integer value.\n");
            continue;
        }
        // Clear input buffer
        while (getchar() != '\n'); 
        if (n <= 0) {
            printf("Please enter a positive integer for the number of elements.\n");
            continue;
        }

        int array[n];
        printf("Enter the elements in sorted order\n");
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &array[i]);
            while (getchar() != '\n'); 
        }

        // Prompt for target element
        printf("Enter the target element to search for: ");
        scanf("%d", &target);
        while (getchar() != '\n');
        
        // Perform binary search
        int index = binarySearch(array, n, target);
        if (index != -1) {
            printf("Element %d found at index %d.\n", target, index);
        } else {
            printf("Element %d not found in the array.\n", target);
        }

        // Ask if the user wants to perform another search
        char choice;
        printf("Do you want to perform another search? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');
        if (choice != 'y' && choice != 'Y') {
            break;
        }  
    }
    return 0;
}

int binarySearch(int arr[], int n, int target) {
    int index;
    int left = 0;
    int right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            index = mid;
            found = 1;
            break;
        }
        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        return -1;
    }

    return index;
}



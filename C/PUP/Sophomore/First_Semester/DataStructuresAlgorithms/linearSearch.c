#include <stdio.h>

int linearSearch(int arr[], int n, int target);

int main() {
    // Size of the array
    int n, target;

    while(1) {
        // Prompt user for array size and elements
        printf("Enter the number of elements in the array: ");
        if(scanf("%d", &n) == -1) {
            while (getchar() != '\n'); 
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
        printf("Enter the elements\n");
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            if (scanf("%d", &array[i]) == -1) {
                while (getchar() != '\n'); 
                printf("Invalid input. Please enter an integer value.\n");
                i--; // Decrement i to retry this index
                continue;
            }
            while (getchar() != '\n'); 
        }

        // Prompt for target element
        printf("Enter the target element to search for: ");
        scanf("%d", &target);
        while (getchar() != '\n');
        
        // Perform linear search
        int index = linearSearch(array, n, target);
        if (index != -1) {
            printf("Element %d found at index %d\n", target, index);
        } else {
            printf("Element %d not found in the array\n", target);
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

int linearSearch(int arr[], int n, int target) {
    // Flag variable if the element is found
    int found = 0;
    int index;

    // Find the target element
    for (int i = 0; i < n; i++)
    {
        // If the current element matches the target
        if (arr[i] == target)
        {
            index = i;
            found = 1;
            break;
        }
    }

    // If the element is not found
    if (!found)
    {
        return -1;
    }

    return index;
}



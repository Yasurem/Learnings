#include <stdio.h>
#include "../Headers/display.h"

void selectionSort(int arr[], int s)
{
    int i, j, temp;
    for (i = 0; i < s; i++)
    {
        for (j = i + 1; j < s; j++)
        {
            if (arr[j] < arr[i])
            {
                animate(arr, i, j, s); // Ignore, for display purposes only
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;                  
            }
        }
    }

    // Print Result
    printOut(arr, s);
}
/*  Why there is room for improvement:
    
    Inefficient
    Performs too many swaps
    and Redundant Comparisons */


/* 
    Selection sort: 
        - The simplest sorting algorithm 

        - Works just like how humans arrange numbers 
        
        - Not the fastest nor the slowest sorting algorithm

        Three fundamental steps: 
            a.) Observe the whole array
            b.) Identify the smallest value
            c.) Perform the swap
            d.) Repeat if necessary        

        Time Complexity: 
        O(n²)
        - the number of operations the algorithm performs increases proportionally to n multiplied by itself
*/ 

void betterSelectionSort(int arr[], int s)
    {
        int i, j, min, temp; // Initialization
    
        for (i = 0; i < s; i++) 
        {
            min = i; // Assume that the first index contains the smallest array, just in case that the array is already sorted

            for (j = i + 1; j < s; j++) // Note: Imagine j as the inspector that looks for smaller values
            {   
                if (arr[j] < arr[min]) // if the value where j currently is is lower than the smallest value so far
                {
                    min = j; // set where j currently is as the new location of the smallest value
                }
            }
            
            // If there j found no value 
            if (min != i)
            {
                animate(arr, i, min, s); // Disregard (Display-related)

                // Perform the swap
                temp = arr[i]; // Place the value in index i on a temporary storage
                arr[i] = arr[min]; // Replace the value at the index i with the smallest value
                arr[min] = temp; // Place the value inside the temporary storage (temp) to the former index of the smallest value
            }
        }

        // Print the outcome
        printOut(arr, s);
    }

/* 
    Linear search (a.k.a Sequential search)
        - The simplest searching algorithm 
        
        - Better than Binary search if values are not sorted

        One main step: 
            - Check every index until target is found
            - If target not found, return -1

        Time Complexity: 
        O(n)
        - the number of operations the algorithm performs increases proportionally to n
*/ 

// Linear Search
int linearSearch(int arr[], int s, int target)
{
    int i;

    for (i = 0; i < s; i++) // Read the whole array
    {
        if (arr[i] == target) // If i detects the target, print "Found!"
        {
            printf("\n| FOUND!\n| Location: arr[%d]\n", i); // You can also just return the index to the main instead,
            return 0;
        }
    }  

    printf("| Target Not found!");
    return -1; // Error: Target not found
}

/* 
    Binary search 
        - The best searching algorithm when a dataset is already sorted
        
        - Better than Binary search if values are not sorted

        - Works similarly to how humans search for a page in a dictionary if there is no table of contents

        Fundamental steps: 
            a.) Start from the median
            b.) If the median isn't equal to the target, check if the target is larger or smaller than the median
            c.) If the target is larger than the medium, then disregard the bottom half and vice versa
            d.) If the target is not found, return -1


        Time Complexity: 
        O(log n)
        - The time required to run the algorithm increases logarithmically with the size of the input
*/

// Binary Search
int binarySearch(int arr[], int s, int target)
{
    int low = 0; // Lowest Array Index
    int high = s - 1; // Highest Array Index | Note: s - 1 is equal to high because the first index is 0
    
    while (low <= high) // While the highest index is greater than or equal to lowest index
    {
        int mid = low + (high - low) / 2; // Could be low + high/2 however, low + (high - low) prevents integer overflow

        /* 

        Integer overflow example:
            low = 2,000,000,000
            high = 2,000,000,002
            
            low + high = 4,000,000,002 exceeds the maximum value for a 32-bit integer
            This causes the integer overflow.

        */

        if (arr[mid] == target) // Target found!
        {
            printf("\n| FOUND!\n| Location: arr[%d]\n", mid);
            return 0;
        }

        else if (arr[mid] > target) // The target is less than the median
        {
            high = mid - 1; // The code will no longer check for arr[mid] to the last index
        }

        else // The targer is greater than the median
        {
            low = mid + 1;  // The code will no longer check for lowest index to arr[mid]
        }
    }

    // Loop finished without finding the target
    printf("| Target Not Found!\n");

    return -1; // Error: Target not found
}
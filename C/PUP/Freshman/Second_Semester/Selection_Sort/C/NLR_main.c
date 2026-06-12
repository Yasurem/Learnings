/* 

Everything in this file was created by Joemarc Jr. D. Castillo for the course Computer Programming 2
 
Note:
        Non-lesson-related features such as display, interactives, and main contain the label "NLR_" 
        
        The folder "Headers" contains all the header files used in this activity                    
        
        The folder "C" contains the main file and the function definitions of the headers in the "Headers" folder

*/

// Lesson-related functions are located in the file: "ss_lesson.c" inside the folder "C"

// Headers
#include <stdio.h>
#include <unistd.h>
#include "../Headers/display.h"
#include "../Headers/interactive.h"
#include "../Headers/lesson.h"

// Color Definitions
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

/* Note: The subfunctions above are defined after the main function */

// Main Function
int main(void)
{
    int yn;
    do
    {
        system("cls");
        int s = 6, method, search, src, srcD;                   // Default Value is 5
        int arr[/*s*/] = {6, 2, 1, 5, 4, 3}; // Array Declaration

// Note: Uncomment the code snippet below if you wish to enter your own values
        // s = input(arr, s);

    // Display initial values
        iniDisp(arr, s);

        
        // User Input
        method = choose_method();

        if (method == 1)
        {
        // Use the Unoptimized Sorting Method
            selectionSort(arr, s);
        }
        else if (method == 2)
        {
        // Use the Optimized Selection Sort
            betterSelectionSort(arr, s);
        }
        else
        {
            return 0;
        }

        do
        {
            // Ask for searching method
            method = choose_search();

            if (method != 0)
            {
                search = searchIn();
            }
            
            if (method == 1)
            {
            // Use Linear Search
                src = linearSearch(arr, s, search);
                
            }
            else if (method == 2)
            {
            // Use Binary Search
                src = binarySearch(arr, s, search);
            }
            else
            {
                return 0;
            }

            printf("|-------------------------------------\n| Would you like to search for another value?\n|\t1 - Yes\t\t|\t0 - No\t|\n| Decision: ");
            scanf("%d", &srcD);
            
            if (src != -1)
            {
                printf("|-----Search was %ssuccessful!%s-----|\n", GREEN, RESET);
            }
            else
            {
                printf("|-----Search finished with an %serror: %d%s-----|", RED, RESET, src);
            }
        } 
        while (srcD == 1);

        // Ask if repeat or not
        yn = exit_decision();
        system("cls");
    }
    while (yn != 0);

}





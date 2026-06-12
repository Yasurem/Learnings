/* This file was created by Joemarc Jr. D. Castillo for the course Computer Programming 2 */

// Headers
#include <stdio.h>
#include <conio.h>
#include <unistd.h>

// Color Definitions
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Display-related functions :P
void animate(int arr[], int i, int h, int s);
void iniDisp(int arr[], int s);
void printOut(int arr[], int s);

// Interactive functions
int choose_method();
int exit_decision();

// Lesson-related functions
int input(int arr[], int s);
void selectionSort(int arr[], int s);
void betterSelectionSort(int arr[], int s);


/* Note: The subfunctions above are defined after the main function */

// Main Function
int main(void)
{
    int yn;
    do
    {
        system("cls");
        int s = 6, method;                   // Default Value is 5
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

        yn = exit_decision();
        system("cls");
    }
    while (yn != 0);
}

/* Important Functions */

// Lecture-related functions
int input(int arr[], int s)
{
    printf("Value Quantity: ");
    while (scanf("%d", &s) != 1 || s <= 0)
    {
        printf("Invalid input! Enter a positive integer: ");
        while (getchar() != '\n');
    }

    int i;
    for (i = 0; i < s; i++)
    {
        printf("[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return s;
}
int choose_method()
{
    int method;
    printf("Choose Sorting Method: \n(1) Normal Selection Sort\n(2) Better Selection Sort\n(0) Exit\nAnswer: ");
    while (scanf("%d", &method) != 1 || (method != 1 && method != 2))
    {
        if (method == 0)
        {  
            return 0;
        }
        printf("Invalid Choice!\n");
        while (getchar() != '\n');
    }

    return method;  
}

// Works just like how humans arrange small data sets
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

void betterSelectionSort(int arr[], int s)
{
    int i, j, min, temp;

    for (i = 0; i < s; i++)
    {
        min = i;
        for (j = i + 1; j < s; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        if (min != i)
        {
            animate(arr, i, min, s);
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printOut(arr, s);
}
/* Only swap once per iteration */

// Display-related definitions
void animate(int arr[], int i, int h, int s)
{
    int a;

    printf("%sSorting...\n%s", GREEN, RESET);
    for (a = 0; a < s; a++) // Print the array
    {
        if (a == i || a == h)
        {
            printf("%s [%d] %s", YELLOW, arr[a], RESET); // Print the highlighted value
        }

        else if (a < i)
        {
            printf("%s %d %s", GREEN, arr[a], RESET); // Print the other values
        }
        else
        {
            printf(" %d ", arr[a]);
        }
    }

    getch();
    printf("\n");
    fflush(stdout);
    usleep(150000); // 500 milliseconds delay
    system("cls");
}
void iniDisp(int arr[], int s)
{
    system("cls");
    int i;
    printf("%sUnsorted Array: \n", RED);
    for (i = 0; i < s; i++)
    {
        printf("%s%3d %s", RED, arr[i], RESET);
    }
    printf("\n");
    getch();
}
void printOut(int arr[], int s)
{
    int a;

    printf("%sSorted!\a\n{", GREEN);
    for (a = 0; a < s; a++)
    {
        printf("%3d ", arr[a]);
    }
    printf(" }%s", RESET);
    getch();
}
int exit_decision()
{
    int ans;
    printf("\nReturn (1) or Exit (0): ");
    while (scanf("%d", &ans) != 1 || (ans != 0 && ans != 1))
    {
        printf("\nInvalid Choice! \n");
        while (getchar() != '\n');
    }
    return ans;
}
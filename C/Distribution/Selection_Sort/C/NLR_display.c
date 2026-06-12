#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "../Headers/display.h"

// Color Definitions
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

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
    printf(" }%s\n", RESET);
    getch();
}

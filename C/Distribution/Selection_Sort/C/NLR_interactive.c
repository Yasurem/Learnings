#include <conio.h>
#include <stdio.h>
#include <unistd.h>

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
        printf("| Invalid Choice!\n");
        while (getchar() != '\n');
    }

    return method;  
}

int choose_search()
{
    system("cls");
    int method;
    printf("|\tChoose Searching Method\t|\n|\t(1) Linear Search\t|\n|\t(2) Binary Search\t|\n|\t(0) Exit\t\t|\n|\tDecision: ");
    while (scanf("%d", &method) != 1 || (method != 1 && method != 2))
    {
        if (method == 0)
        {  
            return 0;
        }
        printf("| Invalid input!\n");
        while (getchar() != '\n');
    }
    return method;
}

int searchIn()
{
    system("cls");
    int target;
    printf("| Enter the value to search: ");
    while (scanf("%d", &target) != 1)
    {
        printf("\n| Invalid input! Please enter a valid integer.\n|\n| Search: ");
        while (getchar() != '\n'); // Clear buffer
    }
    return target;
}

int exit_decision()
{
    int ans;
    printf("\n|\tReturn to Main Menu (1) | Exit (0)\t|\n| Decision: ");
    while (scanf("%d", &ans) != 1 || (ans != 0 && ans != 1))
    {
        printf("\n| Invalid input!\n");
        while (getchar() != '\n');
    }
    return ans;
}
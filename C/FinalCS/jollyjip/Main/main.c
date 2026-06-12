// Header
#include <stdio.h>
#include <string.h>
#include "../header/interactive.h"
#include "../header/display.h"

// Modify promp messages here
char * ordr_msg = "What would you like to order?";
char * inv_msg = "| Invalid response.";
char * ordrd_msg = "| Would you like to order again?";

// Main Menu
int main ()
{
    int ans;

    // Display Welcome to Jolly Jip Restaurant
    while (1)
    {
        dispMain();
        scanf("%d", &ans);
        while (getchar() != '\n');

        switch (ans)
        {
            case 1:
                if(billSub(ordr_msg, inv_msg) == 0)
                {
                    continue;
                }
                break;
            case 2:
                fileMnt();
                break;
            case 3:
                printf("\n\tThank you! Exiting...\n");
                return 0;
            default:
                invalid_msg(inv_msg);
        }

        printf("\nPress Enter to continue...");
        getchar(); // Pause before re-showing menu
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../display.h"
#include "../interactive.h"

void dispMain()
{
    printf("     \t\tJOLLY - JIP RESTAURANT\n\n");
    printf("     FINANCIAL INFORMATION SYSTEM\n\n");
    printf("     \t\tMAIN MENU\n\n");
    printf("     [1] Billing Sub-Module\n");
    printf("     \t[a] Ordering and Receipt\n");
    printf("     \t[b] Generate daily total sales\n\n");
    
    printf("     [2] File Maintenance\n");
    printf("     \t[a] Add new record\n");
    printf("     \t[b] Update Record\n");
    printf("     \t\t[a] Menu\n");
    printf("     \t\t[b] Price\n");
    printf("     \t[c] Display Updated Records\n\n");

    printf("     [3] Exit Program\n\n");
    printf("     Choose: ");
}

void dispBillSM()
{
    system("cls");
    printf("     \tBilling Sub-Module\n");
    printf("     \t[a] Ordering and Receipt\n");
    printf("     \t[b] Generate daily total sales\n\n");
    printf("     Choose: ");
}

void dispfMNT()
{
    system("cls");
    printf("     \tFile Maintenance\n");
    printf("     \t[a] Add new record\n");
    printf("     \t\t[a] Menu\n");
    printf("     \t[b] Update Record\n");
    printf("     \t\t[a] Menu\n");
    printf("     \t\t[b] Price\n");
    printf("     \t[c] Display Updated Records\n\n");
    printf("     Choose: ");    
}

void dispAdd()
{
    system("cls");
    printf("     \t\t[a] Menu\n");
    printf("     Choose: ");    
}

void dispUPDTRec()
{
    system("cls");
    printf("     \tUpdate Record\n");
    printf("     \t\t[a] Menu\n");
    printf("     \t\t[b] Price\n");
    printf("     Choose: ");    
}

int displayMenu()
{
    system("cls");
    FILE *file = fopen("./Main/menu.csv", "r");
    if (!file) 
    {
        printf("\n\tCould not open menu file.\n");
        return -1;
    }

    char code[MAX_CHAR];
    char desc[5 * MAX_CHAR];
    float price;

    printf("\n\t%-10s | %-25s | %-10s\n", "CODE", "DESCRIPTION", "PRICE");
    printf("\t------------------------------------------------------\n");

    while (fscanf(file, "%[^,],%[^,],%f\n", code, desc, &price) == 3) {
        printf("\t%-10s | %-25s | %-10.2f\n", code, desc, price);
    }

    fclose(file);
}


void displayRec()
{
    char choice;

    system("cls"); // use "clear" if you're on Linux/Mac
    printf("\n\tDISPLAY UPDATED RECORDS\n\n");
    printf("\t[A] View Full Menu\n");
    printf("\t[B] View Price Only\n");
    printf("\n\tChoose option: ");
    scanf(" %c", &choice);
    while (getchar() != '\n');

    choice = tolower(choice);

    switch (choice) {
        case 'a':
            displayMenu();
            break;
        case 'b':
            displayPrice();
            break;
        default:
            printf("\n\tInvalid choice.\n");
            break;
    }
}

void displayPrice() 
{
    system("cls");
    FILE *file = fopen("./Main/menu.csv", "r");
    if (!file) {
        printf("\n\tCould not open menu file.\n");
        return;
    }

    char code[MAX_CHAR];
    char desc[5 * MAX_CHAR];
    float price;

    printf("\n\t%-10s | %-10s\n", "CODE", "PRICE");
    printf("\t---------------------------\n");

    while (fscanf(file, "%[^,],%[^,],%f\n", code, desc, &price) == 3) {
        printf("\t%-10s | %-10.2f\n", code, price);
    }

    fclose(file);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"
#include "../display.h"
#include "../interactive.h"
#include "../order.h"

void removeNewline(char *str) 
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') 
    {
        str[len - 1] = '\0';
    }
}

int billSub(char * ordr_msg, char * inv_msg)
{
    char resp;
    // Billing Sub-Module
    // [a] Ordering and Receipt
    // [b] Generate daily total sales
    // Choose:

    dispBillSM();
    scanf("%c", &resp);
    while(getchar() != '\n');

    switch(resp)
    {
        case 'a':
            int val;
            val = orderSys(ordr_msg, inv_msg);

            if (val == 0)
            {
                return 0;
            }
            break;
        case 'b':
            totalSales();
            break;
        default:
            return(invalid_msg(inv_msg));
            break;
    }
    return 0;
}

int orderSys(char * ordr_msg, char * inv_msg)
{
    // Check for menu file
    FILE * menu = fopen("./Main/menu.csv", "r");
    if (menu == NULL) 
    {
        printf("| Create a menu first!\n");
        fclose(menu); 
        return 0;
    } 

    // Check for menu file

    // Enter orders
    table Clients;
    int i = 0;
    char more;
    FILE * client_rec = fopen("./Main/clients.csv", "a"); // Append on clients.csv

    do 
    {
        Clients.num = i + 1;

        int quantity = order(ordr_msg, &Clients, menu, inv_msg);
        if (quantity != -1)
        {
            billingSummary(&Clients);
            record(&Clients, client_rec, quantity);
        }
        if (quantity < 0) break;  // if user cancels order

        record(&Clients, client_rec, quantity + 1);

        printf("| Another customer?\n| [Y/N]: ");
        scanf(" %c", &more);
        while(getchar() != '\n');
        more = tolower(more);

        i++;
    } 
    while (more == 'y');
    
    fclose(menu);
    fclose(client_rec); 
    // Enter orders
}

void totalSales()
{
    FILE *sales = fopen("./Main/clients.csv", "r");
    if (!sales)
    {
        printf("Could not open clients.csv\n");
        return;
    }

    char line[256];
    float totalBilling = 0;
    float totalDiscount = 0;
    float netBilling = 0;

    // Flags to track when we are in a customer block
    int inCustomerBlock = 0;

    // Temporary holders for each customer's bill and discount
    float currBill = 0;
    float currDisc = 0;

    while (fgets(line, sizeof(line), sales))
    {
        if (strstr(line, "| Customer#")) inCustomerBlock = 1;

        if (inCustomerBlock)
        {
            if (strstr(line, "| Discount:"))
                sscanf(line, "| Discount: %f", &currDisc);

            else if (strstr(line, "| Bill Total:"))
                sscanf(line, "| Bill Total: %f", &currBill);

            else if (strstr(line, "| Change:"))
            {
                // After reaching end of transaction block
                totalBilling += currBill;
                totalDiscount += currDisc;
                netBilling += (currBill - currDisc);
                currBill = 0;
                currDisc = 0;
                inCustomerBlock = 0;
            }
        }
    }

    fclose(sales);

    // Get date today
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Output Daily Report
    system("cls"); // Use "clear" if on Linux
    printf("\n=======================================================\n");
    printf("             DAILY TOTAL SALES REPORT                  \n");
    printf("               As of %02d-%02d-%04d                      \n",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("=======================================================\n");
    printf("Total billing for the day     : P %.2f\n", totalBilling);
    printf("Total discount provided       : P %.2f\n", totalDiscount);
    printf("Total net billing for the day: P %.2f\n", netBilling);
    printf("=======================================================\n\n");
    printf("\n| Press Enter to continue...");
    getchar(); // Pause before re-showing menu
}

int fileMnt()
{
    // File Maintenance
    //      [a] Add new record
    //          [a] Menu
    //      [b] Update Record
    //          [a] Menu
    //          [b] Price
    //      [c] Display Updated Records
    // Choose:
    dispfMNT();
    char resp;
    scanf("%c", &resp);

    switch (resp)
    {
    case 'a':
        char ans;
        dispAdd();

        scanf(" %c", &ans);
        while(getchar() != '\n');

        ans = tolower(ans);

        if (ans == 'a')
        {
            addRec();
        }

        else
        {
            perror("| Invalid!\n");
        }

        break;

    case 'b':
        updateRec();
        break;

    case 'c':
        displayRec();
        break;

    default:
        perror("| Invalid Choice!\n");
        break;
    }
}

void addRec()
{
    FILE *fp = fopen("./Main/menu.csv", "a"); // make sure the path is correct
    if (fp == NULL) 
    {
        system("cls");
        printf("\n\n\tUNABLE TO OPEN FILE\n\n");
        return;
    }

    char code[MAX_CHAR];
    char desc[5 * MAX_CHAR]; // Assuming larger space for item name
    float price;

    system("cls");  // Use "clear" on Linux/Mac
    printf("\n\t   ADD ITEM TO MENU\n\n");

    printf("\tItem Code: ");
    fgets(code, sizeof(code), stdin);
    removeNewline(code);

    printf("\tItem Description: ");
    fgets(desc, sizeof(desc), stdin);
    removeNewline(desc);

    printf("\tUnit Price: ");
    scanf("%f", &price);
    while (getchar() != '\n'); // clear leftover newline

    fprintf(fp, "%s,%s,%.2f\n", code, desc, price);

    fclose(fp);
    printf("\n\t  New record added SUCCESSFULLY\n\n");
}

void updateRec() 
{
    char choice;

    dispUPDTRec();
    scanf(" %c", &choice);
    while (getchar() != '\n'); // Clear input buffer

    choice = tolower(choice);

    switch (choice) 
    {
        case 'a':
            updateMenu();
            break;
        case 'b':
            updatePrice();
            break;
        default:
            printf("\n\tInvalid choice!\n");
            break;
    }
}

void updateMenu() 
{
    FILE *file = fopen("./Main/menu.csv", "r");
    FILE *temp = fopen("./Main/temp.csv", "w");
    if (!file || !temp) 
    {
        printf("\n\tError opening file.\n");
        return;
    }

    char code[MAX_CHAR], newDesc[5 * MAX_CHAR];
    char line[256];
    int found = 0;

    printf("\n\tEnter item code to update description: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = 0;

    printf("\tEnter new description: ");
    fgets(newDesc, sizeof(newDesc), stdin);
    newDesc[strcspn(newDesc, "\n")] = 0;

    while (fgets(line, sizeof(line), file)) 
    {
        char itemCode[MAX_CHAR], itemDesc[5 * MAX_CHAR];
        float price;

        sscanf(line, "%[^,],%[^,],%f", itemCode, itemDesc, &price);

        if (strcmp(itemCode, code) == 0) 
        {
            fprintf(temp, "%s,%s,%.2f\n", itemCode, newDesc, price);
            found = 1;
        } 
        
        else 
        {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);
    remove("./Main/menu.csv");
    rename("./Main/temp.csv", "./Main/menu.csv");

    if (found)
        printf("\n\tDescription updated successfully.\n");
    else
        printf("\n\tItem code not found.\n");
}

void updatePrice() 
{
    FILE *file = fopen("./Main/menu.csv", "r");
    FILE *temp = fopen("./Main/temp.csv", "w");
    if (!file || !temp) 
    {
        printf("\n\tError opening file.\n");
        return;
    }

    char code[MAX_CHAR];
    float newPrice;
    char line[256];
    int found = 0;

    printf("\n\tEnter item code to update price: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = 0;

    printf("\tEnter new price: ");
    scanf("%f", &newPrice);
    while (getchar() != '\n');

    while (fgets(line, sizeof(line), file)) 
    {
        char itemCode[MAX_CHAR], itemDesc[5 * MAX_CHAR];
        float price;

        sscanf(line, "%[^,],%[^,],%f", itemCode, itemDesc, &price);

        if (strcmp(itemCode, code) == 0) 
        {
            fprintf(temp, "%s,%s,%.2f\n", itemCode, itemDesc, newPrice);
            found = 1;
        } 
        
        else 
        {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);
    remove("./Main/menu.csv");
    rename("./Main/temp.csv", "./Main/menu.csv");

    if (found)
        printf("\n\tPrice updated successfully.\n");
    else
        printf("\n\tItem code not found.\n");
}

int invalid_msg(char * inv_msg)
{
    char resp;
    printf("%s\n| [A] Continue | [B] Exit\n", inv_msg);

    scanf("%c", &resp);
    while (getchar() != '\n');

    resp = tolower(resp);

    if (resp == 'a')
    {
        return 0;
    }

    else if (resp == 'b')
    {
        return 1;
    }

    else
    {
        return invalid_msg(inv_msg);
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "../interactive.h"
#include "../order.h"
#include "../display.h"

int order(char * ordr_msg, table * customer, FILE * menu, char * inv_msg)
{
    char resp;
    int orders = 0;
    
    customer->billT = 0;
    char code[MAX_CHAR];
    char name[MAX_CHAR];
    char temp[MAX_CHAR];
    float price;

    int i;
    for (i = 0; i < MAX_ORDR; i++)
    {
        system("cls");
        displayMenu();
        if (i != 0)
        {
            printf("| Order/s:\n");
            for (int j = 0; j < i; j++)
            {
                printf("| %s | P%.2f | %d |\n", customer->Items[j].name, 
                                                customer->Items[j].price, 
                                                customer->Items[j].qnt);
            } 
        }

        // Prompt Item Code
        printf("|\n");
        printf("|-------------------------------------------%s-------------------------------------------\n| Input Item Code: ", ordr_msg);        
        scanf("%s", customer->Items[i].code);
        while (getchar() != '\n');
        printf("|-------------------------------------------------------------------------------------------------\n");

        // Check if Item code exists 
        int flag = 0;
        rewind(menu);

        while (fgets(temp, MAX_CHAR, menu))
        {
            temp[strcspn(temp, "\n")] = '\0';

            int match = sscanf(temp, " %[^,],%[^,],%f", code, name, &price);
            // If the match format is incorrect
            if (match != 3) 
            { 
                continue;
            }       
            
            // Item exists
            if (strcmp(customer->Items[i].code, code) == 0)
            {
                strcpy(customer->Items[i].code, code);
                strcpy(customer->Items[i].name, name);
                customer->Items[i].price = price;

                // Item found
                flag = 1;
                printf("| Order | %s | P%.2f |\n", customer->Items[i].name, customer->Items[i].price);

                // Prompt for quantity
                printf("| Quantity: ");
                scanf("%d", &customer->Items[i].qnt);
                while (getchar() != '\n');

                printf("| Order/s:\n| %s | P%.2f | %d |\n", customer->Items[i].name, 
                                                          customer->Items[i].price, 
                                                          customer->Items[i].qnt);

                customer->Items[i].total = customer->Items[i].qnt * (float) customer->Items[i].price;
                customer->billT = customer->billT + customer->Items[i].total;
                orders = orders + customer->Items[i].qnt;

                customer->discount = 0;
                customer->tendered = 0;
                customer->change = 0;
            } 
        }

        if (flag == 1)
        {
            do 
            {
                printf("| Order again?\n| [Y] | [N]: ");
                scanf(" %c", &resp);
                while (getchar() != '\n');

                resp = tolower(resp);
                if (resp != 'y' && resp != 'n') 
                {
                // exit if user chooses to exit
                    if (invalid_msg(inv_msg)) 
                    return -1; 
                }
            }
            while (resp != 'y' && resp != 'n');

            if (resp == 'n')
            {
                char ans;
                
                system("cls");
                printf("| Order/s:\n");
                for (int j = 0; j < i + 1; j++)
                {
                    printf("| %s | P%.2f | %d | %.2f |\n", customer->Items[j].name, 
                                                        customer->Items[j].price, 
                                                        customer->Items[j].qnt,
                                                        customer->Items[j].total);
                } 

                printf("| Amount to pay: P%.2f\n", customer->billT);
                printf("| Proceed with your order?\n| [Y] | [N]: ");
                scanf(" %c", &ans);
                while(getchar() != '\n');

                ans = tolower(ans);
                if (ans == 'y')
                {
                    // Next customer please!
                    system("cls");
                    printf("| Order Valid!\n");
                    usleep(999999);
                    return i + 1;
                }

                else
                {
                    system("cls");
                    return -1;
                }
            }

            else if (resp == 'y' && i == MAX_ORDR - 1)
            {
                printf("| Order Limit Reached!");
                return i + 1;
            }

            else if (resp == 'y')
            {
                system("cls");
            }
        }

        if (flag == 0)
        {  
            printf("| Order not found!\n");
            i--;
            continue;  
        }
       
    }

    return i; 
}

void billingSummary(table *customer)
{
    int senior = 0, pwd = 0;
    float discount = 0;

    // Get current month
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int month = tm.tm_mon + 1; // tm_mon: 0-11

    // Month-based 2% discount
    if ((month == 5 || month == 6) && customer->billT >= 500 && customer->billT <= 2000)
    {
        discount += 0.02 * customer->billT;
        printf("| 2%% discount applied for May/June promotion.\n");
    }

    // Ask for Senior or PWD
    char stat;
    printf("| Are you a [S]enior, [P]WD, or [N]one? ");
    scanf(" %c", &stat);
    stat = tolower(stat);

    if (stat == 's')
    {
        discount += 0.20 * customer->billT;
        printf("| 20%% Senior Citizen discount applied.\n");
    }
    else if (stat == 'p')
    {
        discount += 0.05 * customer->billT;
        printf("| 5%% PWD discount applied.\n");
    }
    printf("| Discount: %.2f\n", discount);
    // Compute Net Bill
    customer->discount = discount;
    customer->billN = customer->billT - discount;
    printf("| Net Bill: P%.2f\n", customer->billN);

    // Tendering
    float tmp;

    printf("| Amount Tendered: ");
    scanf("%f", &customer->tendered);    
    while(getchar() != '\n');
    do
    {
        tmp = 0;
        if (customer->tendered < customer->billN)
        {
            printf("| Insufficient Fund. Please add more.\n");
            printf("| Amount Tendered: ");
            scanf("%f", &tmp);
            while(getchar() != '\n');
        }
        customer->tendered = customer->tendered + tmp;
    }
    while (customer->tendered < customer->billN);

    customer->change = customer->tendered - customer->billN;
    printf("| Change: P%.2f\n", customer->change);
}

void record(table * customer, FILE * client_rec, int quantity)
{
    fprintf(client_rec, "| Customer#: %d\n", customer->num);
    fprintf(client_rec, "| Discount: %.2f\n", customer->discount);
    fprintf(client_rec, "| Orders Code     | Order Price | Quantity |\n");

    for (int i = 0; i < quantity - 1; i++)
    {
        fprintf(client_rec, "| %-13s | %-11.2f | %8d |\n", customer->Items[i].code,
                                                           customer->Items[i].price,
                                                           customer->Items[i].qnt);
    }
    fprintf(client_rec, "|-----------------------------------\n");
    fprintf(client_rec, "| Bill Total: %.2f |\n", customer->billT);
    fprintf(client_rec, "| Tendered:   %.2f |\n", customer->tendered);
    fprintf(client_rec, "| Change:     %.2f |\n", customer->change);
    fprintf(client_rec, "|-----------------------------------\n");
    fprintf(client_rec, "| SUMMARY | TOTAL: %.4f |\n\n", customer->billT);
}
// Create a billing statement for JOLLY - JIP RESTAURANT
// 1. Using structure within structures array of structure passing to function BILLING, 
//      write a program to generate the above output.
// 2. Menu maybe classified by
//          
//         a. Package type
//             1. Solo Package - Solo Pack#1 or Solo Pack#2
//             2. Barkada Package - Barkada Package#1 or Barkada Package#2
//             3. Family Package - Family Package#1 or Family package#2

//         b. Individual Order(s) – provide individual menu

// 3. Ask the customer if he/she wants to place another order, 
//      if yes, let the customer choose another order(s) from the menu. 
//      Otherwise, proceed to item #4.

// 4. Compute for the following:
    // a. Amount = Quantity * Unit price
    // b. Total bill = sum of individual amount.
    // c. Discount:
        // a. 2 % discount if the Total Bill is between 
        // 500.00 – 2,000.00 for the month of MAY, we celebrate “Mother’s Day” 
        // while for the month of June, we celebrate “Independence Day” AND

        // b. 20% discount of the Total Bill for Senior Citizen OR

        // c. 5 % discount of the Total Bill for Person with Disability (PWD)

    // d. Net bill = Total bill – Discount
    // e. Change = Amount Tendered – Net bill
    // f. if amount tendered is less than the Net Bill, prompt “Insufficient Fund” and Ask for another amount to be tendered until full payment of billing.

// 5. Repeat the process as often as desired.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CUSTOMERS 1000
#define MAX_ORDERS 50
#define MAX_MENU 9

// Declare Structures
typedef struct
{
    int code;
    float quantity;
} order;

typedef struct
{
    int code;
    char * name;
    float price;
} menu;

typedef struct
{
    float amount;
    float total;
    float net;
    float change;
    float payment;
    float discount;
} bill;

typedef struct
{
    int order_count;
    order order[MAX_ORDERS];
    bill Bill;
} customer;

// Menu 
menu Menu[] = {
    {101, "Hotdog", 100.00},
    {102, "Cheesedog", 200.00},
    {103, "Hotdigididdy1", 6900.00},
    {201, "Sisig Barkada", 100.00},
    {202, "Pizza Barkada", 200.00},
    {203, "Hotdigididdy2", 6900.00},
    {301, "Sisig Familia", 100.00},
    {302, "Pizza Familia", 200.00},
    {303, "Hotdigididdy3", 6900.00}
};

// Record of customers
customer Customers[MAX_CUSTOMERS];

// Functions
int AskOrder(char * prompt, int number);
int BILLING(int number);
void print_menu();
float discountPrint(int number);
void print_billing_statement(int number);

int main ()
{
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        print_menu();
        
        // Ask the Customer if he/she wants to place an order
        if(AskOrder("Hello! What would you like to order?\n", i) == 1)
        {
            printf("Customer Cancelled\n");
            system("cls");
            continue;
        }

        else
        {
            // Compute [BILLING]
            BILLING(i); 
            printf("Next customer!\n");
        }
    }
}

int AskOrder(char * prompt, int number)
{
    int i;
    printf("%s", prompt);
    Customers[number].Bill.amount = 0;
    Customers[number].order[i].quantity = 0;
    Customers[number].order_count = 0;

    for (i = 0; i < MAX_ORDERS; i++)
    {
        int index;

        printf("[Enter '0': Done | Enter '1': Exit]\nEnter Order code: ");
        scanf("%d", &Customers[number].order[i].code); 

        if (Customers[number].order[i].code == 1) // Customer cancelled
        {
            Customers[number].order_count = 0;
            return 1;
        }

        else if (Customers[number].order[i].code == 0) // Customer is done
        {
            if (i == 0)
            {
                printf("No Orders Found!\n");
                system("cls");
                return 1;
            }

            return 0;
        }

        else // Check if order code exists
        {
            int check = 1;

            for (int j = 0; j < MAX_MENU; j++) 
            {
                if (Customers[number].order[i].code == Menu[j].code) // Order found
                {   
                    printf("Enter Order Quantity: ");
                    scanf("%f", &Customers[number].order[i].quantity); 

                    Customers[number].order_count++;
                    index = j;
                    check = 0;
                }
            }

            if (check == 1)
            {
                printf("Order Code Not Found!\n");
                i--;
                continue;
            }

            printf("You have successfully ordered %.0f %s!\n", Customers[number].order[i].quantity, Menu[index].name);
        }
    }
    return 0;
}

int BILLING(int number)
{
    // a. Amount = Quantity * Unit price
    for (int i = 0; i < Customers[number].order_count; i++)
    {
        for (int j = 0; j < MAX_MENU; j++)
        {
            if (Menu[j].code == Customers[number].order[i].code)
            {
                Customers[number].Bill.amount = Customers[number].Bill.amount + (Customers[number].order[i].quantity * Menu[j].price);               
            }
        }
    }

    // Total bill = sum of individual amount.
    Customers[number].Bill.discount = discountPrint(number);
    Customers[number].Bill.net = Customers[number].Bill.amount - (Customers[number].Bill.discount * Customers[number].Bill.amount);

    printf("| Total bill: %.2f\n", Customers[number].Bill.amount); 
    printf("| Discount: %.2f\n", Customers[number].Bill.discount); 
    printf("| Net Bill: %.2f\n", Customers[number].Bill.net);

    
    printf("| Received: ");
    scanf("%f", &Customers[number].Bill.payment); 

    while (Customers[number].Bill.payment < Customers[number].Bill.net)
    {
        printf("| Insufficient funds!\n");
        printf("| Received: ");
        scanf("%f", &Customers[number].Bill.payment);
    }

    Customers[number].Bill.change = Customers[number].Bill.payment - Customers[number].Bill.net;
    printf("| Change: %.2f\n", Customers[number].Bill.change);

    return 0;
}

void print_menu()
{
    const char *title = "JOLLY - JIP RESTAURANT MENU";
    int width = 39; // total width of the table including borders

    // Center title
    int pad = (width - (int)strlen(title)) / 2;
    printf("\n%*s%s\n\n", pad, "", title);

    // Table border top
    printf("+-------+---------------------------+---------+\n");

    // Header row with centered text
    printf("| %-5s | %-25s | %-7s |\n", "Code", "Item", "Price");

    // Header bottom border
    printf("+-------+---------------------------+---------+\n");

    // Solo Packages
    printf("|       | %-25s |         |\n", "-- Solo Packages --");
    for (int i = 0; i < 3; i++) {
        printf("| %5d | %-25s | P%7.2f |\n", Menu[i].code, Menu[i].name, Menu[i].price);
    }
    printf("+-------+---------------------------+---------+\n");

    // Barkada Packages
    printf("|       | %-25s |         |\n", "-- Barkada Packages --");
    for (int i = 3; i < 6; i++) {
        printf("| %5d | %-25s | P%7.2f |\n", Menu[i].code, Menu[i].name, Menu[i].price);
    }
    printf("+-------+---------------------------+---------+\n");

    // Family Packages
    printf("|       | %-25s |         |\n", "-- Family Packages --");
    for (int i = 6; i < 9; i++) {
        printf("| %5d | %-25s | P%7.2f |\n", Menu[i].code, Menu[i].name, Menu[i].price);
    }

    // Table bottom border
    printf("+-------+---------------------------+---------+\n");
}

float discountPrint(int number)
{
    char response;
    float discount;
    printf("| Are you a:\n| a.) Senior Citizen\n| b.) Person with Disability (PWD)\n| c.) None of the Above\n| Answer: ");
    scanf(" %c", &response);

    response = tolower(response);

    if (response == 'a')
    {   
       return 0.2;
    }   

    else if (response == 'b')
    {
        return 0.05;
    }
    else if (response == 'c')
    {
        if (Customers[number].Bill.amount < 2000.00 && Customers[number].Bill.amount > 500)
        {
            return 0.02;
        }

        return 0.00;
    }

    else
    {
        discountPrint(number);
    }
}

void print_billing_statement(int number) {
    printf("\n--- BILLING STATEMENT ---\n");
    printf("+-------+---------------------------+----------+------------+\n");
    printf("| Code  | Item                      | Quantity |   Amount   |\n");
    printf("+-------+---------------------------+----------+------------+\n");

    for (int i = 0; i < Customers[number].order_count; i++) {
        int code = Customers[number].order[i].code;
        float qty = Customers[number].order[i].quantity;
        // Find menu index
        int idx = -1;
        for (int j = 0; j < MAX_MENU; j++) {
            if (Menu[j].code == code) {
                idx = j;
                break;
            }
        }
        if (idx != -1) {
            float amt = qty * Menu[idx].price;
            printf("| %5d | %-25s | %8.0f | P%10.2f |\n", code, Menu[idx].name, qty, amt);
        }
    }
    printf("+-------+---------------------------+----------+------------+\n");
    printf("|                          Total Amount: | P%10.2f |\n", Customers[number].Bill.amount);
    printf("|                         Discount (%%): | %9.2f%% |\n", Customers[number].Bill.discount * 100);
    printf("|                             Net Bill: | P%10.2f |\n", Customers[number].Bill.net);
    printf("|                          Payment Given: | P%10.2f |\n", Customers[number].Bill.payment);
    printf("|                                Change: | P%10.2f |\n", Customers[number].Bill.change);
    printf("+----------------------------------------+------------+\n");
}
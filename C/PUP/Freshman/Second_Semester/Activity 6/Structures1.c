#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT 3
#define MAX_CUSTOMER 100
// Declare Structure
typedef struct 
{
    char Prod_code[8];
    char ProductDes[30];
    float price;
    int quantity;
} Product;

typedef struct 
{
    char CustomerName[100];
    char Cust_Address[100];
    Product product[MAX_PRODUCT];
} Customer;

void RECORD(int num);
float KOMPUTE(int num, float amount[]);
void RECEIPT(int num, float totalbilling, float amount[]);

Customer customer[MAX_CUSTOMER];

int main ()
{
    float amount[MAX_PRODUCT];
    int i = 0; char cont;
    while (i < MAX_CUSTOMER)
    {
        RECORD(i);
        float total = KOMPUTE(i, amount);
        RECEIPT(i, total, amount);

        printf("\nDo you want to enter another customer? (Y/N): ");
        scanf(" %c", &cont); // Space before %c skips leftover newline
        while (getchar() != '\n'); // Clear the buffer after char input

        if (cont == 'N' || cont == 'n')
            break;

        i++;
    }

}

void RECORD(int num)
{
    printf("Enter Customer Name: ");
    fgets(customer[num].CustomerName, sizeof(char) * 100, stdin);
    customer[num].CustomerName[strcspn(customer[num].CustomerName, "\n")] = '\0';

    printf("Enter Customer Address: ");
    fgets(customer[num].Cust_Address, sizeof(char) * 100, stdin);
    customer[num].Cust_Address[strcspn(customer[num].Cust_Address, "\n")] = '\0';

    int i;
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        printf("Enter product code: ");
        fgets(customer[num].product[i].Prod_code, sizeof(char) * 9, stdin);
        customer[num].product[i].Prod_code[strcspn(customer[num].product[i].Prod_code, "\n")] = '\0';

        printf("Enter product description: ");
        fgets(customer[num].product[i].ProductDes, sizeof(char) * 30, stdin);
        customer[num].product[i].ProductDes[strcspn(customer[num].product[i].ProductDes, "\n")] = '\0';

        printf("Enter unit price: ");
        scanf("%f", &customer[num].product[i].price);
        while (getchar() != '\n');

        printf("Enter number quantity: ");
        scanf("%d", &customer[num].product[i].quantity);
        while (getchar() != '\n');
    }
}

float KOMPUTE(int num, float amount[])
{
    float totalbilling = 0.0;
    int i;
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        amount[i] = customer[num].product[i].price * customer[num].product[i].quantity;
        totalbilling = totalbilling + amount[i];
    }
    return totalbilling;
}

void RECEIPT(int num, float totalbilling, float amount[])
{
    int i;
    printf("Receipt for Customer: %s\n", customer[num].CustomerName);
    printf("Customer Address: %s\n", customer[num].Cust_Address);

    printf("Product Code    Product Description     Unit Price      Quantity        Amount\n");
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        printf("%s    %s     %f      %d     %f\n", customer[num].product[i].Prod_code, customer[num].product[i].ProductDes, customer[num].product[i].price, customer[num].product[i].quantity, amount[i]);
    }

    printf("Total Billing: %f", totalbilling);
}
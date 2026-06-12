#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCT 3
#define MAX_CUSTOMER 10

typedef struct 
{
    char Prod_code[10];
    char Prod_Des[30];
    float price;
    int quant;
} Product;

typedef struct 
{   
    char CustomerName[30];
    char Cust_Address[30];
    Product product[MAX_PRODUCT];
} Customer;

void RECORD(Customer * customer);
float KOMPUTE(Customer * customer, float amount[]);
void RECEIPT(Customer * customer, float amount[], float total);

Customer customer[MAX_CUSTOMER];

int main ()
{
    float amount[MAX_PRODUCT];
    for (int i = 0; i < MAX_CUSTOMER; i++)
    {
        RECORD(&customer[i]);
        float total = KOMPUTE(&customer[i], amount);
        RECEIPT(&customer[i], amount, total);
    }
    
}

void RECORD(Customer * customer)
{
    printf("Enter Customer Name: ");
    fgets(customer->CustomerName, sizeof(char) * 30, stdin);
    customer->CustomerName[strcspn(customer->CustomerName, "\n")] = '\0';

    printf("Enter Customer Address: ");
    fgets(customer->Cust_Address, sizeof(char) * 30, stdin);
    customer->Cust_Address[strcspn(customer->Cust_Address, "\n")] = '\0';

    for (int i = 0; i < MAX_PRODUCT; i++)
    {
        printf("Enter product code: ");
        fgets(customer->product[i].Prod_code, sizeof(char) * 10, stdin);
        customer->product[i].Prod_code[strcspn(customer->product[i].Prod_code, "\n")] = '\0';

        printf("Enter product description: ");
        fgets(customer->product[i].Prod_Des, sizeof(char) * 30, stdin);
        customer->product[i].Prod_Des[strcspn(customer->product[i].Prod_Des, "\n")] = '\0';

        printf("Enter unit price: ");
        scanf("%f", &customer->product[i].price);
        while(getchar() != '\n');

        printf("Enter quantity: ");
        scanf("%d", &customer->product[i].quant);
        while(getchar() != '\n');
    }
}

float KOMPUTE(Customer * customer, float amount[])
{
    float total = 0;

    for (int i = 0; i < MAX_PRODUCT; i++)
    {
        amount[i] = customer->product[i].price * customer->product[i].quant;
        total = total + amount[i];        
    }

    return total;
}

void RECEIPT(Customer * customer, float amount[], float total)
{
    printf("Receipt for Customer: %s\n", customer->CustomerName);
    printf("Customer Address: %s\n", customer->Cust_Address);

    printf("Product code        Product Description         Unit Price          Quantity            Amount\n");
    for (int j = 0; j < MAX_PRODUCT; j++)
    {
        printf("    %s              %s                  %f              %d              %f\n", customer->product[j].Prod_code, customer->product[j].Prod_Des, customer->product[j].price, customer->product[j].quant, amount[j]);
    }

    printf("Total Bill: %f\n", total);
}
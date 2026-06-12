#include <stdio.h>
#include <string.h>

#define MAX_ID 10
#define MAX_C 1000
#define rental 12

typedef struct
{
    char ID[MAX_ID];
    float tIn;
    float tOut;
} com;

typedef struct
{
    float time;
    float fee;
    com computer;
} customer;

customer Customer[MAX_C];

void input(customer * Customer);
void compute(customer * Customer);
void store(customer * Customer, int num);  

FILE * data;
int main ()
{
    data = fopen("database.csv", "w+");

    fprintf(data, "| Customer# | Computer ID |\t tIn \t|\t tOut \t|\t Time \t| Payment |\n");

    for (int i = 0; i < MAX_C; i++)
    {
        input(&Customer[i]);
        compute(&Customer[i]); 
        store(&Customer[i], i + 1);  
    }

    fclose(data);
}

void input(customer * Customer)
{
    printf("Computer ID: ");
    fgets(Customer->computer.ID, (MAX_ID + 1) * sizeof(char), stdin);
    Customer->computer.ID[strcspn(Customer->computer.ID, "\n")] = '\0';

    printf("Time In: ");
    scanf("%f", &Customer->computer.tIn);
    while (getchar() != '\n');

    printf("Time Out: ");
    scanf("%f", &Customer->computer.tOut);
    while (getchar() != '\n');
}

void compute(customer * Customer)
{
// Find number of hours spent

    // Convert the tIn and tOut into normal hours
    if (Customer->computer.tIn >= Customer->computer.tOut)
    {
        // Add 24 to tOut
        Customer->computer.tOut = Customer->computer.tOut + 2400;
    }

    Customer->time = Customer->computer.tOut - Customer->computer.tIn;

    // Convert into military time
    Customer->time = Customer->time / 100;
    printf("Time Spent: %.2f hours\n", Customer->time);

    Customer->fee = Customer->time * rental;

    // Compute ampunt to be paid
    printf("Amount to pay: PhP %.2f\n", Customer->fee);
}

void store(customer * Customer, int num)
{
    fprintf(data, "|\t %d \t\t| %s |\t %.0f \t|\t %.0f \t|\t %.2f \t|\tPhP %.2f \t|\n", num, Customer->computer.ID, Customer->computer.tIn, Customer->computer.tOut, Customer->time, Customer->fee);
}
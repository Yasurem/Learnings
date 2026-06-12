#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/*
This project was created by Computer programming (CS 1-1N) Group 3
Group 3 members: 
    Castillo, Joemarc Jr. D.
    Evaristo, Yeshaya Gabriel I.
    Cabale, Johnry S.
*/ 
 

int FIBO();

void MILITARY_TIME();

int main() {
    int confirm, yn;
    do {
        char select;

        printf("\n|-------------------------------------------------------|\n");
        printf("|\t\t Final Requirements [1st Sem]\t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("|\t\t Select Exercise Demo\t\t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("|\t\t Rabbit Exercise | Press A\t\t|\n");
        printf("|\t\t Military Time   | Press B\t\t|\n");
        printf("|\t\t Exit Program\t | Press C\t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("|                                                       |\n| Answer: ");

        while (scanf(" %c", &select) != 1 || (select != 'A' && select != 'a' && select != 'B' && select != 'b' && select != 'C' && select != 'c')) 
        {
            printf("| Invalid input! Please enter A, B, or C: ");
            while (getchar() != '\n');
        }
    
        printf("|                                                       |\n");

        if (select == 'A' || select == 'a') 
        {
            printf("|-------------------------------------------------------|\n");
            printf("|\t\t Rabbit Exercise \t\t\t|\n");
            printf("|-------------------------------------------------------|\n");
            yn = FIBO();
            
        } 
        else if (select == 'B' || select == 'b') 
        {
            MILITARY_TIME();
        } 
        
        else if (select == 'C' || select == 'c') 
        {
            return 0;
        }

        printf("| Repeat menu?  Yes (1) | No (0): ");

        while (scanf("%d", &confirm) != 1 || (confirm != 0 && confirm != 1)) 
        {
            printf("| Invalid input! Enter 1 to repeat or 0 to exit: ");
            while (getchar() != '\n');
        }
    } 
    while (confirm == 1);

    return 0;
}

int FIBO() {
    int RABBIT[12], i;
    int Total_Rabbits = 0; 
    RABBIT[0] = 1;
    RABBIT[1] = 1;

    for (i = 2; i < 12; i++)
    {
        RABBIT[i] = RABBIT[i - 1] + RABBIT[i - 2];
        Total_Rabbits = Total_Rabbits + RABBIT[i];
    }

    for (i = 0; i < 12; i++)
    {
        printf("|\t Month %d \t|\t %d Rabbit Pairs \t|\n", i + 1, RABBIT[i]);
    }

    printf("|-------------------------------------------------------|\n");
    
    return 0;
}

void MILITARY_TIME() 
{
    int confirm; 
    int militaryTime;

    do
    {
        printf("|-------------------------------------------------------|\n");
        printf("|\t\t Military Time Exercise \t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("| Input time in military format: ");
        scanf("%d", &militaryTime);

        int hour, minute;
        char notation;

        hour = militaryTime / 100;
        minute = militaryTime % 100;
    
        if (hour < 0 || hour > 24 || minute < 0 || minute > 59) {
            printf("| Output: INVALID TIME \t\t\t|\n");
            return;
        }

        if (hour == 0 || hour == 24) 
        {
            hour = 12;
            notation = 'A';
        }

        else if (hour < 12) 
        {
            notation = 'A';
        } 

        else if (hour == 12) 
        {
            notation = 'P';
        } 

        else 
        {
            hour -= 12;
            notation = 'P';
        }
        printf("|                                                       |\n");
        printf("|                                                       |\n");
        printf("|\t\t Output: %d:%02d %cM \t\t\t|\n", hour, minute, notation);
        printf("|                                                       |\n");  
        printf("|-------------------------------------------------------|\n");
        printf("| Repeat? \t\t Yes (1) | No (0) \t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("| Answer: ");
        while (scanf("%d", &confirm) != 1 || (confirm != 0 && confirm != 1)) 
        {
            printf("| Invalid input! Enter 1 to repeat or 0 to exit: ");
            while (getchar() != '\n');
        }
    } 
    while (confirm == 1);
    
    
}
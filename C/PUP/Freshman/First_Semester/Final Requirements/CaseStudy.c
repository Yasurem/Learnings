#include <stdio.h>

// This project was created by Computer programming (CS 1-1N) Group 3
// RABBITTTT
int fibonacci();

// TIMERIMST
void convertTime(int militaryTime);

int main() {
    int confirm, yn;
    do {
        char select;

        printf("\n|-------------------------------------------------------|\n");
        printf("|\t\t Final Requirements [1st Sem]\t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("|\t\t Select Exercise Demo\t\t\t|\n");
        printf("|-------------------------------------------------------|\n");
        printf("|\t\t Rabit Exercise  | Press A\t\t|\n");
        printf("|\t\t Military Time   | Press B\t\t|\n");
        printf("|\t\t Exit Program\t | Press C\t\t|\n");
        printf("|-------------------------------------------------------|\n| Answer: ");

        while (scanf(" %c", &select) != 1 || (select != 'A' && select != 'a' && select != 'B' && select != 'b' && select != 'C' && select != 'c')) {
            printf("| Invalid input! Please enter A, B, or C: ");
            while (getchar() != '\n');
        }
        
        printf("|-------------------------------------------------------|\n");

        if (select == 'A' || select == 'a') {
            yn = fibonacci(yn);
        } else if (select == 'B' || select == 'b') {
            int militaryTime;
            printf("| Input time in military format: ");
            scanf("%d", &militaryTime);
            convertTime(militaryTime);
        } else if (select == 'C' || select == 'c') {
            return 0;
        }

        printf("| Repeat menu? Yes (1) | No (0): ");
        while (scanf("%d", &confirm) != 1 || (confirm != 0 && confirm != 1)) {
            printf("| Invalid input! Enter 1 to repeat or 0 to exit: ");
            while (getchar() != '\n');
        }
    } while (confirm == 1);

    return 0;
}

int fibonacci() {
    int RABBIT[12], i;
    int Total_Rabbits = 0; 
    RABBIT[0] = 1;
    RABBIT[1] = 1;

    for (i = 2; i < 12; i++)
    {
        RABBIT[i] = RABBIT[i - 1] + RABBIT[i - 2];
    }

    for (i = 0; i < 12; i++)
    {
        Total_Rabbits = Total_Rabbits + RABBIT[i];
        printf("|\t Month %d \t|\t %d Rabbit Pairs \t|\n", i + 1, RABBIT[i]);
    }

    printf("|-----------------------|-------------------------------|\n");
    printf("|     One year later    |\t %d total rabbits\t|\n\n", Total_Rabbits);
    printf("|-----------------------|-------------------------------|\n");
    
    return 0;
}

void convertTime(int militaryTime) {
    int hour, minute;

    hour = militaryTime / 100;
    minute = militaryTime % 100;
    
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("| Output: INVALID TIME \t\t\t|\n");
        return;
    }

    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }
    
    printf("| Output: %d:%02d%s\n", hour, minute, (hour < 12) ? " PM" : " AM");
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int access();

int palindrome();

int main (void)
{
    // Execute Access
    if(access() != 0)
    {
        printf("Get tf outta here!");
        return 1;
    }

    palindrome();
}

int access()
{
    char user[100], password[100];
    char def_user[] = "Group3";
    char def_password[] = "g3@2025";
    char ch, confirm;
    int flag = 0;

    int try = 3;

    // Ask for the Username
    do
    {
        confirm = '0';
        printf("Username: ");
        scanf(" %[^\n]", user);

        if (strcmp(user, def_user) != 0)
        {
            printf("User does not exist. Try again?  | Y | n |\nAnswer: ");
            scanf(" %c", &confirm);

            if (confirm == 'n' || confirm == 'N')
            {
                return -1;
            }

            else if (confirm == 'y' || confirm == 'Y')
            {
                system("cls");
            }

            else
            {
                printf("Invalid input!");
                while (getchar() != '\n');
                printf("Answer: ");
            }
        }   
    } 
    while(confirm == 'y' || confirm == 'Y');

    // Ask for the Password 
    int i = 0;

    do
    {
        printf("Password: ");
        while (1) 
        {
            ch = getch();

            if (ch == '\r') 
            {
                password[i] = '\0';
                break;
            } 
        
            else if (ch == '\b' && i > 0) 
            {
                i--;
                printf("\b \b");
            } 
        
            else if (i < sizeof(password) - 1 && ch != '\b') 
            {
                password[i++] = ch;
                printf("*");
            }
        }
        printf("\n\n");

        if (strcmp(password, def_password) == 0)
        {
            printf("Correct Password!");
            return 0;
            break;
        }

        else
        {
            printf("Incorrect password!\nAttempts left: %d\nTry again? | Y | n |\n\nAnswer: ", try - 1);
            scanf(" %c", &confirm);

            if (confirm == 'n' || confirm == 'N')
            {
                return -1;
            }

            else if (confirm == 'y' || confirm == 'Y')
            {
                try--;
                system("cls");
            }

            else
            {
                printf("Invalid input! Again: ");
                while (getchar() != '\n');
            }    
        } 

        if (try <= 0)
        {
            printf("No more attempts left! ");
            return 1;
        }
    } 
    while(try > 0 && flag != 1);
}

int palindrome()
{
    system("cls");
    char userIn[100];
    int len;
    int i, j;

    printf("Palindrome Checker\n\nInput: ");
    scanf(" %[^\n]", userIn);

    len = strlen(userIn);

    for (i = 0; i < len / 2; i++)
    {
        if (userIn[i] != userIn[len - i - 1])
        {
            printf("Not a palindrome!");
            return 1;
        }

        else
        {
            printf("Palindrome Identified!");
            return 0;
        }
    }
}

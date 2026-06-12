#include <stdio.h>
#include <stdlib.h>

#define menu_sz 5;
#define name_sz 15;


modify_menu();

int main ()
{
    // Main Menu
    //      *Welcome to JollyBot!*
    //
    //      Menu file in use: [menu.csv]
    //
    //      a.) UseMenu(): A menu already exists
    //                  - Ask the user the file name then open the file for viewing
    //                      i.)   Use the menu (read) then initialize customer service
    //                      ii.)  Modify the current menu (write)
    //                      iii.) Add a dish to the menu (append) - addDish Function
    //                      iv.)  Go back (return to main Menu)
    //
    //      b.) Create a new menu
    //                      i.)   Ask the user the file name then create the file
    //                      ii.)  Add a dish to the menu (append) - AddDish Function
    //                      iii.) UseMenu(): Ask the user to confirm if he wants to modify the menu he created
    //      
    //      Initialize order_sys()
    FILE * menu = fopen("menu.csv", "a+");
    printf("Enter Menu: ");

    char * dish_name = malloc(10 * sizeof(char));
    int price;

    for (int i = 0; i < menu_sz; i++); 
    {
        printf("[Dish no. %d]: ", i + 1);
        fgets(dish_name, name_sz, stdin);
        dish_name[strcspn(dish_name, "\n")] = '\0';

        printf("Input price: ");
        scanf("%f", &price);

        // Input the dish to the menu.csv
        fprintf(menu, "[10%d] | %s, P%d\n", i + 1, dish_name, price);
    }
    
    printf("Menu: ");
    for (int i = 0; i < menu_sz; i++)
    {
        fscanf();
    }
}
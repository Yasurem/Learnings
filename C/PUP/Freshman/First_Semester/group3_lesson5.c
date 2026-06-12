#include <math.h>
#include <stdio.h>
#include <ctype.h>

// Array exercise 1
int array_exe1(int yn);
int EVEN(int BSIT[]);

// Array exercise 2
int array_exe2(int yn);
int REVERSE(int X[], int Y[], int N);

// Array exercise 3
int array_exe3(int yn);
void array_multiply(int X[], int Y[], int Z[], int N);
void array_sum_sqroot(int N, int Z[]);

// Array exercuse 4
int array_exe4(int yn);
void add_pairs(int initial[], int final[], int n);

// Array exercise 5
int array_exe5(int yn);
int score_sys(int score[]);
float score_ave(int results);

// Main Menu
int main() {
    int confirm, yn;
    do {
        int select;

        printf("\n|-----------------------------------------------|\n");
        printf("|\t\tARRAY EXERCISES\t\t\t|\n");
        printf("|-----------------------------------------------|\n");
        printf("|\t\tSelect Exercise Demo\t\t|\n");
        printf("|-----------------------------------------------|\n");
        printf("|\t(5 - 1) Array Exercise 1 | Press 1\t|\n");
        printf("|\t(5 - 2) Array Exercise 2 | Press 2\t|\n");
        printf("|\t(5 - 3) Array Exercise 3 | Press 3\t|\n");
        printf("|\t(5 - 4) Array Exercise 4 | Press 4\t|\n");
        printf("|\t(5 - 5) Array Exercise 5 | Press 5\t|\n");
        printf("|\t\tExit Program\t | Press 0\t|\n");
        printf("|-----------------------------------------------|\n| Answer: ");

        while (scanf("%d", &select) != 1 || select < 0 || select > 5) {
            printf("| Invalid input! Please enter a number between 0 and 5: ");
            while (getchar() != '\n');
        }

        printf("|-----------------------------------------------|\n");

        if (select == 1) {
            yn = array_exe1(yn);
        } else if (select == 2) {
            yn = array_exe2(yn);
        } else if (select == 3) {
            yn = array_exe3(yn);
        } else if (select == 4) {
            yn = array_exe4(yn);
        } else if (select == 5) {
            yn = array_exe5(yn);
        } else if (select == 0) {
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

// Array Exercise 1
int array_exe1(int yn) {
    do {
        int BSIT[20], i, ESum;

        for (i = 0; i < 20; i++) {
            printf("| Input value %d: ", i + 1);

            while (scanf("%d", &BSIT[i]) != 1) {
                printf("| Invalid input! Enter a number: ");
                while (getchar() != '\n');
            }
        }

        ESum = EVEN(BSIT);

        printf("|---------------------------------------------------------------------------------------------|\n");
        printf("| Array BSIT: |");
        for (i = 0; i < 20; i++) {
            printf(" %d |", BSIT[i]);
        }

        printf("\n| Sum (Even Index): %d\n", ESum);
        printf("|---------------------------------------------------------------------------------------------|\n");

        printf("| Repeat - Enter 0 | Exit - Enter 1 |\n");
        printf("| Answer: ");
        scanf("%d", &yn);
        printf("\n\n");
    } while (yn == 0);
    return yn;
}

int EVEN(int BSIT[]) {
    int ESum = 0;
    for (int i = 0; i < 20; i += 2) {
        ESum += BSIT[i];
    }
    return ESum;
}


// Array Exercise 2
int array_exe2(int yn)
{
    do
    {
        int N;
        printf("| Set Value Quantity: ");
        while (scanf("%d", &N) != 1 || N <= 0) {
            printf("| Invalid input! Enter a positive number: ");
            while (getchar() != '\n');
        }

        int X[N], Y[N], i;

        for (i = 0; i < N; i++)
        {
            printf("| Value %d: ", i + 1);
            scanf("%d", &X[i]);
        }

        REVERSE(X, Y, N);

        printf("|------------------------------------------------\n");
        printf("| Reverse:");

        for (i = 0; i < N; i++)
        {
            printf(" %d |", Y[i]);
        }

        printf("\n|-----------------------------------------------|\n| Repeat - Enter 0 | Exit - Enter 1 |\n");
        printf("| Answer: ");
        scanf("%d", &yn);
        printf("|-----------------------------------------------|\n");
    }
    while (yn == 0);
    return yn;
}

int REVERSE(int X[],  int Y[], int N)
{
    int i, j;
    for (i = N - 1, j = 0; i >= 0; i--, j++)
    {
        Y[j] = X[i];
    } 
}

// Array Exercise 3
int array_exe3(int yn)
{
    do
    {
        int N = 20, i;
        int X[20], Y[20], Z[20];

        // Ask the user the quantity of values
        printf("| Set Value Quantity (Up to 20): ");
        while (scanf("%d", &N) != 1 || N <= 0 || N > 20) 
        {
            printf("| Invalid input! Enter a positive number (1-20): ");
            while (getchar() != '\n');
        }
    
        // Ask user to input 20 X Values
        for (i = 0; i < N; i++) 
        {
            printf("| Input X Value #%d: ", i + 1);
            while (scanf("%d", &X[i]) != 1) 
            {
                printf("| Invalid input! Enter a number: ");
                while (getchar() != '\n');
            }
        }

        printf("|-------------------------------------------------\n");

        // Ask user to input 20 Y Values
        for (i = 0; i < N; i++) {
            printf("| Input Y Value #%d: ", i + 1);
            while (scanf("%d", &Y[i]) != 1) 
            {
                printf("| Invalid input! Enter a number: ");
                while (getchar() != '\n');
            }
        }

        array_multiply(X, Y, Z, N);

        printf("|-------------------------------------------------\n");
        printf("| The Products are:\n");
        for (i = 0; i < N; i++)
        {
            printf("|\t\t\t%d * %d = %d\t\t|\n",  X[i], Y[i], Z[i]);
        }
    
        array_sum_sqroot(N, Z);

        printf("|-------------------------------------------------\n");
        printf("| Repeat - Enter 0 | Exit - Enter 1 |\n");
        printf("| Answer: ");
        scanf("%d", &yn);
    }
    while (yn == 0);
    return yn;
}

void array_multiply(int X[], int Y[], int Z[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        Z[i] = Y[i] * X[i];
    }
}

void array_sum_sqroot(int N, int Z[])
{
    int i, sum = 0;
    float result;

    for (i = 0; i < N; i++)
    {
        sum = sum + Z[i];
    }

    result = sqrt(sum);
    printf("| Square root: %.2f\n", result);
}

// Array Exercise 4
int array_exe4(int yn)
{
    do
    {
        const int n = 10;
        int initial[n], final[n - 1];
        int i;

        printf("| Enter eleven numbers: ");
        for (i = 0; i <= n; i++) {
            printf("| Input #%d: ", i + 1);
            while (scanf("%d", &initial[i]) != 1) {
                printf("| Invalid input! Enter a number: ");
                while (getchar() != '\n');
            }
        }

        add_pairs(initial, final, n);

        printf("|----------------------------------------------------------------------------------------------|\n");
        printf("| Sum (Every succeeding pair): ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", final[i]);
        }

        printf("\n|----------------------------------------------------------------------------------------------|\n");
        printf("| Repeat - Enter 0 | Exit - Enter 1 |\n");
        while (scanf("%d", &yn) != 1 || (yn != 0 && yn != 1)) {
            printf("| Invalid input! Enter 0 to repeat or 1 to exit: ");
            while (getchar() != '\n');
        }
    }
    while (yn == 0);
    return yn;
}

void add_pairs(int initial[], int final[], int n)
{
    int i;
    final[0] = 0; 
    for (i = 0; i < n + 1; i++)
    {
        final[i] = initial[i] + initial[i + 1];
    }
}

int array_exe5(int yn)
{
    do
    {
        char name[100];
        int score[5];
        int i;
        int results = 0;
        float average = 0; 

        printf("| Enter student name: ");
        scanf("%s", name);

        for (i = 0; i < 5; i++) {
            printf("| Enter Answer #%d: ", i + 1);
            while (scanf("%d", &score[i]) != 1) {
                printf("| Invalid input! Enter a valid numerical value: ");
                while (getchar() != '\n');
            }
        }

        results = score_sys(score);
        average = score_ave(results);

        printf("|-----------------------------------------------|\n");
        printf("| Score: %d\n| Average: %.2f\n", results, average);
        printf("|-----------------------------------------------|\n");

        printf("| Repeat - Enter 0 | Exit - Enter 1 |\n");
        printf("| Answer: ");
        while (scanf("%d", &yn) != 1 || (yn != 0 && yn != 1)) {
            printf("| Invalid input! Enter 0 to repeat or 1 to exit: ");
            while (getchar() != '\n');
        }
    }
    while (yn == 0);
    return yn;
}

int score_sys(int score[])
{
    int i;
    int results = 0;
    for (i = 0; i <= 5; i++)
    {
        if (score[i] < 0 || score[i] > 5)
        {
            score[i] = 0;
        }
        results = results + score[i];
    }
    return results;
}

float score_ave(int results)
{
    float average = 0;
    average = results / 5.0;
    return average;
}
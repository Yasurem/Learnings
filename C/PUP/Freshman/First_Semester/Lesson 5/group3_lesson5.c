#include <math.h>
#include <stdio.h>

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
int main()
{
    int confirm, yn;
    do
    {
        int i, select;
        printf("\n|-----------------------------------------------|\n");
        printf("|\t\tARRAY EXERCISES\t\t\t|\n");
        printf("|-----------------------------------------------|\n");
        printf("|\t\tSelect Exercise Demo\t\t|\n");
        printf("|-----------------------------------------------|\n");
        for (i = 1; i <= 5; i++)
        {
            printf("|\t(5 - %d) Array Exercise %d | Press %d\t|\n", i, i, i);
        }
        printf("|\t\tExit Program\t | Press 0\t|\n");
        printf("|-----------------------------------------------|\n| Answer: ");

        scanf("%d", &select);

        printf("|-----------------------------------------------|\n");

        if (select == 1)
        {
            yn = array_exe1(yn);
        }

        else if (select == 2)
        {
            yn = array_exe2(yn);
        }

        else if (select == 3)
        {
            yn = array_exe3(yn);
        }

        else if (select == 4)
        {
            yn = array_exe4(yn);
        }

        else if (select == 5)
        {
            yn = array_exe5(yn);
        }

        else if (select == 0)
        {
            return 0;
        }
        
        else
        {
            printf("| Invalid input! Exit program? Yes (1) | No (0) |\n| Answer: ");
            scanf("%d", &confirm);
            if (confirm == 1)
            {
                return 1;
            }
        }
    } 
    while (confirm == 0 || yn == 1);
}

// Array Exercise 1
int array_exe1(int yn)
{
    do
    {
        int BSIT[20], i, ESum;
    
        for (i = 0; i < 20; i++)
        {
            printf("| Input value %d: ", i + 1);
            scanf("%d", &BSIT[i]);
        }

        // Sum of all even indexes
        ESum = EVEN(BSIT);

        printf("|---------------------------------------------------------------------------------------------|\n");
        // Print array BSIT
        printf("| Array BSIT: |");
        for (i = 0; i < 20; i++)
        {
            printf(" %d |",  BSIT[i]);
        }

        // Print result
        printf("\n| Sum (Even Index): %d\n", ESum);
        printf("|---------------------------------------------------------------------------------------------|\n");

        // Repeat or Exit
        printf("| Repeat - Enter 0 | Exit - Enter 1 |\n");
        printf("| Answer: ");
        scanf("%d", &yn);
        printf("\n\n");
    } 
    while (yn == 0);
}

int EVEN(int BSIT[])
{
    int ESum = 0;
    int i;
    for (i = 1; i <= 20; i += 2)
    {
        ESum = ESum + BSIT[i];
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
        scanf("%d", &N);

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
        int N, i;
        int X[20], Y[20], Z[20];

        // Ask the user the quantity of values
        do
        {
            printf("| Set Value Quantity (Up to 20): ");
            scanf("%d", &N);
        } 
        while (N < 0 || N > 20);
    
        // Ask user to input 20 X Values
        for (i = 0; i < N; i++)
    {
        printf("| Input X Value #%d: ", i + 1);
        scanf("%d", &X[i]);
    }

        printf("|-------------------------------------------------\n");

        // Ask user to input 20 Y Values
        for (i = 0; i < N; i++)
        {
            printf("| Input Y Value #%d: ", i + 1);
            scanf("%d", &Y[i]);
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
        for (i = 0; i <= n; i++)
        {
            scanf("%d", &initial[i]);
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
        printf("| Answer: ");
        scanf("%d", &yn);
    }
    while (yn == 0);
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

        for (i = 0; i < 5; i++)
        {
            printf("| Enter Answer # %d? ", i + 1);
            scanf("%d", &score[i]);
        }

        results = score_sys(score);
        average = score_ave(results);

        printf("|-----------------------------------------------|\n");
        printf("| Score: %d\n| Average: %.2f\n", results, average);
        printf("|-----------------------------------------------|\n");

        printf("| Repeat - Enter 0 | Exit - Enter 1 |\n");
        printf("| Answer: ");
        scanf("%d", &yn);
    }
    while (yn == 0);
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
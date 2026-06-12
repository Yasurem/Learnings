#include <stdio.h>

int score_sys(int score[]);
float score_ave(int results);

int main()
{
    char name[100];
    int score[5];
    int i;
    int results = 0;
    float average = 0; 

    printf("Enter student name: ");
    scanf("%s", name);

    for (i = 0; i < 5; i++)
    {
        printf("Enter Answer # %d? ", i + 1);
        scanf("%d", &score[i]);
    }

    results = score_sys(score);
    average = score_ave(results);

    printf("Score: %d\nAverage: %.2f\n", results, average);
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
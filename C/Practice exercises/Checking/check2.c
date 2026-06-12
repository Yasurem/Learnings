#include <stdio.h>

int main (void)
{
    int i, j, row, column;
    printf("Row size: ");
    scanf("%d", &row);
    printf("Column size: ");
    scanf("%d", &column);

    int array_NICE[row][column], array_SQUARED[row][column];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &array_NICE[i][j]);
        }
    }

    printf("Array Nice: {\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("\t%d", array_NICE[i][j]);
            array_SQUARED[i][j] = array_NICE[i][j] * array_NICE[i][j];
        }
        printf("\n");
    }
    printf("}\n\nSquared: {\n");

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("\t%d", array_SQUARED[i][j]);
        }
    }
    printf("}");
    return 0;
}
#include <stdio.h>

typedef struct {
    unsigned row;
    unsigned col;
    int value;
} elem;

typedef struct {
    elem arr[100];
    unsigned no_of_rows;
    unsigned no_of_cols;
} matrix;

void inputMat(matrix* mat)
{
    printf("Enter number of rows : ");
    scanf("%u", &mat->no_of_rows);
    printf("Enter number of cols : ");
    scanf("%u", &mat->no_of_cols);

    // First element of array will contain :
    // no of distinct non zero row ; no of distinct non zero col ; no of non zero values
    mat->arr[0].row = 0;
    mat->arr[0].col = 0;
    mat->arr[0].value = 0;
    // Since no data has been provided upto this point so
    // initialsing with 0 values

    for (int i = 0, data = 0; i < mat->no_of_rows; ++i) {
        for (int j = 0; j < mat->no_of_cols; ++j) {
            printf("Enter element [%u][%u] : ", i + 1, j + 1);
            scanf("%d", &data);
            if (data) {
                mat->arr[0].value += 1;
                mat->arr[mat->arr[0].value].row = i + 1;
                mat->arr[mat->arr[0].value].col = j + 1;
                mat->arr[mat->arr[0].value].value = data;

                // Checking if adding to different row
                if (mat->arr[mat->arr[0].value - 1].row != i + 1) {
                    mat->arr[0].row += 1;
                }
                mat->arr[0].col += 1;
            }
        }
    }
}

void printMat(matrix* mat)
{
    printf("Distinct rows : %u\nDistinct cols : %u\n", mat->arr[0].row, mat->arr[0].col);
    for (int i = 1; i <= mat->arr[0].value; ++i) {
        printf("[%u][%u] : [%d]\n", mat->arr[i].row, mat->arr[i].col, mat->arr[i].value);
    }
}

int main()
{
    matrix mat1;

    inputMat(&mat1);

    unsigned rWiseColCount[100] = { 0 };
    unsigned rWiseCols[100][100] = { 0 };

    printMat(&mat1);
}
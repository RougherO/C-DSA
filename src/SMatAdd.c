#include <stdio.h>

typedef struct {
    int data;
    unsigned row;
    unsigned col;
} elem;

typedef struct {
    unsigned no_of_non_zero;
    unsigned no_of_rows;
    unsigned no_of_cols;
    elem arr[100];
} matrix;

void shift(elem* start, elem* end)
{
    for (; end > start; --end) {
        *end = *(end - 1);
    }
}

int main()
{
    matrix mat = { 0 }, mat_2 = { 0 }, mat_r = { 0 };
    mat.no_of_non_zero = 0;
    mat_2.no_of_non_zero = 0;

    printf("Enter number of rows : ");
    scanf("%u", &mat.no_of_rows);

    printf("Enter number of columns : ");
    scanf("%u", &mat.no_of_cols);

    for (int i = 0, data = 0; i < mat.no_of_rows; ++i) {
        for (int j = 0; j < mat.no_of_cols; ++j) {
            printf("Enter element [%u][%u] : ", i + 1, j + 1);
            scanf("%d", &data);
            if (data != 0) {
                mat.arr[mat.no_of_non_zero].data = data;
                mat.arr[mat.no_of_non_zero].row = i;
                mat.arr[mat.no_of_non_zero].col = j;
                ++mat.no_of_non_zero;
            }
        }
    }

    printf("Enter number of rows : ");
    scanf("%u", &mat_2.no_of_rows);

    printf("Enter number of columns : ");
    scanf("%u", &mat_2.no_of_cols);

    if (!(mat_2.no_of_cols == mat.no_of_cols && mat_2.no_of_rows == mat.no_of_rows)) {
        printf("Matrices cannot be added because of different dimension");
        return 1;
    }

    for (int i = 0, data = 0; i < mat_2.no_of_rows; ++i) {
        for (int j = 0; j < mat_2.no_of_cols; ++j) {
            printf("Enter element [%u][%u] : ", i + 1, j + 1);
            scanf("%d", &data);
            if (data != 0) {
                mat_2.arr[mat_2.no_of_non_zero].data = data;
                mat_2.arr[mat_2.no_of_non_zero].row = i;
                mat_2.arr[mat_2.no_of_non_zero].col = j;
                ++mat_2.no_of_non_zero;
            }
        }
    }

    // Without a third matrix
    for (int j = 0, i = 0; j < mat_2.no_of_non_zero; ++j) {
        for (; i < mat.no_of_non_zero && !(mat.arr[i].row == mat_2.arr[j].row && mat.arr[i].col == mat_2.arr[j].col); ++i)
            ;
        if (i != mat.no_of_non_zero) {
            mat.arr[i].data += mat_2.arr[j].data;
        } else {
            mat.arr[mat.no_of_non_zero++] = mat_2.arr[j];
        }
    }

    for (int i = 0; i < mat.no_of_non_zero; ++i) {
        printf("Element [%u][%u] : %d\n", mat.arr[i].row + 1, mat.arr[i].col + 1, mat.arr[i].data);
    }
    printf("\n");
}
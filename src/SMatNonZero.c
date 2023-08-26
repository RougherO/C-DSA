#include <stdio.h>

typedef struct elem {
    int data;
    int row;
    int col;
} elem;

typedef struct Matrix {
    elem arr[100];
    int numOfNonZero;
    int rows;
    int cols;
} Matrix;

int main()
{
    Matrix m1 = { 0 };

    printf("Enter num of rows of Matrix 1 : ");
    scanf("%d", &m1.rows);
    printf("Enter num of cols of Matrix 1 : ");
    scanf("%d", &m1.cols);

    for (int i = 0, ch = 'Y'; ch == 'Y' || ch == 'y'; ++i) {
        printf("Enter row index : ");
        scanf("%d", &m1.arr[i].row);
        printf("Enter col index : ");
        scanf("%d", &m1.arr[i].col);
        printf("Enter non zero value : ");
        scanf("%d", &m1.arr[i]);
        m1.numOfNonZero += 1;
        printf("Continue to Enter values [Y/n]: ");
        scanf("%*c%c", &ch);
    }

    // ) initialising count array
    int count[m1.rows];
    for (int i = 0; i < m1.rows; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < m1.numOfNonZero; ++i) {
        count[m1.arr[i].row] += 1;
    }

    for (int i = 0; i < m1.rows; ++i) {
        printf("Row [%d] : %d elements\n", i, count[i]);
    }
}
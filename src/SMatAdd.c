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
    Matrix m1 = { 0 }, m2 = { 0 }, m3 = { 0 };

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

    printf("Enter num of rows of Matrix 2 : ");
    scanf("%d", &m2.rows);
    printf("Enter num of cols of Matrix 2 : ");
    scanf("%d", &m2.cols);

    for (int i = 0, ch = 'Y'; ch == 'Y' || ch == 'y'; ++i) {
        printf("Enter row index : ");
        scanf("%d", &m2.arr[i].row);
        printf("Enter col index : ");
        scanf("%d", &m2.arr[i].col);
        printf("Enter non zero value : ");
        scanf("%d", &m2.arr[i]);
        m2.numOfNonZero += 1;
        printf("Continue to Enter values [Y/n]: ");
        scanf("%*c%c", &ch);
    }

    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        printf("Cannot add the matrices");
    }

    int i = 0, j = 0, k = 0;
    for (; i < m1.numOfNonZero && j < m2.numOfNonZero;) {
        if (m1.arr[i].row < m2.arr[j].row) {
            m3.arr[k++] = m1.arr[i++];
        } else if (m2.arr[j].row < m1.arr[i].row) {
            m3.arr[k++] = m2.arr[j++];
        } else if (m1.arr[i].col < m2.arr[j].col) {
            m3.arr[k++] = m1.arr[i++];
        } else if (m2.arr[j].col < m1.arr[i].col) {
            m3.arr[k++] = m2.arr[j++];
        } else {
            m3.arr[k].data = m1.arr[i].data + m2.arr[j].data;
            m3.arr[k].row = m1.arr[i].row;
            m3.arr[k].col = m1.arr[i].col;
            ++k, ++j, ++i;
        }
        m3.numOfNonZero += 1;
    }

    for (; i < m1.numOfNonZero; ++i) {
        m3.arr[k++] = m1.arr[i++];
        m3.numOfNonZero += 1;
    }

    for (; j < m2.numOfNonZero; ++j) {
        m3.arr[k++] = m2.arr[j++];
        m3.numOfNonZero += 1;
    }

    printf("Adding Two Matrices: \n");
    for (int i = 0; i < m3.numOfNonZero; ++i) {
        printf("[%d][%d] : %d\n", m3.arr[i].row, m3.arr[i].col, m3.arr[i].data);
    }
}
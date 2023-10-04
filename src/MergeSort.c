#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[size - 1]);
}

void merge(int* arr1, int size1, int* arr2, int size2)
{
    int* buffer = calloc(size1 + size2, sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        buffer[k++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
    }
    while (i < size1) {
        buffer[k++] = arr1[i++];
    }
    while (j < size2) {
        buffer[k++] = arr2[j++];
    }

    memcpy(arr1, buffer, size1 * sizeof(int));
    memcpy(arr2, buffer + size1, size2 * sizeof(int));
    free(buffer);
}

void mergeSort(int* arr, int size)
{
    if (size == 1 || size == 0) {
        return;
    }
    int mid = size / 2;
    mergeSort(arr, mid);
    mergeSort(arr + mid, size - mid);
    merge(arr, mid, arr + mid, size - mid);
}

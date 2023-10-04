#include <stdio.h>

void printArray(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[size - 1]);
}

void swap(int* val1, int* val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

void maxHeapify(int* arr, int size, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(arr + index, arr + largest);
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int* arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, size, i);
    }
}

void heapSort(int* arr, int size)
{
    buildMaxHeap(arr, size);
    printArray(arr, size);
    for (int i = size - 1; i > 0; --i) {
        swap(arr, arr + i);
        maxHeapify(arr, i, 0);
        printArray(arr, size);
    }
}

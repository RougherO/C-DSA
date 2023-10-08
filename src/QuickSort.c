#include <stdio.h>

void swap(int* val1, int* val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

int partition(int* arr, int start, int end)
{
    if (start == end)
        return start;
    int key = start;
    for (start += 1; start <= end;) {
        if (arr[start] >= arr[key]) {
            swap(arr + start, arr + end);
            end -= 1;
        } else {
            ++start;
        }
    }
    swap(arr + key, arr + end);
    return end;
}

void quickSort(int* arr, int start, int end)
{
    if (start >= end)
        return;
    int index = partition(arr, start, end);
    quickSort(arr, start, index - 1);
    quickSort(arr, index + 1, end);
}

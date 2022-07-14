#include <algorithm>
#include <iostream>

int partition(int arr[], int start, int end) {
  int pivot = arr[start];
  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot) {
      count++;
    }
  }

  int pivot_index = start + count;
  std::swap(arr[start], arr[pivot_index]);

  int i = start, j = end;
  while (i < pivot_index && j > pivot_index) {
    while (arr[i] <= arr[pivot_index]) {
      i++;
    }

    while (arr[j] > arr[pivot_index]) {
      j--;
    }

    if (i < pivot_index && j > pivot_index) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  return pivot_index;
}

void quick_sort(int arr[], int start, int end) {
  // base case
  if (start >= end) {
    return;
  }

  // partitioning the array
  int q = partition(arr, start, end);

  // sort the left part
  quick_sort(arr, start, q - 1);

  // sort the right part
  quick_sort(arr, q + 1, end);
}

int main() {
  int arr[] = {8, 6, 12, 7, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  quick_sort(arr, 0, size - 1);

  for (int i = 0; i < size; i++) {
    std::cout << i << std::endl;
  }
}
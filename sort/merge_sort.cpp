/*
https://www.programiz.com/dsa/merge-sort
*/

#include <iostream>

void merge(int arr[], int left, int middle, int right) {
  // create two separate arrays
  int size_1 = middle - left + 1;
  int size_2 = right - middle;

  int arr_1[size_1];
  int arr_2[size_2];

  for (int i = 0; i < size_1; i++) {
    arr_1[i] = arr[left + i];
  }

  for (int i = 0; i < size_2; i++) {
    arr_2[i] = arr[middle + 1 + i];
  }

  // Maintain current index of sub-arrays and main array
  int i = 0;
  int j = 0;
  int k = left;

  while (i < size_1 && j < size_2) {
    if (arr_1[i] <= arr_2[j]) {
      arr[k] = arr_1[i];
      i++;
    } else {
      arr[k] = arr_2[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < size_1) {
    arr[k] = arr_1[i];
    i++;
    k++;
  }

  while (j < size_2) {
    arr[k] = arr_2[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void divide(int arr[], int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    divide(arr, left, middle);
    divide(arr, middle + 1, right);
    merge(arr, left, middle, right);
  }
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  divide(arr, 0, size - 1);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
}

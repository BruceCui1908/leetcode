#include <iostream>

// [5,1,2,4,8]
void merge(int arr[], int left, int middle, int right) {
  // copy elements to array
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

  int i = 0;
  int j = 0;
  int k = left;

  while (i < size_1 && j < size_2) {
    if (arr_1[i] <= arr_2[j]) {
      arr[k++] = arr_1[i++];
    } else {
      arr[k++] = arr_2[j++];
    }
  }

  while (i < size_1) {
    arr[k++] = arr_1[i++];
  }

  while (j < size_2) {
    arr[k++] = arr_2[j++];
  }
}

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
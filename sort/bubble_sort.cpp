#include <algorithm>
#include <iostream>

void bubble_sort(int arr[], int size) {
  bool is_sorted = true;
  for (int i = 0; i < size - 1; i++) {
    // Last i elements are already in place
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] < arr[j + 1]) {
        is_sorted = false;
        std::swap(arr[j], arr[j + 1]);
      }
    }

    if (is_sorted) {
      break;
    }
  }
}

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
}

int main() {
  int arr[] = {5, 1, 4, 2, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Before:" << std::endl;
  print_arr(arr, size);
  bubble_sort(arr, size);
  std::cout << "After:" << std::endl;
  print_arr(arr, size);
}
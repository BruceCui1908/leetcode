#include <algorithm>
#include <iostream>

/*
https://www.youtube.com/watch?v=Hoixgm4-P4M

quick sort = pivot
1) pivot is corret position in final sorted array
2) items to the left are smaller
3) items to the right are larger

2 6 5 3 8 7 1 0
step:
1.pick a pivot
2.swap pivot with the end element
3.find left > than pivot
4.find right < than pivot
5.swap left with right
6.repeat 3~5 until left index > right index
7.swap left with pivot(at the end index) (pivot element is in right position)

how to choose pivot
divide the array in half

worst case O(n^2)
avg case O(nlogn)
*/

int partition(int arr[], int low, int high) {
  int left = low;
  int pivot = arr[high];

  for (int right = low; right < high; right++) {
    if (arr[right] < pivot) {
      std::swap(arr[left], arr[right]);
      left++;
    }
  }

  std::swap(arr[left], arr[high]);
  return left;
}

void quick_sort(int arr[], int low, int high) {
  if (high <= low) {
    return;
  }

  int p = partition(arr, low, high);
  quick_sort(arr, low, p - 1);
  quick_sort(arr, p + 1, high);
}

int main() {
  int arr[] = {5, 8, 1, 10, 8, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, size - 1);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}
/*
https://www.geeksforgeeks.org/heap-sort/

What is Binary Heap?
Let us first define a Complete Binary Tree. A complete binary tree is a binary
tree in which every level, except possibly the last, is completely filled, and
all nodes are as far left as possible

A Binary Heap is a Complete Binary Tree where items are stored in a special
order such that the value in a parent node is greater(or smaller) than the
values in its two children nodes. The former is called max heap and the latter
is called min-heap. The heap can be represented by a binary tree or array.

Why array based representation for Binary Heap?
Since a Binary Heap is a Complete Binary Tree, it can be easily represented as
an array and the array-based representation is space-efficient. If the parent
node is stored at index I, the left child can be calculated by 2 * I + 1 and the
right child by 2 * I + 2 (assuming the indexing starts at 0).
*/

#include <algorithm>
#include <iostream>

void heapify(int arr[], int size, int index) {
  // initialize largest as root
  int largest = index;

  int left = 2 * index + 1;
  int right = 2 * index + 2;

  // if left child is larger than the root
  if (left < size && arr[left] > arr[largest]) {
    largest = left;
  }

  // if right child is larger than the root
  if (right < size && arr[right] > arr[largest]) {
    largest = right;
  }

  // heapify until largest is the root
  if (largest != index) {
    std::swap(arr[index], arr[largest]);
    heapify(arr, size, largest);
  }
}

void heap_sort(int arr[], int size) {
  // Build heap (rearrange array)
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }

  /*
  simply delete the root element from the max heap.
  In order to delete this node, try to swap it with the last node.
  After removing the root element, again heapify it to convert it into max heap.
  */
  for (int i = size - 1; i > 0; i--) {
    // Move current root to end
    std::swap(arr[0], arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  heap_sort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << std::endl;
  }
}
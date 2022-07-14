#include <algorithm>
#include <vector>

class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    int heap_size = nums.size();
    build_max_heap(nums, heap_size);

    // [1,2,3,4,5,6,7,8] k=3 i=7 i>=6
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
      std::swap(nums[0], nums[i]);
      heap_size--;
      max_heapify(nums, 0, heap_size);
    }

    return nums[0];
  }

  void max_heapify(std::vector<int> &nums, int index, int heap_size) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap_size && nums[left] > nums[largest]) {
      largest = left;
    }

    if (right < heap_size && nums[right] > nums[largest]) {
      largest = right;
    }

    if (largest != index) {
      std::swap(nums[index], nums[largest]);
      max_heapify(nums, largest, heap_size);
    }
  }

  void build_max_heap(std::vector<int> &nums, int heap_size) {
    for (int i = heap_size / 2; i >= 0; i--) {
      max_heapify(nums, i, heap_size);
    }
  }
};
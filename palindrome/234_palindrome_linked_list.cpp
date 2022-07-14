
#include <vector>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next{next} {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    std::vector<int> vals;
    while (head != nullptr) {
      vals.emplace_back(head->val);
      head = head->next;
    }

    for (int i = 0, j = (int)vals.size() - 1; i < j; i++, j--) {
      if (vals[i] != vals[j]) {
        return false;
      }
    }

    return true;
  }
};

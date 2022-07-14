#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val{0}, next{nullptr} {}
  ListNode(int v) : val{v}, next{nullptr} {}
  ListNode(int x, ListNode *n) : val{x}, next{n} {}
};

// recursive
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    } else if (list2 == nullptr) {
      return list1;
    } else if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }
};

class Solution2 {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }

      prev = prev->next;
    }

    prev->next = list1 == nullptr ? list2 : list1;

    return dummy->next;
  }
};
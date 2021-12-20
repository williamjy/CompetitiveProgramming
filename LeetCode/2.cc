#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *start = nullptr, *end = nullptr;
    int a = 0, b = 0, carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry) {
      if (l1 != nullptr) {
        a = l1->val;
        l1 = l1 ->next;
      } else {
        a = 0;
      }
      if (l2 != nullptr) {
        b = l2->val;
        l2 = l2 ->next;
      } else {
        b = 0;
      }
      a += b;
      a+= carry;
      carry = a / 10;
      a %= 10;
      ListNode *newNode = new ListNode(a);
      if (start == nullptr) {
        start = newNode;
        end = newNode;
      } else {
        end->next = newNode;
        end = end->next;
      }
    }
    return start;
  }
};

int main () {
}
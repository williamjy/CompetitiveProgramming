#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *curr;
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        if (list1->val < list2->val) {
            curr = list1;
            list1 = list1->next;
        } else {
            curr = list2;
            list2 = list2->next;
        }
        head = curr;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 == nullptr) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        return head;
    }
};
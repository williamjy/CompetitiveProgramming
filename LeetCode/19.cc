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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *prev, *curr = head;
        for (; curr != nullptr; curr = curr->next, count++) {}
        if (count == n) return head->next;
        curr = head;
        count -= n;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};

int main() {
    ListNode *head;
    int i = 1;
    for (int j = 0; j < i; j++) {
        if (!j) head = new ListNode(i-j);
        else head = new ListNode(i-j,head);
    }
    Solution solution;
    head = solution.removeNthFromEnd(head,1);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
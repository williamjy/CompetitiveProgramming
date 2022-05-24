#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

// This solution has a high chance of timeout
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<stack<ListNode*>> intToStacks{20001,stack<ListNode*>{}};
        ListNode *curr = nullptr, *head = nullptr;
        int smallest = 20000;
        for (auto list : lists) {
            if (list != nullptr) {
                if (smallest >= list->val) {
                    smallest = list->val;
                    head = list;
                }
                intToStacks[list->val+10000].push(list);
            }
        }
        if (head == nullptr) return nullptr;
        if (intToStacks[smallest+10000].top()->next == nullptr) {
            intToStacks[smallest+10000].pop();
        } else {
            ListNode *smallestNode = intToStacks[smallest+10000].top()->next;
            intToStacks[smallest+10000].pop();
            intToStacks[smallestNode->val+10000].push(smallestNode);
        }
        curr = head;
        for (int i = 0; i <= 20000; i++) {
            while (!intToStacks[i].empty()) {
                ListNode *list = intToStacks[i].top();
                intToStacks[i].pop();
                curr->next = list;
                curr = curr->next;
                list = list->next;
                if (list != nullptr) {
                    intToStacks[list->val+10000].push(list);
                }
            }
        }
        return head;
    }
};
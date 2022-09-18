#include <set>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> node_queue(cmp);
        for (int i = 0; i < lists.size(); ++i) {
            while (lists[i] != nullptr) {
                node_queue.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        ListNode *head = nullptr, *curr = nullptr;
        while (!node_queue.empty()) {
            auto node = node_queue.top();
            node->next = nullptr;
            if (head == nullptr) {
                head = node;
                curr = node;
            } else {
                curr->next = node;
                curr = curr->next;
            }
            node_queue.pop();
        }
        return head;
    }
};
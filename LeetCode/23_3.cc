#include <set>
#include <map>
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
        auto cmp = [](const pair<int,int>& left, const pair<int,int>& right) {
            return left.first <= right.first;
        };
        set<pair<int,int>,decltype(cmp)> smallest(cmp);
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                smallest.insert(make_pair(lists[i]->val,i));
            }
        }
        ListNode *head = nullptr, *curr = nullptr;
        while (!smallest.empty()) {
            auto i = smallest.begin()->second;
            if (head == nullptr) {
                head = lists[i];
                curr = lists[i];
            } else {
                curr->next = lists[i];
                curr = curr->next;
            }
            smallest.erase(smallest.begin());
            lists[i] = lists[i]->next;
            if (lists[i] != nullptr) {
                smallest.insert(make_pair(lists[i]->val,i));
            }
        }
        return head;
    }
};
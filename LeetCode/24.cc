struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if (head ->next != nullptr) {
            head = head->next;
        }
        while (curr != nullptr) {
            ListNode *next1 = curr->next;
            if (next1 == nullptr) {
                break;
            }
            curr->next = next1->next;
            next1->next = curr;
            if (prev != nullptr) {
                prev->next = next1;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
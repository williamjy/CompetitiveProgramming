
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next ) {}
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* paddedHead = new ListNode(0, head);
        ListNode* preStart = paddedHead;
        while (preStart->next != nullptr)
        {
            ListNode* curr = preStart;
            for (int i = 0; i < k; ++i)
            {
                if (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                else
                {
                    return paddedHead->next;
                }
            }
            curr = preStart->next;
            for (int i = 0; i < k - 1; ++i)
            {
                ListNode *tmp = preStart->next;
                preStart->next = curr->next;
                curr->next = curr->next->next;
                preStart->next->next = tmp;
            }
            preStart = curr;
        }
        return paddedHead->next;
    }
};
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = nullptr;
        Node* prevCreated = nullptr;
        Node* curr = head;
        map<Node*,Node*> oldToNew;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            oldToNew[curr] = newNode;
            if (prevCreated == nullptr) {
                newHead = newNode;
                prevCreated = newNode;
            } else {
                prevCreated->next = newNode;
                prevCreated = prevCreated->next;
            }
            curr = curr->next;
        }
        curr = newHead;
        while (curr != nullptr) {
            if (head->random != nullptr) {
                curr->random = oldToNew[head->random];
            }
            head = head->next;
            curr = curr->next;
        }
        return newHead;
    }
};
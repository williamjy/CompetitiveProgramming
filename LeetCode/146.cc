#include <iostream>
#include <map>

using namespace std;

struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
    Node(): value(-1), prev(nullptr), next(nullptr) {};
    Node(int key, int value): key(key), value(value), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    int size;
    int capacity;
    map<int, Node*> keyToNode;
    Node *head;
    Node *tail;
    void push_back (Node *node) {
    }
public:
    LRUCache (int capacity) {
        this->size = 0;
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    Node *nextHead() {
        Node *oldHead = head;
        head = head->next;
        head->prev = nullptr;
        return oldHead;
    }

    void removeNode (Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertNode (Node *node) {
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
    }
    
    int get (int key) {
        Node *node = keyToNode[key];
        if (node == nullptr) {
            return -1;
        } else if (node == tail) {
            // dp nothing
        } else if (node == head) {
            insertNode(node);
            nextHead();
        } else {
            removeNode(node);
            insertNode(node);
        }
        node->next = nullptr;
        return node->value;
    }
    
    void put (int key, int value) {
        Node *node = keyToNode[key];
        if (node == nullptr) {
            node = new Node(key, value);
            if (size == 0) {
                head = node;
                tail = node;
                keyToNode[key] = node;
                size++;
            } else {
                insertNode(node);
                if (size == capacity) {
                    auto oldHead = nextHead();
                    if (oldHead != nullptr) {
                        keyToNode[oldHead->key] = nullptr;
                        delete head->prev;
                    }
                } else {
                    size++;
                }
            }
        } else {
            node->key = key;
            node->value = value;
            if (node == tail) {
                // nothing
            } else if (node == head) {
                insertNode(node);
                nextHead();
            } else {
                removeNode(node);
                insertNode(node);
            }
        }
        keyToNode[node->key] = node;
        node->next = nullptr;
    }
};

int main() {
    LRUCache lruCache{2};
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl;
    lruCache.put(3, 3);
    cout << lruCache.get(2) << endl;
    lruCache.put(4, 4);
    cout << lruCache.get(1) << endl;
    cout << lruCache.get(3) << endl;
    cout << lruCache.get(4) << endl;
}

// int main() {
//     LRUCache lruCache{2};
//     lruCache.put(1, 0);
//     lruCache.put(2, 2);
//     cout << lruCache.get(1) << endl;
//     lruCache.put(3, 3);
//     cout << lruCache.get(2) << endl;
//     lruCache.put(4, 4);
//     cout << lruCache.get(1) << endl;
//     cout << lruCache.get(3) << endl;
//     cout << lruCache.get(4) << endl;
// }

// int main() {
//     LRUCache lruCache{2};
//     lruCache.put(2, 1);
//     lruCache.put(3, 2);
//     cout << lruCache.get(3) << endl;
//     cout << lruCache.get(2) << endl;
//     lruCache.put(4, 3);
//     cout << lruCache.get(2) << endl;
//     cout << lruCache.get(3) << endl;
//     cout << lruCache.get(4) << endl;
// }

// int main() {
//     LRUCache lruCache{1};
//     lruCache.put(2, 1);
//     cout << lruCache.get(2) << endl;
//     lruCache.put(3, 2);
//     cout << lruCache.get(2) << endl;
//     cout << lruCache.get(3) << endl;
// }

// int main() {
//     LRUCache lruCache{2};
//     lruCache.put(2, 1);
//     lruCache.put(1, 1);
//     cout << lruCache.get(2) << endl;
//     lruCache.put(4, 1);
//     cout << lruCache.get(1) << endl;
//     cout << lruCache.get(2) << endl;
// }
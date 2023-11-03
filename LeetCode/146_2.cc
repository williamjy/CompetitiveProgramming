#include <map>

using namespace std;

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    int m_remainingSize;
    map<int, Node *> m_keyValueMap;
    Node *head;
    Node *tail;

    Node* remove(int key) {
        Node *node = m_keyValueMap.at(key);
        if (node == head && node == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (node == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else if (node == tail) {
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = nullptr;
        return node;
    }

    void insert(Node *node) {
        if (head == nullptr && tail == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

public:
    LRUCache(int capacity) {
        m_remainingSize = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        Node *node = nullptr;
        if (m_keyValueMap.find(key) != m_keyValueMap.end()) {
            node = remove(key);
            insert(node);
            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        Node *node = nullptr;
        if (m_keyValueMap.find(key) != m_keyValueMap.end()) {
            node = remove(key);
            node->value = value;
            insert(node);
        } else {
            node = new Node(key, value);
            insert(node);
            m_keyValueMap[key] = node;
            m_remainingSize--;
        }
        if (m_remainingSize < 0) {
            Node *removedNode = remove(head->key);
            m_keyValueMap.erase(removedNode->key);
            delete(removedNode);
            m_remainingSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
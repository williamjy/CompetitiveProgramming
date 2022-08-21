#include <iostream>
#include <memory>
#include <map>
using namespace std;

struct Node {
    int key;
    int value;
    int frequency;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;
    Node(): value(-1), prev(), next() {};
    Node(int key, int value): key{key}, value{value}, frequency{1}, prev(), next() {};
};
class LFUCache {
private:
    int total;
    int capacity;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    map<int, shared_ptr<Node>> keyToNode;
    map<int, shared_ptr<Node>> freqToNode;
public:
    LFUCache(int capacity): total{0}, capacity{capacity} {
    }
    int get(int key) {
        if (keyToNode[key] == nullptr) {
            return -1;
        }
        increaseFrequence(keyToNode[key]);
        return keyToNode[key]->value;
    }
    void put(int key, int value) {
        // Insert a node
        if (capacity == 0) {
            return;
        }
        auto node = keyToNode[key];
        if (node == nullptr) {
            node = make_shared<Node>(Node(key,value));
            if (total == capacity) {
                remove(head);
            } else {
                total++;
            }
            insert_after(freqToNode[1],node);
            keyToNode[key] = node;
            freqToNode[1] = node;
        } else {
            node->value = value;
            increaseFrequence(node);
        }
    }

    void increaseFrequence(shared_ptr<Node> node) {
        remove(node);
        ++node->frequency;
        if (freqToNode[node->frequency] != nullptr) {
            insert_after(freqToNode[node->frequency], node);
        } else if (freqToNode[node->frequency-1] != nullptr) {
            insert_after(freqToNode[node->frequency-1], node);
        } else {
            insert_after(node->prev, node);
        }
        keyToNode[node->key] = node;
        freqToNode[node->frequency] = node;
    }

    void insert_after(shared_ptr<Node> after, shared_ptr<Node> node) {
        if (after != nullptr) {
            node->next = after->next;
            after->next = node;
            if (node->next != nullptr) {
                node->next->prev = node;
            }
        } else if (head != nullptr) {
            node->next = head;
            head->prev = node;
        }
        node->prev = after;
        
        if (head == nullptr) {
            head = node;
        } else if (head->prev != nullptr) {
            head = head->prev;
        }
        if (tail == nullptr) {
            tail = head;
        } else if (tail->next != nullptr) {
            tail = tail->next;
        }
    }

    void remove (shared_ptr<Node> node) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        keyToNode.erase(node->key);
        if (freqToNode[node->frequency] == node) {
            freqToNode.erase(node->frequency);
            if (node->prev != nullptr and node->prev->frequency == node->frequency) {
                freqToNode[node->frequency] = node->prev; 
            }
        }
        if (head == node) {
            head = head->next;
        }
        if (tail == node) {
            tail = tail->prev;
        }
    }

    friend ostream& operator<<(ostream& os, LFUCache const& lfucache) {
        for (auto curr = lfucache.head; curr != nullptr; curr = curr->next) {
            os << "key: " << curr->key << " frequency: " << curr->frequency << endl;
        }
        return os;
    }
};

// int main() {
//     LFUCache lfu(9);
//     lfu.put(1,1);
//     lfu.put(2,2);
//     lfu.put(3,3);
//     lfu.put(4,4);
//     lfu.put(5,5);
//     lfu.put(6,6);
//     lfu.put(7,7);
//     lfu.put(8,8);
//     lfu.put(9,9);

//     lfu.get(4);
//     lfu.get(5);
//     lfu.get(6);
//     // lfu.get(4);
//     // lfu.get(5);
//     // lfu.get(6);

//     lfu.get(7);
//     lfu.get(8);
//     lfu.get(9);
//     lfu.get(7);
//     lfu.get(8);
//     lfu.get(9);
//     // lfu.get(7);
//     // lfu.get(8);
//     // lfu.get(9);
//     // lfu.get(7);
//     // lfu.get(8);
//     // lfu.get(9);

//     lfu.get(5);

//     cout << lfu;
// }

// int main() {
//     LFUCache lfu(10);
//     lfu.put(10,13);
//     lfu.put(3,17);
//     lfu.put(6,11);
//     lfu.put(10,5);
//     lfu.put(9,10);

//     lfu.get(13);
//     lfu.put(2,19);
//     lfu.get(2);
//     lfu.get(3);
//     lfu.put(5,25);
//     lfu.get(8);
//     lfu.put(9,22);
//     lfu.put(5,5);
//     lfu.put(1,30);
//     lfu.get(11);
//     lfu.put(9,12);
//     lfu.get(7);
//     lfu.get(5);
//     lfu.get(8);
//     lfu.get(9);
//     lfu.put(4,30);
//     lfu.put(9,3);
//     lfu.get(9);
//     lfu.get(10);
    
//     lfu.get(10);
    // lfu.put(6,14);
    // lfu.put(3,1);
    // lfu.get(3);
    // lfu.put(10,11);

    // lfu.get(8);
    // lfu.put(2,14);
    // lfu.get(1);
    // lfu.get(5);
    // lfu.get(4);
    // lfu.put(11,4);
    // lfu.put(12,24);
    // lfu.put(5,18);
    // lfu.get(13);
    // lfu.put(7,23);
    // lfu.get(8);
    // lfu.get(12);
    // lfu.put(3,27);
    // lfu.put(2,12);
    // lfu.get(5);
    // lfu.put(2,9);
    // lfu.put(13,4);
    // lfu.put(8,18);
    // lfu.put(1,7);
    // lfu.get(6);
    // lfu.put(9,29);
    // lfu.put(8,21);
    // lfu.get(5);
    // lfu.put(6,30);
    // lfu.put(1,12);
    // lfu.get(10);
    // lfu.put(4,15);
    // lfu.put(7,22);
    // lfu.put(11,26);
    // lfu.put(8,17);
    // lfu.put(9,29);
    // lfu.get(5);
    // lfu.put(3,4);
    // lfu.put(11,30);
    // lfu.get(12);
    // lfu.put(4,29);
    // lfu.get(3);
    // lfu.get(9);
    // lfu.get(6);
    // lfu.put(3,4);
    // lfu.get(1);
    // lfu.get(10);
    // lfu.put(3,29);
    // lfu.put(10,28);
    // lfu.put(1,20);
    // lfu.put(11,13);
    // lfu.get(3);
    // lfu.put(3,12);
    // lfu.put(3,8);
    // lfu.put(10,9);
    // lfu.put(3,26);
    // lfu.get(8);
    // lfu.get(7);
    // lfu.get(5);
    // lfu.put(13,17);
    // lfu.put(2,27);
    // lfu.put(11,15);
    // lfu.get(12);
    // lfu.put(9,19);
    // lfu.put(2,15);
    // lfu.put(3,16);
    // lfu.get(1);
    // lfu.put(12,17);
    // lfu.put(9,1);
    // lfu.put(6,19);
    // lfu.get(4);
    // lfu.get(5);
    // lfu.get(5);
    // lfu.put(8,1);
    // lfu.put(11,7);
    // lfu.put(5,2);
    // lfu.put(9,28);
    // lfu.get(1);
    // lfu.put(2,2);
    // lfu.put(7,4);
    // lfu.put(4,22);
    // lfu.put(7,24);
    // lfu.put(9,26);
    // lfu.put(13,28);
    // lfu.put(11,26);
    // cout << lfu;
// }

int main() {
    LFUCache lfu(2);
    lfu.put(1,1);
    lfu.put(2,2);
    lfu.get(2);
    lfu.get(2);
    lfu.get(2);
    lfu.put(3,3);
    lfu.get(3);
    // lfu.get(3);
    cout << lfu;
}
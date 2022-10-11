#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,std::greater<int>> right;
    MedianFinder() {
    }
    void addNum(int num) {
        if (left.empty() || num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        if (left.size() >= right.size() + 2) {
            right.push(left.top());
            left.pop();
        } else (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) {
            return (double) (left.top() + right.top()) / 2;
        } else {
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
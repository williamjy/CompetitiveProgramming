#include <map>

using namespace std;

class Logger {
private:
    map<string, int> cache;

public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (cache.find(message) != cache.end()) {
            if (timestamp < cache[message]) {
                return false;
            }
        }
        cache[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
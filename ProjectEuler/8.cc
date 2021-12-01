#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        int maximum = 0;
        for (int i = 0; i < n-k; i++) {
          string sub_num = num.substr(i,k);
          int to_num = stoi(sub_num);
          int total = 1;
          while (to_num >= 10) {
            total *= to_num % 10;
            to_num /= 10;
          }
          total *= to_num;
          maximum = (maximum > total) ? maximum : total;
        }
        cout << maximum << endl;
    }
    return 0;
}
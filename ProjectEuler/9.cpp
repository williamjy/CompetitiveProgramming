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
        cin >> n;
        if (n & 1) {
          cout << "-1" << endl;
          continue;
        }
        int a, b, c;
        long long maximum = -1;
        for (a = 1; a <= n/3; a++) {
          b = (n*n - 2*n*a)/2/(n-a);
          c = n - a - b;
          if (a*a + b*b == c*c) {
            maximum = (maximum > a*b*c) ? maximum : a*b*c;
          }
        }
        cout << maximum << endl;
    }
    return 0;
}
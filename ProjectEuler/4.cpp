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
        int a = max(n/100000,n%10);
        for (int i = a; i > 0; i--) {
          for (int j = 9; j >= 0; j--) {
            for (int k = 9; k >= 0; k--) {
              int s = i*100001+j*10010+k*1100;
              if (s >= n) continue;
              for (int m = 999; m >=100; m--) {
                if (s%m == 0 && s/m >= 100 && s/m < 1000) {
                  cout << s << endl;
                  i = 0;
                  j = -1;
                  k = -1;
                  break;
                }
              }
            }
          }
        }
    }
    return 0;
}
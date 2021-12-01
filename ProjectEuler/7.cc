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

int primes[200000];

int main(){
    int t;
    cin >> t;
    for (int i = 2; i < 200000; i++) {
      if (primes[i] == 1) continue;
      for (int j = 2 * i; j < 200000; j+=i) {
        primes[j] = 1;
      }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        for (int i = 2; i < 200000; i++) {
          if (primes[i] == 0) n--;
          if (n == 0) {
            cout << i << endl;
            break;
          }
        }
    }
    return 0;
}
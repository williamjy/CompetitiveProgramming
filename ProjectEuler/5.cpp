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

int primes[41] = {0};

int main(){
    int t;
    cin >> t;
    for (int i = 2; i <= 40; i++) {
      if (primes[i] != 0) continue;
      for (int j = 2 * i; j <= 40; j+=i) {
        primes[j] = 1;
      }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int num = 1;
        for (int i = 2; i <= n; i++) {
          if (primes[i] == 0) {
            int p = 0;
            while (pow(i,++p) <= n) {}
            num *= pow(i,p-1);
          }
        }
        cout << num << endl;
    }
    return 0;
}
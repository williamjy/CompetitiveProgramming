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

long primes[1000001] = {0};

int main(){
    int t;
    cin >> t;
    for (int i = 2; i < 1000001; i++) {
      if (primes[i] == 1) continue;
      for (int j = 2*i; j < 1000001; j += i) {
        primes[j] = 1;
      }
    }
    primes[0] = 0;
    primes[1] = 1;
    for (int i = 1; i < 1000001; i++) {
      primes[i] = (primes[i]) ? primes[i-1] : primes[i-1] + i;
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << primes[n] << endl;
    }
    return 0;
}
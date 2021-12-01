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
        long n;
        cin >> n;
        long sq = sqrt(n);
        while (n%2 == 0) {
            n/=2;
        }
        if (n== 1) {
          printf("2\n");
        } else {
          long p = 3;
          while (n != 1 && p <= sq) {
              if (n % p == 0) n/=p;
              else p+=2;
          }
          if (n == 1) printf("%ld\n", p);
          else printf("%ld\n", n);
        }
    }
    return 0;
}

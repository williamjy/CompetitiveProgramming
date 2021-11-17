#include <cmath>
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  map<long,long> prime_map;
  map<long,long> memo;
  long X;
  cin >> X;
  long n = 2;
  while (n) {
    if (memo[n] >= X) break;
    //cout << "n: " << n << endl;
    if (memo[n] == 0) {
      long n_sqr = n*n;
      for (long i = 1; i <=n;i++) {
        if (n_sqr%i == 0) memo[n]++;
      }
    }
    if (memo[n] >= X) break;
    n++;
  }
  cout << n << endl;
}
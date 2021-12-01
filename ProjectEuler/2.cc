#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long memo[96];

void fibo() {
  memo[0] = 1;
  memo[1] = 2;
  int i = 2;
  for (int i = 2; i < 96; i++) {
    memo[i] = memo[i-2]+memo[i-1];
  }
}

int main() {
  int t;
  long n;
  cin >> t;
  fibo();
  while (t--) {
    cin >> n;
    long sum = 0;
    int i = 0;
    while (memo[i] < n && i < 93) {
      if (!(memo[i] & 1)) sum+= memo[i];
      i++;
    }
    cout << sum << endl;
  }
  return 0;
}

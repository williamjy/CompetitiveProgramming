#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int getNumFactors(int n) {
  int div = 2, total = 1;
  while (n % div == 0) {
    n /= div;
    total++;
  }
  div++;
  while (n > 1) {
    int cnt = 1;
    while (n % div == 0) {
      n /= div;
      cnt++;
    }
    total *= cnt;
    div += 2;
  }
  return total;
}

int getSmallest(int input) {
  static map<int,int> stack;
  static int curr = 1;
  static int tri = 1;

  if (stack.count(input)) return stack[input];

  while (1) {
    int sum = tri*(tri+1)/2;
    int factors = getNumFactors(sum);
    while (curr < factors) {
      stack[curr++] = sum;
    }
    tri++;
    if (factors > input) break;
  }
  return stack[input];
}

int main() {
  int t , n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << getSmallest(n) << endl;
  }
}
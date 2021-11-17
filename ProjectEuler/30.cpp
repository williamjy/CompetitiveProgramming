#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int digit_pow(int i, int n) {
  if (i < 10) return pow(i,n);
  return pow(i%10,n)+digit_pow(i/10,n);
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int up = pow(9,n)*(n+1);
    for (int i = 2; i<=up; i++) {
      if (i == digit_pow(i,n)) sum+=i;
    }
    cout << sum << endl;
    return 0;
}

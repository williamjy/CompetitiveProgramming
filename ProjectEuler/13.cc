#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int list[2000000];

int main() {
  int n;
  cin >> n;
  string s[n];

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int carry = 0;
  for (int i = 49; i >= 10; i--) {
    for (int j = 0; j < n; j++) {
      carry += s[j][i] - '0';
    }
    carry /= 10;
  }

  long total = 0;
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      carry += s[j][i] - '0';
    }
    total += (carry % 10) * pow(10,9-i);
    carry /= 10;
  }
  total += carry * pow(10,10);
  
  int length = 0;
  long copy = total;
  while (copy > 0) {
    copy /= 10;
    length++;
  }
  while (length > 10) {
    total/=10;
    length--;
  }
  cout << total << endl;
  return 0;
}

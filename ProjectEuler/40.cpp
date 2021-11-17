#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long iList[7];

long power(long n) {
  if (n == 0) return 1;
  return 10*power(n-1);
}

long getDigit(long i) {
  long j = 0;
  while (i >0) {
    i-=(9*power(j) * (j+1));
    j++;
  }
  i+=(9*power(j-1) * j);
  i-=1;
  long num = power(j-1)+ i/j;
  long p = i % j;
  long q = num / power(j-1-p);
  return (q) % 10;
}

int main() {
  long t;
  cin >> t;
  while (t--) {
    long result=1;
    for (long i = 0; i <7; i++) {
      if (i == 6) scanf("%ld",&iList[i]);
      else scanf("%ld ",&iList[i]);
      int a = getDigit(iList[i]);
      //cout << a << endl;
      result *= a;
    }
    cout << result << endl;
  }
  return 0;
}
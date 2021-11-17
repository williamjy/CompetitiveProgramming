#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial_meo[100000];
int g_meo[100000];

int factorial (int n) {
  if (n == 0) return 1;
  if (factorial_meo[n]!=0) return factorial_meo[n];
  factorial_meo[n] = n*factorial(n-1);
  return factorial_meo[n];
}

int f(int n) {
  if (n<10) return factorial(n);
  return factorial(n%10)+f(floor(n/10));
}

int s(int n) {
  if (n<10) return n;
  return n%10+s(n/10);
}

int g(int i) {
  if (g_meo[i]!=0) return g_meo[i];
  int n = 1;
  while (n) {
    if (s(f(n)) == i) {
      g_meo[i]=n;
      return n;
    }
    n++;
  }
  return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    int n;
    int m;
    scanf("%d",&q);
    for (int i = 0; i < q; i++) {
      scanf("%d %d",&n,&m);
      int output = 0;
      for (int j = 1; j <= n; j++) {
        cout << j << endl;
        output += s(g(j));
      }
      cout << output << endl;
    }
    return 0;
}
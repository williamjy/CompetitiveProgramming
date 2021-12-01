#include <bits/stdc++.h>
using namespace std;

int res[5000];

int main() {
    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        int size = 1;
        int carry = 0;
        res[0]=1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j<size;j++) {
                int tmp = res[j] * i + carry;
                res[j] = tmp % 10;
                carry = tmp/10;
            }
            while (carry) {
                res[size] = carry % 10;
                carry /= 10;
                size++;
            }
        }
        int sum=0;
        for (int i = 0; i < size; i++) {
            sum+=res[i];
        }
        cout << sum << endl;
    }
}
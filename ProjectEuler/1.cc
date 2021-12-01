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
        long a = (n-1)/3;
        long b = (n-1)/5;
        long c = (n-1)/15;
        long sum = (3*a*(a+1) + 5*b*(b+1)-15*c*(c+1)) >> 1;
        cout << sum << endl;
    }
    return 0;
}

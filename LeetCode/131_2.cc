#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<vector<bool>> memo;
  vector<vector<string>> result;
  vector<string>stack;
public:
  vector<vector<string>> partition(string s) {
    initializeMemo(s);
    rec(0,s);
    return result;
  }
  void rec(int start, string s) {
    if (start == s.size()) result.push_back(stack);
    for (int i = start+1; i <= s.size(); i++) {
      if (memo[start][i-1]) {
        stack.push_back(s.substr(start,i-start));
        rec(i,s);
        stack.pop_back();
      }
    }
  }
  void initializeMemo(string s) {
    memo = vector<vector<bool>> (s.size()+1,vector<bool>(s.size(),0));
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j <= min(i-0,(int) s.size()-i-1); j++) {
        if (!j) {
          memo[i][i] = 1;
        } else {
          memo[i-j][i+j] = memo[i-j+1][i+j-1] && s[i-j] == s[i+j];
        }
      }
    }
    for (int i = 0; i < s.size()-1; i++) {
      for (int j = 0; j <= min(i-0,(int) s.size()-i-2); j++) {
        if (!j) {
          memo[i][i+1] = s[i] == s[i+1];
        } else {
          memo[i-j][i+j+1] = memo[i-j+1][i+j] && s[i-j] == s[i+j+1];
        }
      }
    }
  }
};

// reference
// https://leetcode.com/problems/palindrome-partitioning/discuss/41963/Java%3A-Backtracking-solution.
// public class Solution {
//         List<List<String>> resultLst;
// 	    ArrayList<String> currLst;
// 	    public List<List<String>> partition(String s) {
// 	        resultLst = new ArrayList<List<String>>();
// 	        currLst = new ArrayList<String>();
// 	        backTrack(s,0);
// 	        return resultLst;
// 	    }
// 	    public void backTrack(String s, int l){
// 	        if(currLst.size()>0 //the initial str could be palindrome
// 	            && l>=s.length()){
// 	                List<String> r = (ArrayList<String>) currLst.clone();
// 	                resultLst.add(r);
// 	        }
// 	        for(int i=l;i<s.length();i++){
// 	            if(isPalindrome(s,l,i)){
// 	                if(l==i)
// 	                    currLst.add(Character.toString(s.charAt(i)));
// 	                else
// 	                    currLst.add(s.substring(l,i+1));
// 	                backTrack(s,i+1);
// 	                currLst.remove(currLst.size()-1);
// 	            }
// 	        }
// 	    }
// 	    public boolean isPalindrome(String str, int l, int r){
// 	        if(l==r) return true;
// 	        while(l<r){
// 	            if(str.charAt(l)!=str.charAt(r)) return false;
// 	            l++;r--;
// 	        }
// 	        return true;
// 	    }
// }

int main () {
  Solution solution;
  string s = "aab";
  for (auto a : solution.partition(s)) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
}
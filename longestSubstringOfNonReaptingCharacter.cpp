#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int logestSubstr(string s){
    // set<char> st;
    // int i = 0, j = 0, maxLen = 0;
    
    // while(j<s.size()){
    //     while(st.count(s[j])){
    //         st.erase(s[i]);
    //         i++;
    //     }
    //     maxLen = max(maxLen, j - i + 1);
    //     st.insert(s[j]);
    //     j++;
    // }
    
    int maxLen = 0, i = 0; 
    unordered_map<char, int> m;
    for(int j = 0; j<s.size(); j++){
        if(m.count(s[j]) && m[s[j]] >= i){
            i = m[s[j]] + 1;
            cout << i << endl;
            // cout << s[j] << " " << m[s[j]] << endl;
        }
        m[s[j]] = j;
        maxLen = max(maxLen, j - i + 1);
    }
    return maxLen;
}
int main() {
  string s = "abcasabbc";
  cout << logestSubstr(s) << endl;

    return 0;
}

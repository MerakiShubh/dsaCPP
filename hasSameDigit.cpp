#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s){
    
    while(s.size() > 2){
        string temp = "";
        for(int i = 0; i<s.size() - 1; i++){
            int d1 = s[i] - '0';
            int d2 = s[i + 1] - '0';
            int val = (d1 + d2) % 10;
            temp.push_back(val + '0');
        }
        s = temp;
    }
    
    if(s.size() == 2 && s[0] == s[1]) return true;
    
    return false;
}


int main() {
    string s = "34789";
    
   cout << hasSameDigits(s) << endl;
    return 0;
}

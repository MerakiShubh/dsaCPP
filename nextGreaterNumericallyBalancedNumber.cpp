#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(int val){
    vector<int> freq(10, 0);
    
    string str = to_string(val);
    
    for(char ch : str){
        freq[ch - '0']++;
        if(ch == '0') return false;
    }
    
    for(int i = 1; i<=9; i++){
        if(freq[i] > 0 && freq[i] != i){
            return false;
        }
    }
    
    return true;
}


int  nextBeautifulNumber(int n) {
    const int maxVal = 1224444;
    
    for(int i = n+1; i<=maxVal; i++){
        if(check(i)){
            return i;
        }
    }
    
    return -1;
}
int main() {
  cout <<  nextBeautifulNumber(12344) << endl;

    return 0;
}

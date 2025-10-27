#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank) {
    
    int prev;    
    int count = 0;
    int prevCount = 0;

    for(int i = 0; i<bank.size(); i++){
        int currCount = 0;
        sort(bank[i].begin(), bank[i].end(), greater<int>());
        for(char ch : bank[i]){
            if(ch == '1'){
                currCount++;
            }
            if(ch == '0'){
                break;
            }
        }
         if(prevCount && currCount){
                count += prevCount * currCount;
                cout << "count: " << count << endl;
            }
            if(currCount){
                prevCount = currCount;
            }
    }
    return count;
}
int main() {
    
    vector<string> v = {"011001","000000","010100","001000"};
  
  cout << numberOfBeams(v) << endl;

    return 0;
}

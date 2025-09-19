#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int k){
    int maxCount = 0;
    unordered_map<int, int> track;
    int sum = 0;
    for(int i = 0; i<v.size(); i++){
       sum = sum + v[i];
       
       if(sum == k){
           maxCount = i + 1;
       }
       
       if(track.count(sum - k)){
           maxCount = max(maxCount, i - track[sum -k]);
       }
       
       if(!track.count(sum)){
           track[sum] = i;
       }
    }
    return maxCount;
}

int main() {
    vector<int> v = {10, 5, 2, 7, 1, -10};
    int k = 15;
    
    cout << solve(v, k) << endl;

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxPairSum(vector<int> &nums){
    if(nums.size() == 0) return -1;
    
    unordered_map<int, vector<int>> mp;
    
    
    for(int val : nums){
        int remain = val, maxDigit = 0;
        while(remain > 0){
            maxDigit = max(maxDigit, remain%10);
            remain /= 10;
        }
        mp[maxDigit].push_back(val);
    }
    
    int maxSum = -1;
    
    for(auto &[digit, arr] : mp){
       if(arr.size() == 1) continue;
       sort(arr.begin(), arr.end(), greater<int>());
       maxSum = max(maxSum, arr[0] + arr[1]);
    }
    
    return maxSum;
}

int main() {
    vector<int> v = {112,131,411};
    cout << maxPairSum(v) << endl;
    return 0;
}

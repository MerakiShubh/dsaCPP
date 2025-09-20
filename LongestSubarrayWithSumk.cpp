#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//------------> using map with O(n) <---------------------

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


// -----> Brute force with O(n2) <--------------------

//int solve(vector<int> v, int k){
//     int maxLen = 0;
    
//     for(int i = 0; i<v.size(); i++){
//         int currSum = 0;
//         for(int j = i; j<v.size(); j++){
//             currSum += v[j];
//             if(currSum == k){
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }
//     }
//     return maxLen;
// }


// --------------> sliding window works only with positive elements with 


// int solve(vector<int> v, int k){
//     int left = 0, right = 0;
//     int maxLen = 0;
//     int currSum = 0;
    
//     while(right<v.size()){
//         currSum = currSum + v[right];
        
//         //shrink window
//         while(left <= right && currSum > k){
//             currSum = currSum - v[left];
//             left++;
//         }
        
//         if(currSum == k){
//             maxLen = max(maxLen, right - left + 1);
//         }
        
//         //expand window
//         right++;
//     }
    
//     return maxLen;
// }

int main() {
    vector<int> v = {10, 5, 2, 7, 1, -10};
    int k = 15;
    
    cout << solve(v, k) << endl;

    return 0;
}

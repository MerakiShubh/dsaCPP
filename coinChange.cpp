#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve3(vector<int> &v, int target){
    vector<int>dp(target+1, INT_MAX);

    dp[0] = 0;
    
    for(int i = 1; i<dp.size(); i++){
        int mini = INT_MAX;
        for(int j = 0; j<v.size(); j++){
            if(i - v[j] >= 0 && dp[i - v[j]] != INT_MAX){
                mini = min(mini, 1 + dp[i - v[j]]);
            }
        }
        dp[i] = mini;
    }
    
   for(int i = 0; i<dp.size(); i++){
       cout << i << " -> " << dp[i] << endl;
   }
    
    return dp[target];
}

int solve2(vector<int> &v, int target, vector<int> &dp){
    
      if(target == 0) return 0;
      if(target < 0) return INT_MAX;
      if(dp[target] != -1) return dp[target];
      
      int mini = INT_MAX;
      for(int i = 0; i<v.size(); i++){
          int ans = solve(v, target - v[i], dp);
          if(ans != INT_MAX){
              mini = min(mini, 1 + ans);
          }
      }
    
  return dp[target] = mini;
}




int main() {
  vector<int> v = {1, 2, 5};
  int target = 11;
  
  //method - 1 recursion
  
  cout << solve(v, target) << endl;
  
  
//   method 2 top down (recursion + memoization) 
//   vector<int> dp(target + 1, -1);
  
//   cout <<  solve2(v, target, dp) << endl;
  
//   for(int i = 0; i<dp.size();  i++){
//       cout << i << " -> " << dp[i] << endl;
//   }

// method - 3 bottom up (tabulation) 

cout << "ans: " << solve3(v, target) << endl;




    return 0;
}

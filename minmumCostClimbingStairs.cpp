#include<bits/stdc++.h>
using namespace std;

    // void startFromZero(vector<int> &cost, int &ansFromZero) {
    //     int i = 1;
    //     while (i < cost.size()) {
    //         if (cost[i] < cost[i + 1]) {
    //             ansFromZero += cost[i];
    //             i = i + 1;
    //         } else if (cost[i] > cost[i + 1]) {
    //             ansFromZero += cost[i + 1];
    //             i = i + 2;
    //         } else {
    //             ansFromZero += cost[i + 1];
    //             i = i + 2;
    //         }
    //     }
    // }

    // void startFromFirst(vector<int> &cost, int &ansFromFirst) {
    //     int i = 2;
    //     while (i < cost.size()) {
    //         if (cost[i] < cost[i + 1]) {
    //             ansFromFirst += cost[i];
    //             i = i + 1;
    //         } else if (cost[i] > cost[i + 1]) {
    //             ansFromFirst += cost[i + 1];
    //             i = i + 2;
    //         } else {
    //             ansFromFirst += cost[i + 1];
    //             i = i + 2;
    //         }
    //     }
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     if (cost.empty()) return 0;
    //     if (cost.size() == 1) return cost[0];

    //     int ansFromZero = cost[0];
    //     int ansFromFirst = cost[1];

    //     startFromZero(cost, ansFromZero);
    //     startFromFirst(cost, ansFromFirst);

    //     return min(ansFromZero, ansFromFirst);
    // }
    
// ----------------------------><----------------------------------
    
    // int solve(vector<int> &cost, int i){
    //     if(i>=cost.size()) return 0;
        
    //     return cost[i] + min(solve(cost, i + 1), solve(cost, i + 2));
    // }
    
    // int minCostClimbingStairs(vector<int> &cost){
    //     int n = cost.size();
        
    //     return min(solve(cost, 0), solve(cost, 1));
    // }
    
    
// --------------------------------><---------------------------------

    // int solve(vector<int> &cost, int i, vector<int> &dp){
    //     if(i >= cost.size()) return 0;
        
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
        
    //     dp[i] = cost[i] + min(solve(cost, i + 1, dp), solve(cost, i + 2, dp));
        
    //     return dp[i];
    // }

    // int minCostClimbingStairs(vector<int> &cost){
    //     int n = cost.size();
    //     vector<int> dp(n, -1);
        
    //     return min(solve(cost, 0, dp), solve(cost, 1, dp));
    // }
    
// --------------------------><-------------------------------
    // int minCostClimbingStairs(vector<int> &cost){
    //     int n = cost.size();
        
    //     vector<int> dp(n);
        
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];
        
    //     for(int i = 2; i<n; i++){
    //         dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    //     }
        
    //     return min(dp[n - 1], dp[n - 2]);
    // }
    
    
    int minCostClimbingStairs(vector<int> &cost){
        int first = cost[0];
        int second = cost[1];
        
        for(int i = 2; i<cost.size(); i++){
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        
        return min(first, second);
    }

    
    
    int main(){
        vector<int> v = {1,100,1,1,1,100,1,1,100,1};
        
        // method - 1 brute force approach
        // cout << minCostClimbingStairs(v) << endl;
        
        // method - 2 Recursive approach 
        // cout << minCostClimbingStairs(v) << endl;
        
        // method - 3 recurstion with dp(top down)
        // cout << minCostClimbingStairs(v) << endl;
        
        // method - 4 recursion with dp (bottom up) 
        // cout << minCostClimbingStairs(v) << endl;
        
        //method - 5 recursion with dp with space optimization
        cout << minCostClimbingStairs(v) << endl;

        
        
        return 0;
    }

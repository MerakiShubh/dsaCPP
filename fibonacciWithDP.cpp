#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> dp(N, 0);


// Tob down ---> Space O(n) + O(n) with TC O(n)
// int fib(int n){
//     if(n<=1) return n;
    
//     if(dp[n]){
//         return dp[n];
//     }
    
//     dp[n] = fib(n - 1) + fib(n - 2);
    
//     return dp[n];
// }

//Tabulation method ---> Space O(n) wtih TC O(n)
// int fib(int n){
//     dp[0] = 0;
//     dp[1] = 1;
    
//     for(int i = 2; i<=n; i++){
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }
    
//     return dp[n];
// }

//Space optimization ----> Space O(1) with TC O(n)

int fib(int n){
    int prev1 = 1;
    int prev2 = 0;
    
    int curr;
    for(int i = 2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cout << "Enter the number to calculate fib number: " << endl;
    cin >> n;
    
    cout << fib(n) << endl;
    
    cout << "dp: " << endl;
    for(int i = 0; i<6; i++){
        cout << dp[i] << " ";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> ones;
vector<int> zeros;

int  solve(int curr, int m, int n, int total){
    
    if(curr == total){
        return 0;
    }
    if(dp[curr][m][n] != -1) return dp[curr][m][n];
    
    int notTake = solve(curr + 1, m, n, total);
    
    int take = 0;
    if(m - zeros[curr] >= 0 && n - ones[curr] >= 0){
        take = 1 + solve(curr + 1, m - zeros[curr], n - ones[curr], total);
    }
    
   
    
    return dp[curr][m][n] = max(notTake, take);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    for(int i = 0; i < strs.size(); i++){
        int zeroFreqSum = 0, oneFreqSum = 0;
        for(char ch : strs[i]){
            if(ch == '0'){
                zeroFreqSum++;
            }
            else{
                oneFreqSum++;
            }
        }
        ones.push_back(oneFreqSum);
        zeros.push_back(zeroFreqSum);
    }

    int total = strs.size();
    return solve(0, m, n, total);
    
}

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    
    cout << findMaxForm(strs, m, n) << endl;
}

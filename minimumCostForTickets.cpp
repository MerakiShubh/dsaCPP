class Solution {

private:
int getNextIndex(vector<int> &days, int currIndex, int duration){
    
    int target = days[currIndex] + duration;
    int n = days.size();
    while(currIndex < n && days[currIndex] < target){
        currIndex++;
    }
    return currIndex;
}

int solve(int index, vector<int> &days, vector<int> &costs, vector<int> &dp){
    
    if(index == days.size()) return 0;
    
    if(dp[index] != -1) return dp[index];
    
    int next1 = getNextIndex(days, index, 1);
    int dayOne = costs[0] + solve(next1, days, costs, dp);
    
    int next7 = getNextIndex(days, index, 7);
    int daySeven = costs[1] + solve(next7, days, costs, dp);
    
    int next30 = getNextIndex(days, index, 30);
    int dayThirty = costs[2] + solve(next30, days, costs, dp);
    
    dp[index] = min({dayOne, daySeven, dayThirty});
    
    return dp[index];
    
}

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n = days.size();
        // vector<int> dp(n+1, -1);
        
        // return solve(0, days, costs, dp);

        //tabulation
        int n = days.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;

        for(int i = n - 1; i<days.size(); i--){
            int next1 = getNextIndex(days, i, 1);
            int next7 = getNextIndex(days, i, 7);
            int next30 = getNextIndex(days, i, 30);

        dp[i] = min({
                costs[0] + dp[next1],
                costs[1] + dp[next7],
                costs[2] + dp[next30]
            });
        }

        return dp[0];
    }
};

#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i <= n - k; i++) {
        unordered_map<int, int> freq;

        // Count frequency in current window
        for (int j = i; j < i + k; j++) {
            freq[nums[j]]++;
        }

        // Store as vector of pairs (value, frequency)
        vector<pair<int, int>> freqVec;
        for (auto &p : freq) {
            freqVec.push_back({p.first, p.second});
        }

        // Sort: first by frequency DESC, then by value DESC
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        });

        // Compute x-sum
        int sum = 0;
        for (int idx = 0; idx < min(x, (int)freqVec.size()); idx++) {
            sum += freqVec[idx].first * freqVec[idx].second;
        }

        result.push_back(sum);
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6, x = 2;

    vector<int> ans = findXSum(nums, k, x);

    for (int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}


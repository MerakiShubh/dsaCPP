#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void separateFromZero(vector<int> &nums, int &ops, int l, int r){
     bool allZeros = true;
    for (int i = l; i <= r; i++) {
        if (nums[i] != 0) {
            allZeros = false;
            break;
        }
    }
    if (allZeros) return;

    int minElement = INT_MAX;
    for (int i = l; i <= r; i++) {
        if (nums[i] != 0)
            minElement = min(minElement, nums[i]);
    }

    for (int i = l; i <= r; i++) {
        if (nums[i] != 0)
            nums[i] -= minElement;
    }
    ops++;

    int i = l;
    while (i <= r) {
        while (i <= r && nums[i] == 0) i++;
        int start = i;
        while (i <= r && nums[i] != 0) i++;
        int end = i - 1;

        if (start <= end)
            separateFromZero(nums, ops, start, end); 
    }
    
}

int minOperations(vector<int>& nums) {
    // int ops = 0;
    // separateFromZero(nums, ops, 0, nums.size() - 1);
    // return ops;
    
     stack<int> st;
    int ans = 0;
    for (int x : nums) {
        while (!st.empty() && st.top() > x) st.pop();

        if (x == 0) {
            continue;
        }

        if (st.empty() || st.top() < x) {
            st.push(x);
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {7, 2, 0, 4, 2};
    
    cout << minOperations(v) << endl;

    return 0;
}

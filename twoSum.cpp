vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;  // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int remain = target - nums[i];
        if (mp.find(remain) != mp.end()) {
            return {mp[remain], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main(){
vector<int> v = {2, 7, 11, 15};
vector<int> ans = twoSum(v, 9);

for(int val : ans) cout << val << " ";
return 0;
}

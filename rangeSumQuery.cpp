class NumArray {
public:
    vector<int> nums;
    NumArray(vector<int>& arr) {
        nums = arr;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i)
            sum += nums[i];
        return sum;
    }
};



class NumArray {
public:
    vector<int> prefix; 

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);

       
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

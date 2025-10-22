class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {


        // method - 1 with Time Complexity - O(n2)
       
        // vector<int> result;

        // for(int i = 0; i<nums.size(); i++){
        //      int count = 0;
        //      for(int j = 0; j<nums.size(); j++){
        //         if(nums[i] > nums[j]){
        //             count++;
        //         }
        //      }
        //      result.push_back(count);
        // }
        // return result;


        // method 2 with Time Complexity - O(nlog(k)) + O(k) + O(nlogk) = O(nlog(k))

        
        // vector<int> result;

        // map<int, int> m;

        // for(int val : nums){
        //     m[val]++;
        // }

        // vector<int> values, cummFreq;
        // int sum = 0;

        // for(auto[val, freq] : m){
        //     values.push_back(val);
        //     sum += freq;
        //     cummFreq.push_back(sum);
        // }

        // for(int i = 0; i<nums.size(); i++){
        //     int index = upper_bound(values.begin(), values.end(), nums[i]) - values.begin() - 1;
        //     // int ans = (index >= 0 ) ?  cummFreq[index] - m[nums[i]] : 0;
        //     int ans = cummFreq[index] - m[nums[i]];
        //     result.push_back(ans);
        // }

        // return result;


        // method - 3 with time coplexity O(n) + O(101) + O(n) => O(n)

        vector<int> freq(101, 0);

        for(int val : nums) freq[val]++;

        for(int i = 1;  i<101; i++){
            freq[i] += freq[i - 1];
        }


        vector<int> result;

        for(int i = 0; i<nums.size(); i++){
            int count = (nums[i] == 0) ? 0 : freq[nums[i] - 1]; 
            result.push_back(count);
        }
        
        return result;

    }
};

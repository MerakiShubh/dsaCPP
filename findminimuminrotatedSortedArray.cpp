class Solution {
public:
    int findMin(vector<int>& nums) {

        // method - 1 O(n)

        int min = INT_MAX;

        for(int i = 0; i<nums.size(); i++){
            if(min>nums[i]){
                min = nums[i];
            }
        }
        return min;

        //method - 2 O(lon(n))

        // int lo = 0, hi = nums.size() - 1, mid;
        
        // //completely rotated
        // if(nums[lo] < nums[hi]){
        //     return nums[lo];
        // }

        // while(hi - lo > 1){
        //     mid = (hi + lo) / 2;

        //     if(nums[mid] >= nums[0]){
        //         lo = mid + 1;
        //     }else{
        //         hi = mid;
        //     }
        // }

        // if(nums[lo] < nums[hi]){
        //     return nums[lo];
        // }else{
        //     return nums[hi];
        // }


    }
};

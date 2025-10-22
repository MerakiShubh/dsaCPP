class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {


        // method - 1 with Time complexity -> O(m.n)

        sort(nums.begin(), nums.end());
        int n = nums.size(), m = queries.size();
        vector<int> result;

        for(int i = 0; i<m; i++){
            int sum = 0, count = 0;

            for(int j = 0; j<n; j++){
                sum += nums[j];
                if(sum <= queries[i]){
                    count++;
                }else{
                    break;
                }
            }
            result.push_back(count);
        }

        return result;



        // method - 2 with Time complexity -> O(n) + O(m) -> O(n)
        
    //     sort(nums.begin(), nums.end());

    //     vector<int> prefixVec(nums.size());
    //     prefixVec[0] = nums[0];

    //     for(int i = 1; i<nums.size(); i++){
    //         prefixVec[i] = nums[i] + prefixVec[i - 1];
    //     }

    //     vector<int> result;
    //     for(int i = 0; i<queries.size(); i++){
    //         int index = upper_bound(prefixVec.begin(), prefixVec.end(), queries[i]) - prefixVec.begin();
    //         result.push_back(index);
    //     }
       
    //    return result; 
    }
};

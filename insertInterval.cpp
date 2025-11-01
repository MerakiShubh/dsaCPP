class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // method - 1 with tc O(n) 

        vector<vector<int>> result;

        for(auto val : intervals){
            int first = val[0];
            int second = val[1];

            int left = max(first, newInterval[0]);
            int right = min(second, newInterval[1]);
            
            if(left <= right){
                newInterval[0] = min(first, newInterval[0]);
                newInterval[1] = max(second, newInterval[1]);
            }else if(second < newInterval[0]){
                result.push_back(val);
            }else{
               result.push_back(newInterval);
               newInterval = val;
            }
        }
        result.push_back(newInterval);
        return result;


        // method - 2 with clean logic with tc O(n)

        // vector<vector<int>> result;

        // for(auto &interval : intervals){
        //     if(interval[1] < newInterval[0]){
        //         result.push_back(interval);
        //     }else if(interval[0] > newInterval[1]){
        //         result.push_back(newInterval);
        //         newInterval = interval;
        //     }else{
        //         newInterval[0] = min(interval[0], newInterval[0]);
        //         newInterval[1] = max(interval[1], newInterval[1]);
        //     }
        // }
        // result.push_back(newInterval);
        // return result;
    }
};

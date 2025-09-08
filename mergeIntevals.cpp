#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());  // TC --> O(Nlog(N))

        // method - 1 with (Nlog(N) + N^2) TC and O(1) SC

        // int n = intervals.size();
        // int i = 0;

        // while (i < n - 1) {
        //     int firstVal = intervals[i][0];
        //     int lastVal  = intervals[i][1];

        //     if (firstVal <= intervals[i + 1][0] && intervals[i + 1][0] <= lastVal) {
        //         intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
        //         intervals.erase(intervals.begin() + (i + 1));
        //         n--;
        //     } else {
        //         i++;
        //     }
        // }
        // return invervals;


        //method - 2 with O(Nlog(N) + N) => O(Nlog(N)) TC and O(N) SC

        // vector<vector<int>> result;
        // result.push_back(intervals[0]);

        // for(int i = 1; i<intervals.size(); i++){
        //     if(intervals[i][0] <= result.back()[1]){
        //         result.back()[1] = max(intervals[i][1], result.back()[1]);
        //     }else{
        //         result.push_back(intervals[i]);
        //     }
        // }
        // return result;

        
        //method - 3  with  O(Nlog(N) + N) => O(Nlog(N)) TC and O(N) SC

        int idx = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] <= intervals[idx][1]){
                intervals[idx][1] = max(intervals[i][1], intervals[idx][1]);
            }else{
                idx++;
                intervals[idx] = intervals[i];
            }
            
        }
        intervals.resize(idx + 1);
        return intervals;
}

int main() {
   vector<vector<int>> intervals = {{6,19}, {2,6}, {8,10} , {15,18}};
  merge(intervals);

    sort(intervals.begin(), intervals.end());
   
   for(int i = 0; i<intervals.size(); i++){
       cout << "level " << i+1 << ": ";
       for(int j = 0; j<intervals[i].size(); j++){
           cout << intervals[i][j] << " ";
       }
       cout << endl;
   }
}

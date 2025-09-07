#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int firstVal = 0;
        int lastVal = 0;
        int n = intervals.size();
        int i = 0;

        while(i < n){
            cout << "hllo" << endl;
              if(firstVal <= intervals[i + 1][0] &&  intervals[i + 1][0] <= lastVal){
                intervals.insert(intervals.begin() + i, {intervals[i][0], intervals[i+1][1]});
                intervals.erase(intervals.begin() + (i + 1));
                n--;
                i = 0;
            }
            i++;
        }
            
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

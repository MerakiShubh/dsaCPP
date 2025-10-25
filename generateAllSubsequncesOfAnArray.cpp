#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void generateAllSubsequence(int curr, vector<int> &v, vector<vector<int>> &res, vector<int> &temp){
    
        if(curr == v.size()){
            res.push_back(temp);
            return;
        }
        
        //include 
        temp.push_back(v[curr]);
        
        generateAllSubsequence(curr+1, v, res, temp);
        
        //exclude
        temp.pop_back();
        
        generateAllSubsequence(curr+1, v, res, temp);
    
}
int main() {
  vector<int> v = {1, 2, 3};
  vector<vector<int>> res;
  vector<int> temp;
  generateAllSubsequence(0, v, res, temp);
   
  for(int i = 0; i<res.size(); i++){
      for(int val : res[i]){
          cout << val << " ";
      }
      cout << endl;
  }

    return 0;
}

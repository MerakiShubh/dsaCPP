#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void generatePermutations(vector<int> &v, vector<vector<int>> &res, int idx){
    
    if(idx == v.size() - 1){
        res.push_back(v);
        return;
    }
    
    for(int i = idx; i<v.size(); i++){
        swap(v[i], v[idx]);

        generatePermutations(v, res, idx + 1);
        
        //backtrack
        swap(v[idx], v[i]);
        
    }
    
}


int main() {
    
      vector<int> v = {1, 2, 3};
      vector<vector<int>> res;
    
      generatePermutations(v, res, 0);
       
      for(int i = 0; i<res.size(); i++){
          for(int val : res[i]){
              cout << val << " ";
          }
          cout << endl;
      }

    return 0;
}

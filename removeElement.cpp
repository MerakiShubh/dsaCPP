#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        while(i<nums.size()){
            if(nums[i] == val){
                nums.erase(nums.begin() + i);
                count++;
            }else{
                i++;
            }
        }
        return n - count;
}
int main() {
  vector<int> v = {0,1,2,2,3,0,4,2};
  int val = 2;
  
  cout << removeElement(v, val) << endl;
  
  for(int val : v){
      cout << val << " ";
  }

    return 0;
}

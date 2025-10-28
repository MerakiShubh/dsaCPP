#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isAllEntriesZero(vector<int> nums){
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] != 0){
            return false;
        }
    }

    return true;
}


int makeZeros(vector<int> nums, int index, int direction){
    int n = nums.size();

    bool moveRight = (direction == 1);

    while(index >= 0 && index < n){

        if(nums[index] == 0){
            index += (moveRight ? 1 : -1);
        }else{
            nums[index]--;
            moveRight = !moveRight;
            index += (moveRight ? 1 : -1);
        }

        if(index <  0 || index >= n) break;

    }

    return isAllEntriesZero(nums) ? 1 : 0;
}
 int countValidSelections(vector<int>& nums) {
     
     // method - 1 with tc O(k.n) where is position of zero 

        // int count = 0;

        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] == 0){
        //         count += makeZeros(nums, i, 1);
        //         count += makeZeros(nums, i, -1);
        //     }
        // }

        // return count;
     
     
     
    //  method - 2 with tc O(n)
    
    
    //     int n = nums.size();
        
    //     vector<long long> prefix(n, 0), suffix(n, 0);
        
    //     for(int i = 1; i < n; i++) {
    //         prefix[i] = prefix[i-1] + nums[i-1];
    //     }
        
    //     cout << "prefix: ";
    //     for(int val : prefix) cout << val << " ";
    //     cout << endl;
        
       
    //     for(int i = n-2; i >= 0; i--) {
    //         suffix[i] = suffix[i+1] + nums[i+1];
    //     }
        
  
    //     for(int val : suffix) cout << val << " ";
    //     cout << endl;
        
    //     int result = 0;
        
    //     for(int i = 0; i < n; i++) {
    //         if(nums[i] != 0) continue; 
            
    //         long long left = prefix[i];
    //         long long right = suffix[i];
            
    //         if(left == 0 || right == 0) continue;
            
    //         if(left == right) {
    //             result += 2; 
    //         } else if(left == right + 1) {
    //             result += 1;
    //         } else if(right == left + 1) {
    //             result += 1;
    //         }
    //     }
        
    // return result;
}
int main() {
    vector<int> v = {0, 1, 1, 0, 0, 1};
    
    cout << countValidSelections(v) << endl;

    return 0;
}

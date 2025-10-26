#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void generatePermutations(vector<int> &v, vector<vector<int>> &res, int idx){
    
//     if(idx == v.size() - 1){
//         res.push_back(v);
//         return;
//     }
    
//     for(int i = idx; i<v.size(); i++){
//         swap(v[i], v[idx]);

//         generatePermutations(v, res, idx + 1);
        
//         //backtrack
//         swap(v[idx], v[i]);
        
//     }
    
// }

// void nextPermutation(vector<int> &nums){
    
//      vector<vector<int>> res;
//      generatePermutations(nums, res, 0);
     
//      sort(res.begin(), res.end());
     
//      for(int i = 0; i<res.size(); i++){
//              if(res[i] == nums){
//                  if(i < res.size() - 1){
//                      nums = res[i + 1];
//                  }else{
//                      nums = res[0];
//                  }
//                  break;
//              }
//      }
     
//      for(int val : nums){
//          cout << val << " ";
//      }
     
// }


void nextPermutation(vector<int> &nums){
    
    int n = nums.size();
    int pivot = -1;
    
    /*
    pichhe ke side (right) se aisa element dhundho jo chhota ho aur uske right side wala matlab uske pehele wala bada ho aise element ka pair hai {1, 5}
    */
    for(int i = n - 2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }
    
    /*
    agar aisa pair mila hee nahi iska matalb pura array pichhe se ascending ordre me hai aise case pehla permutation return karna hota hai jo ki aage ascending ho
    */
    
    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    
    /*
    ab aisa elment dundhna hai pivot ke baad jo pivot se bada ho aur baaki sabse se choota ho, toh aisa element pichhe se start karne pr hee mil sakta hai kyui agar pivot se chhota element hai aur wo kisi bade element ke pehel hota to wahi pivot ho jata iska matlab aisa element bade element ke pehle hai (in sabhi baaton me hum pichhe se element count kr rhe hai) aur wo element milt jaye to swap kra do 
    */
    
    
   for(int i = n - 1; i>pivot; i--){
       if(nums[i] > nums[pivot]){
           swap(nums[i], nums[pivot]);
           break;
       }
   }
   
   /*
   swap karane ke baad jab reverse kr doge to bache hue element k sabse chhot versoin mil jayega aur number ko bada krne ke liye hamne pivot ke jagah usse bada element pehele hee rakha hai
   */
   reverse(nums.begin() + (pivot + 1), nums.end());
}

int main() {
    
    vector<int> v = {2, 1, 5, 4, 3, 0, 0};
     
    nextPermutation(v);
     
    return 0;
}

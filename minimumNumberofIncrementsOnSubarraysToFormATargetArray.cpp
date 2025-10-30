#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minNumberOperations(vector<int>& target) {
        int n = target.size();
        
        int sum = target[0];
        
        for(int i = 1; i<n-1; i++){
            if(target[i + 1] > target[i]){
                sum += target[i + 1] - target[i];
            }
        }

        return sum;
    }
    
int main() {
   vector<int> v = {3,1,5,4,2};
   cout << minNumberOperations(v) << endl;
   

    return 0;
}

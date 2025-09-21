#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = 0;
    int maxSum = 0;
    int n = cardPoints.size();
    for(int i = 0; i<k; i++){
        leftSum += cardPoints[i];
    }

    maxSum = leftSum;
    int constant = k;
    for(int i = n - 1; i>n - 1 - constant; i--){
        leftSum = leftSum - cardPoints[k - 1] + cardPoints[i];
        cout << "leftSum: " << leftSum << endl;
        k = k - 1;
        maxSum = max(maxSum, leftSum);
       }
    return maxSum;
    }
int main() {
   
  vector<int> v = {100, 40, 17, 9, 73, 75};
//   vector<int> v = {1,2,3,4,5,6,1};
   int k = 3;
   
   cout << maxScore(v, k) << endl;

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int>& neededTime) 
    char prevChar = ' ';
    int prevVal = 0;
    int totalCost = 0;

    for (int i = 0; i < colors.size(); i++) {
        if (colors[i] == prevChar) {
            totalCost += min(prevVal, neededTime[i]);
            prevVal = max(prevVal, neededTime[i]); 
        } else {
            prevChar = colors[i];
            prevVal = neededTime[i];
        }
    }

    return totalCost;
}

int main() {
   
   vector<int> neededTime = {1,2,3};
   cout << minCost("abc", neededTime) << endl;
   

    return 0;
}

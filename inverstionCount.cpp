#include <bits/stdc++.h> 
using namespace std;


// method - 2 with TC ON(log(N))

int merge(vector<int> &arr, int s, int mid, int e){
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int invCount = 0;
    vector<int> v1(len1);
    vector<int>v2(len2);
    
    for(int i = 0; i<len1; i++) v1[i] = arr[s+i];
    for(int i = 0; i<len2; i++) v2[i] = arr[mid+1+i];
    
    int index1 = 0, index2 = 0;
    int mainVecIndex = s;
    
    while(index1 < len1 && index2 < len2){
        if(v1[index1] <= v2[index2]){
            arr[mainVecIndex++] = v1[index1++];
        }else{
            arr[mainVecIndex++] = v2[index2++];
            invCount = invCount + (len1 - index1);
        }
    }
    
    while(index1 < len1) arr[mainVecIndex++]= v1[index1++];
    while(index2 < len2)  arr[mainVecIndex++] = v2[index2++];
    return invCount;
}


int countMisorderedPairs(vector<int> &arr, int s, int e){
    int invCount = 0;
    if(s < e){
    int mid = s + (e - s) / 2;
        invCount += countMisorderedPairs(arr, s, mid);
        if(mid == 3){
            cout << invCount << endl;
        }
        invCount += countMisorderedPairs(arr, mid + 1, e);
        if(mid == 3){
            cout << invCount << endl;
        }
        invCount += merge(arr, s, mid, e);
        if(mid == 3){
            cout << invCount << endl;
        }
    }
    return invCount;
}


// method 1 with TC O(n^2)

int inversionCount(vector<int> arr){
    int invCount = 0;
    
    for(int i = 0; i<arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                invCount++;
            }
        }
    }
    return invCount;
}


int main() {

    
    vector<int> arr  = {2, 9, 32, 4, 9, 29, 43};
    

    int s = 0, e = arr.size() - 1;
    
    cout << countMisorderedPairs(arr, s, e) << endl;
    
    for(int val : arr){
        cout << val << " ";
    }

    
    // cout << inversionCount(arr) << endl;
    return 0;
}

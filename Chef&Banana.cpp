#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h;
int bananas[N];

bool canEat(int speed){
    int totalTime = 0;
    
    for(int i = 0; i<n; i++){
        totalTime += (bananas[i] + speed - 1) / speed;
        
        if(totalTime > h) return false;
    }
    
    return totalTime <= h;
}


int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        
        cin >> n >> h;
        
        for(int i = 0; i<n; i++){
            cin >> bananas[i];
        }
        
        sort(bananas, bananas + n);
        
        int lo  = 1, hi = *max_element(bananas, bananas + n), mid;
        
        while(hi - lo > 1){
            mid = lo + (hi - lo) / 2;
            
            if(canEat(mid)){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        
        cout << hi << endl;
    }

    return 0;
}



#include <iostream>
using namespace std;


double myPowNegative(int x, int n){
    if(n==0) return 1.0;

    return  1.0 / x*myPowNegative(x, n - 1);
}


// method 2 wtih Tc as O(log(N))
double fastPow(double x, long long n){
    if(n == 0) return 1.0;

    double half = fastPow(x, n / 2);

    if(n % 2 == 0){
        return half * half;
    }else{
        return half * half * x;
    }
}

double myPow(double x, int n) {
   
    // ----> method - 1 with TC - O(N) and fails because n = -2^31 convert to positive (n = -n) int won't last byte
    //because positive range is 2^31 - 1
     
    //     if(n==0) return 1.0;
    
    //     if(n < 0){
    //         n = -n;
    //         return myPowNegative(x, n);
    //     }
    // return x * myPow(x, n-1);

    long long N = n;
    
    if(N < 0){
        N = -N;
        x = 1 / x;
    }
return fastPow(x, N);

}

int main(){
    
    cout << myPow(2, 5) << endl;
    cout << myPow(2, -5) << endl;
 
 return 0;   
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int number){
    if(number < 1) return false;
    if(number <= 3) return true;
    
    if(number%2 == 0) return true;
    if(number%3 == 0) return true;
    
    for(int i = 5; i<=sqrt(number); i += 6){
        if((number%i == 0) ||(number% (i+2 )== 0)) return true;
    }
    return false;
}

int main() {
    
    int number;
    cout << "Enter number; " << endl;
    cin >> number;
   
   if(isPrime(number)){
       cout << "prime: " << number << endl;
   }else{
       cout << "not prime: " << number << endl;
   }
    return 0;
}

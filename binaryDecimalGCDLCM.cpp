#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// tc log(n) and sc log(n)
string covertToBinary(int n){
   
  if(n == 0) return "0";
  if(n == 1) return "1";
   
  int val = n % 2;
   
  return covertToBinary(n / 2) + to_string(val);

    // string ans = "";
    
    // if(n == 0) return "0";

    // while(n>0){
    //     ans = char('0' + (n%2)) + ans;
    //     n /= 2;
    // }
    
    // return ans;
}

int convertToDecimal(string nums){
    
    int sum = 0;
    int power = 0;
    
    for(int i = nums.size() - 1; i>=0; i--){
        int val = nums[i] - '0';
        sum += val * pow(2, power);
        power++;
    }
    return sum;
}

int gcdOfNum(int num1, int num2){
    
    if(num2 == 0) return num1;
    
    return gcdOfNum(num2, num1%num2);
}

int lcmOfNum(int num1, int num2){
    return (num1 * num2) / gcd(num1, num2);
}

int main() {
   int n = 13;
   string binary = covertToBinary(n); 
   cout <<  "decimal to binary: " << binary << endl;
   
   int decimal = convertToDecimal(binary);
   
   cout << "binary to decimal: " << decimal << endl;
   
   int gcd = gcdOfNum(48, 12);
   
   cout <<  "gcd: " << gcd<< endl;
   
   int lcm = lcmOfNum(4, 6);
   
   cout << "lcm: " << lcm << endl;
   
   
    return 0;
}

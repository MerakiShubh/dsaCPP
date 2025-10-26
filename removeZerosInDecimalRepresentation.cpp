class Solution {
public:
    long long removeZeros(long long n) {
        long long ans;
        long long digit;
        string str;
        long long remain = n;

        while(remain > 0){
            digit = remain  % 10;
            if(digit != 0){
                str.push_back(digit + '0');
            }
            
            remain = remain / 10;
        }

        if(str.empty()) return 0;
        
        reverse(str.begin(), str.end());

        ans =  stoll(str);

        return ans;
    }
}

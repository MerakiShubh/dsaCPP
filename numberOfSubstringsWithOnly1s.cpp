class Solution {
public:
    const long long MOD = 1e9 + 7;

    int numSub(string s) {

        int n = s.size();
        long long sum = 0;
        long long len = 0;

        int curr = 0, prev = 0;

        while(curr < n){
            if(s[curr] == '0'){
                curr++;
                continue;
            }

            int prev = curr;
            while(curr < n && s[curr] == '1') curr++;

            len = curr - prev;
            long long ap = (len*(len + 1) / 2) % MOD;

            sum = (sum + ap) % MOD;
        }

        return sum;

    }
};

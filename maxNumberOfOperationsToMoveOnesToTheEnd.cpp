class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int prefix = 0;
        int n = s.size();

        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                if(i == n - 1 || s[i+1] == '1'){
                    count += prefix;
                }
            }else{
                prefix++;
            }
        }
        return count;
    }
};


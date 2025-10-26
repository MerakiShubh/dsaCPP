class Solution {
private:

// void generateAllPermutations(string &str, vector<string> &res, int curr){
    
//     if(curr == str.size()){
//         res.push_back(str);
//         return;
//     }
    
//     for(int i = curr; i<str.size(); i++){
//         swap(str[i], str[curr]);
        
//         generateAllPermutations(str, res, curr + 1);
        
//         swap(str[i], str[curr]);
//     }
    
// }

// bool containsSubstring(string s2, string perm){
//     int n = s2.size();
//     int m = perm.size();

//     for(int i = 0; i<=n-m; i++){
//         bool match = true;

//         for(int j = 0; j<m; j++){
//             if(s2[i + j] != perm[j]){
//                 match = false;
//                 break;
//             }
//         }
//         if(match) return true;
//     }
//     return false;
// }


public:
    bool checkInclusion(string s1, string s2) {

        // method - 1 with TC O(n!) + O((n-m) * m) ---------------> TLE

        // if(s1.size() > s2.size()) return false;

        // vector<string> res;
        // generateAllPermutations(s1, res, 0);


        // ---------------> inbuilt function to check substring present or not <--------------------
        // for(string str : res){
        //     if(s2.find(str) != string::npos){
        //         return true;
        //     }
        // }    
        // return false;


        // for(string str : res){
        //     if(containsSubstring(s2, str)){
        //         return true;
        //     }else{
        //         continue;
        //     }
        // }

        // return false;


        // mehtod - 2 tc -> O(n)

        if(s1.size() > s2.size()) return false;

        vector<int> count1(26, 0), count2(26, 0);

        for(char ch : s1) count1[ch - 'a']++;

        int window = s1.size();

        for(int i = 0; i<s2.size(); i++){
            count2[s2[i] - 'a']++;

            if(i >= window)
                count2[s2[i - window] - 'a']--;
            
            if(count1 == count2)
                return true;
        }

        return false;
    }
};

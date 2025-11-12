class Solution {
private:
int gcd(int num1, int num2){
    if(num2 == 0) return num1;

    return gcd(num2, num1%num2);
}
public:
    int minOperations(vector<int>& nums) {
        int count =0;
        int gcd = nums[0];
        int n = nums.size();
       

        for(int i=0;i<n;i++){
            gcd=__gcd(gcd,nums[i]);
            if(nums[i]!=1){
           
                count++;
            }
        }

        if(gcd!=1){
            return -1;
        }

        if(count!=n){
            return count;
        }
        int mini =1e9;
        for(int i=0;i<n;i++){
            int gcd = nums[i];
            for(int j=i+1;j<n;j++){
                gcd= __gcd(nums[j],gcd);
                if(gcd==1){
                    mini =min(mini,j-i+1);
                }
            }   
        }

        return (count-1)+(mini-1);
    }
};

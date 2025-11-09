class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
        
        // method - 1 with O(max(num1, num2))

        // while(num1 != 0 && num2 != 0){
        //     if(num1 >= num2){
        //         num1 -= num2;
        //         ops++;
        //     }else{
        //         num2 -= num1;
        //         ops++;
        //     }
        // }


        // method - 2 with O(log(min(num1, num2)))
        while(num1 && num2){
            if(num1>=num2)
                ops += num1 / num2, num1 %= num2;
            else
                ops += num2 / num1, num2 %= num1;
        }
       
        return ops;
    }
};

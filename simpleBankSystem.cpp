class Bank {
public:
    const long long accountNumbers = 0;
    vector<long long> balance;
    Bank(vector<long long>& balance):
        balance(balance),
        accountNumbers(balance.size())

     {
    //    this -> blance = blance;
    //    accountNumbers = blance.size(); // if you are not using accountNumbers with const 
    }

    bool isValidAccountNumber(int accNumber){
        if(1 <= accNumber && accNumber <= accountNumbers){
            return true;
        }else{
            return false;
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValidAccountNumber(account1) || !isValidAccountNumber(account2)){
            return false;
        }

        if(balance[account1 - 1] >= money){
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(!isValidAccountNumber(account)){
            return false;
        }

        balance[account - 1] += money;
        return true;

    }
    
    bool withdraw(int account, long long money) {
        if(!isValidAccountNumber(account)){
            return false;
        }

        if(balance[account - 1] >= money){
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

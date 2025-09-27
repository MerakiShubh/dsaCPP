#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3;
vector<long long> dp(N, -1);

long long fib(int n) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number to calculate fib number: " << endl;
    cin >> n;

    cout << fib(n) << endl;

    cout << "dp: " << endl;
    for (int i = 0; i <= n; i++) {
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    return 0;
}


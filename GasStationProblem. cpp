#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // ---------------- Brute Force Helper ----------------
    int findIndex(const vector<int>& gas, const vector<int>& cost, int start) {
        int totalFuel = 0;
        int n = gas.size();
        int index = start;

        while (true) {
            // Wrap around if we reach end
            if (index == n) index = 0;

            // Add gas and try to move to next station
            totalFuel += gas[index];
            if (totalFuel >= cost[index]) {
                totalFuel -= cost[index];
                index++;

                // Completed a full loop
                if (index % n == start) {
                    return start;
                }
            } else {
                // Failed at this station
                return -1;
            }
        }
    }

public:
    // ---------------- Greedy O(n) ----------------
    int canCompleteCircuitGreedy(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for (int g : gas) totalGas += g;
        for (int c : cost) totalCost += c;

        if (totalGas < totalCost) return -1;

        int start = 0;
        int tank = 0;

        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }

    // ---------------- Brute Force O(n²) ----------------
    int canCompleteCircuitBrute(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int index = findIndex(gas, cost, i);
            if (index == i) {
                return i;  // Found valid start
            }
        }
        return -1;
    }
};

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    Solution sol;

    cout << "Greedy Approach (O(n)) → " 
         << sol.canCompleteCircuitGreedy(gas, cost) << endl;

    cout << "Brute Force Approach (O(n^2)) → " 
         << sol.canCompleteCircuitBrute(gas, cost) << endl;

    return 0;
}


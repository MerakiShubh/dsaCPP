#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>  rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> mat(n, vector<int>(n, 0));

        
    for (auto &q : queries) {
        int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
                mat[r][c]++;
            }
        }
    }
        

    return mat;
}

int main() {
    vector<vector<int>> queries = {{1,1,2,2}, {0,0,1,1}};
    vector<vector<int>> mat = rangeAddQueries(3, queries);
    
    for(auto vec : mat){
        for(int val : vec){
            cout << val << " ";
        }
    cout << endl;
    }

    return 0;
}

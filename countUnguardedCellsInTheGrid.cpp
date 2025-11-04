#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int dx, int dy){
   i += dx;
   j += dy;
   
   while(i>=0 && i<m && j>=0 && j<n){
       if(grid[i][j] == 1 || grid[i][j] == 2) break;
       if(grid[i][j] == 0) grid[i][j] = 3;
       
       i += dx;
       j += dy;
   }
}

int countUnguarded(int m, int n, vector<vector<int>>& gaurds, vector<vector<int>>& walls) 
{
       vector<vector<int>> grid(m, vector<int>(n, 0));

        //insert gaurd in gird
        for(auto &gaurd : gaurds){
            grid[gaurd[0]][gaurd[1]] = 1;
        }
        
        
        for(auto &wall : walls){
            grid[wall[0]][wall[1]] = 2;
        }
        
        // cout << "before: " << endl;
        // for(auto vec : grid){
        //     for(int val : vec){
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        
        for(auto gaurd : gaurds){
            int x = gaurd[0], y = gaurd[1];
            for(auto[dx, dy] : directions){
                dfs(grid, x, y, m , n, dx, dy);
            }
        }
        
        
        // cout << "after: " << endl;
        // for(auto vec : grid){
        //     for(int val : vec){
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }
        int count = 0;
        cout << "count: ";
        
        for(auto vec : grid){
            for(int val : vec){
               if(val == 0) count++;
            }
        }
        
        return count;
}

int main() {
    int m = 4, n = 6;
    vector<vector<int>> gaurds = {{0,0},{1,1},{2,3}}; 
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}}; 
    cout << countUnguarded(m, n, gaurds, walls) << endl;

    return 0;
}

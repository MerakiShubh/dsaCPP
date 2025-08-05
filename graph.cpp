#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3;
int graph[N][N];
vector<int> grph[N];
bool vis[N];

void dfs(int vertex){
    /*Take action on vertex after
    entering the vertex
    */
    vis[vertex] = true;
    cout << vertex << endl;
    for(int child : grph[vertex]){
      cout << "parent: " << vertex << " child: " << child << endl;
        /*Take action on child before 
        entring the child node
        */
        if(vis[child]) continue;
        
        dfs(child);
        /*Take action on child after 
        exiting the child
        */
    }
    
    /*Take action on vertex before
    exiting the vertex
    */
}


int main() {
   cout << "Enter data: " << endl;
   int n, m;
   cin >> n >> m;
   
  for(int i = 0; i<m; i++){
      int n1, n2;
      cin >> n1 >> n2;
      
      //adjecency matrix
      graph[n1][n2] = 1;
      graph[n2][n1] = 1;
      
      //adjecency list
      grph[n1].push_back(n2);
      grph[n2].push_back(n1);
  }

   
  cout << "print adjacency matrix graph: " << endl;
   
  for(int i = 0; i<=n; i++){
      for(int j = 0; j<n; j++){
         cout <<  graph[i][j] << " ";
      }
      cout << endl;
  }
   
   cout << "print adjecency list graph: " << endl;
   for(int i = 0; i<=n; i++){
       cout << "index: " << i << " -> ";
      for(int val : grph[i]){
          cout << val << " ";
      }
      cout << endl;
   }
   
  cout << "dfs traversal: " << endl;
   
  for(int i = 1; i<=n; i++){
    if(!vis[i]){
       dfs(i);
    }
  
    }

    return 0;
}

/*
Input 
6 7
0 1
1 2
2 5
5 4
4 3
3 0
1 4
*/

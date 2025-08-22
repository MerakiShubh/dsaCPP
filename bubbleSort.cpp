#include <iostream>
#include <vector>
using namespace std;



void bubbleSortOnePass(vector<int> &v, int size, int i){
    
    //base case 
    if(i == size - 1) return;
    
    if(v[i] > v[i + 1]){
        swap(v[i], v[i+1]);
    }
    
    bubbleSortOnePass(v, size, i+1);
}


void bubbleSort(vector<int> &v, int size){
    
    
    // for(int j = 0; j<v.size(); j++){
    //      int i = 0;
         
    //     while( i < v.size() - 1){
    //         if(v[i] > v[i+1]){
    //               swap(v[i], v[i+1]);
    //         }
    //             i++; 
            
    //     }
    // }
    
    
    //base case
    if(size == 1) return ;
    
    
   
   //Recursive rule
//   int i = 0;
//   while( i < size - 1){
//       if(v[i] > v[i+1]){
//           swap(v[i], v[i + 1]);
//       }
//       i++;
//   }

int i = 0;

    bubbleSortOnePass(v, size, i);
   
   bubbleSort(v, size - 1);
    
}
 



int main() {
    
    vector<int> v =  {28, 32, 44, 43, 40};
    
    // for(int value : v){
    //     cout << "before: " <<  value << endl;
    // }

  
    bubbleSort(v, v.size());
    
    for(int value : v){
        cout <<  "after: " << value << endl;
    }

    return 0;
}

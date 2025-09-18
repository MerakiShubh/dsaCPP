#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class node{
    
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


node* buildTree(node* root){
    //create node
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    
    root = new node(data);
    
    //build left three
    cout << "Enter data to insert in left of: " << data << endl;
    root -> left = buildTree(root -> left);
    
    //build right tree
    cout << "Enter data to insert in right of: " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

int getLeftSum(node* root){
    if(!root) return 0;
    
    int left = getLeftSum(root -> left);
    int right = getRightSum(root -> right);
    
    int best = max(left, right);
    best = max(0, best);
    
    return root -> data + best;
}

int maxSum(node* root, int &maximumSum){
    if(!root) return 0;

    int leftSum = getLeftSum(root -> left, leftSum);
    int rightSum = getRightSum(root -> right, rightSum);
    
    int sum = root -> data + leftSum + rightSum;
    
    maximumSum = max(maximumSum, sum);
    
    
    maxSum(root -> left, maximumSum);
    maxSum(root -> right, maximumSum);
    
    return maximumSum;
}

int maxSum(TreeNode* root, int &maximumSum){
    if(!root) return 0;

    int leftSum = max(0, maxSum(root -> left, maximumSum));
    int rightSum = max (0, maxSum(root -> right, maximumSum));

    int sum = root -> val + leftSum + rightSum;

    maximumSum = max(maximumSum, sum);

    return root -> val + max(leftSum, rightSum);
}

int maxPathSum(node* root){
    int maximumSum = INT_MIN;
    
    
    //method - 1 with TC O(n2)
    //maxSum(root, maximumSum);
    //return maximumSum;
    
    //method - 2 with TC O(n)
    
     maxSum(root, maximumSum);
    return maximumSum;
}


int main(){

cout << "max pathsum: " << maxPathSum(root) << endl;

return 0;
}

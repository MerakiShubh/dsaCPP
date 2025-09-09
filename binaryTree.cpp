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


void levelOrderTraversal(node* root){
    
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
       node* temp = q.front();
       q.pop();
       if(temp == NULL){
           cout << endl;
           if(!q.empty()){
               q.push(NULL);
           }
       }else{
           cout << temp -> data << " ";
           if(temp -> left){
            q.push(temp -> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
       }
    }
}

void reverseLevelOrderTraversal(node* root){
    if(root == nullptr){
        cout << "tree has no node: " << endl;
        return;
    }
    
    queue<node*> q;
    stack<node*> s;
    
    q.push(root);
    q.push(nullptr);
    // s.push(root);
    // s.push(nullptr);
    
    while(!q.empty()){
        node* temp = q.front();
        s.push(temp);
        q.pop();
        if(temp == nullptr){
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            if(temp -> right){
                q.push(temp -> right);
            }
            if(temp -> left){
                q.push(temp -> left);
            }
        }
    }
    
    while(!s.empty()){
        if(s.top() != nullptr){
            cout << s.top() -> data << " ";
            s.pop();
        }else{
            cout << endl;
            s.pop();
        }
    }
    
}


void inOrderTraversal(node* root){
    
    node* temp = root;
    
    //base case
    if(temp == NULL) return;
    
    inOrderTraversal(temp -> left);
    cout << temp -> data << " ";
    inOrderTraversal(temp -> right);
}

void preOrderTraversal(node* root){
    
    node* temp = root;
    
    //base case
    if(temp == NULL) return;
    
    cout << temp -> data << " ";
    preOrderTraversal(temp -> left);
    preOrderTraversal(temp -> right);
}

void postOrderTraversal(node* root){
    
    node* temp = root;
    
    //base case 
    if(temp == NULL) return;
    
    postOrderTraversal(temp -> left);
    postOrderTraversal(temp -> right);
    cout << temp -> data << " ";
}


node* buildFromLevelOrderTraversal(node* root){
    
    queue<node* > q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout << "Enter data to insert in left of: " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }
        
        cout << "Enter data to insert in right of: " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
    
    return root;
}

int height(node* root){
    
    if(root == NULL) return 0;
    
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    
    return max(leftHeight, rightHeight) + 1;
}

int width(node* root){
    queue<pair<node*, long long>> q;
    
    q.push({root, 0});
    
    int maxWidth = 0;
    
    while(!q.empty()){
        int level = q.size();
        long long first_index = q.front().second;
        long long last_index = q.back().second;
        
        maxWidth = max(maxWidth, int (last_index - first_index + 1));
        
        for(int i = 0; i<level; i++){
            auto [temp, index] = q.front();
            
             q.pop();
            
            if(temp -> left)
                q.push({temp -> left, 2 * (index - first_index)});
                
            if(temp -> right)
                q.push({temp -> right, 2 * (index - first_index) + 1});
        }
    }
    
    return maxWidth;
}


int diameter(node* root, int &maxDiameter) {
    // Base case
    if (root == NULL) return 0;

    int leftHeight = diameter(root->left, maxDiameter);
    int rightHeight = diameter(root->right, maxDiameter);

    int currDiameter = leftHeight + rightHeight;

    maxDiameter = max(maxDiameter, currDiameter);

    return max(leftHeight, rightHeight) + 1;
}


int getDiameter(node* root){
    int maxDiameter = 0;
    diameter(root, maxDiameter);
    return maxDiameter;
}

bool isBalanced(node* root, int& height) {
    if (root == NULL) {
        height = 0;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;

    bool leftBalanced = isBalanced(root->left, leftHeight);
    bool rightBalanced = isBalanced(root->right, rightHeight);

    height = max(leftHeight, rightHeight) + 1;

    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    return leftBalanced && rightBalanced;
}

bool isTreeBalanced(node* root) {
    int height = 0;
    return isBalanced(root, height);
}


int isSumTreeFast(node* root){
    if(root == NULL) return 0;
    
    // Leaf node is itself a Sum Tree
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int leftSum = isSumTreeFast(root->left);
    int rightSum = isSumTreeFast(root->right);

    // If any subtree is invalid, return -1
    if(leftSum == -1 || rightSum == -1) return -1;

    if(root->data == leftSum + rightSum){
        // return total sum including current node
        return root->data + leftSum + rightSum;
    }

    return -1; // not a sum tree
}

bool sumTree(node* root){
    return isSumTreeFast(root) != -1;
}


vector<vector<int>> zigZagTraversal(node* root){
    
    
    // -------> method - 1 <--------
    
    // vector<vector<int>> result;
    // vector<int> v;
    // queue<node*> q;
    // stack<node*> s;
    
    // q.push(root);
    // q.push(nullptr);
    // int count = 0;
    
    // while(!q.empty()){
    //     node* temp = q.front();
    //     q.pop();
    //     if(!temp){
    //         count++;
    //         result.push_back(v);
    //         v.clear();
    //         if(!q.empty()){
    //             q.push(nullptr);
    //         }
    //     }else{
    //         if(count % 2 == 0){
    //             cout << temp -> data << " ";
                
    //             v.push_back(temp -> data);
                
    //             if(temp -> left) s.push(temp -> left);
    //             if(temp  -> right) s.push(temp -> right);
                
    //         }
    //         if(count % 2 != 0){
    //             cout << s.top() -> data << " ";
    //             v.push_back(s.top() -> data);
    //             s.pop();
    //         }
            
    //         if(temp -> left) q.push(temp -> left);
    //         if(temp -> right) q.push(temp -> right);
    //     }
    // }
    // return result;
    
    
    //---------> method - 2 <----------
    
    vector<vector<int>> result;
    queue<node*> q;
    bool leftToRight = true;
    q.push(root);
    
    while(!q.empty()){
       
        int size = q.size();
         vector<int> v(size);
        for(int i = 0; i<size; i++){
            node* temp = q.front();
            q.pop();
            
            int index = leftToRight ? i : size - i - 1;
            
            v[index] = temp -> data;
            
           if(temp -> left) q.push(temp -> left);
           if(temp -> right) q.push(temp -> right);
        }
        
        result.push_back(v);
        
        leftToRight = !leftToRight;
    }
    
    return result;
}

void righSideViewHelper(node* root, vector<int> &result, int currDepth){
    
    if(!root) return;
    
    if(currDepth == result.size()){
        result.push_back(root -> data);
    }
    
    if(root -> right){
        // currDepth++; ---> This changes the vlaue of current depth in current recursion stack
        // righSideViewHelper(root -> right, result, currDepth);
        righSideViewHelper(root -> right, result, currDepth + 1);
    }
    
    if(root -> left){
        // currDepth++; ---> This changes the vlaue of current depth in current recursion stack
        // righSideViewHelper(root -> left, result, currDepth);
        righSideViewHelper(root -> left, result, currDepth + 1);
        
    }
}

vector<int> rightSideView(node* root){
    vector<int> result;
    if(!root) return result;
    int currDepth = 0;
    righSideViewHelper(root, result, currDepth);
    
    for(int val : result){
        cout << val << " ";
    }
    
    return result;
}

vector<int> topView(node* root){
    vector<int> result;
    if(!root) return result;
    
    map<int, int> m;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        auto[temp, index] = q.front();
        q.pop();
        
        if(!m[index]){
            m[index] = temp -> data;
        }
        
        if(temp -> left){
            q.push({temp -> left, index - 1});
        }
        
        if(temp -> right){
            q.push({temp -> right, index + 1});
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        result.push_back(it -> second);
        
        cout << it -> second << " ";
    }
    
    
    return result;
}

int bottomLeft(node* root, int currDepth, int &maxDepth, int &ans){
    if(!root) return -1;

    if(currDepth > maxDepth){
        ans = root -> data;
    }
    maxDepth = max(currDepth, maxDepth);
    if(root -> left){
        bottomLeft(root -> left, currDepth + 1, maxDepth, ans);
    }

    if(root -> right){
        bottomLeft(root -> right, currDepth + 1, maxDepth, ans);
    }
    return ans;
}

int findBottomLeftValue(node* root) {

// <----- method - 1 (dfs)  ------>

    // int maxDepth = 0;
    // int ans = root -> data;
    // return bottomLeft(root, 0, maxDepth, ans);
    
    
    vector<int> v;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp){
            v.push_back(temp -> data);
        }
        
        if(!temp){
            if(!q.empty()){
                q.push(nullptr);
                v.clear();
            }
        }else{
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
    return v[0];
}

int main() {
    
    node* root = NULL;
    
    root = buildTree(root);
    
    // cout << "level order traversal: " << endl;
    // levelOrderTraversal(root);
    
    // cout << "reverse level oreder travesal: " << endl;
    // reverseLevelOrderTraversal(root);
    // cout << endl;
    
    // cout << "inorder traversal: " << endl;
    // inOrderTraversal(root);
    // cout << endl;
    
    // cout << "preorder traversal: " << endl;
    // preOrderTraversal(root);
    // cout << endl;
    
    // cout << "postorder traversal: " << endl;
    // postOrderTraversal(root);
    // cout << endl;
    
    // cout <<"height: " << height(root) << endl;
    
    // cout <<"width: " <<  width(root) << endl;
    // cout <<"diameter: " << getDiameter(root) << endl;
    
    
    // root = buildFromLevelOrderTraversal(root);
    
    // cout << "level order traversal: " << endl;
    // levelOrderTraversal(root);
    
    // cout << "balanced: " << isTreeBalanced(root) << endl;
    
    // cout << "zig zag traversal: " << endl;
    // vector<vector<int>> result = zigZagTraversal(root);
    // for(int i = 0; i<result.size(); i++){
    //     for(int j = 0; j<result[i].size(); j++){
    //         cout << result[i][j] << " ";
    //     }
    // }
    
    // cout << "Right side view: " << endl;
    // rightSideView(root);
    
    // cout << "top view: " << endl;
    // topView(root);
    
    cout << "bottomLeft: " << findBottomLeftValue(root) << endl;
    
 
    //5 7 1 -1 -1 8 -1 -1 3 -1 2 -1 -1 
    // 1 2 6 8 -1 -1 -1 -1 3 -1 4 -1 -1
    // 1 2 4 -1 7 9 10 -1 -1 -1 -1 5 -1 -1 3 -1 6 8 -1 11 -1 -1 -1 
    return 0;
}





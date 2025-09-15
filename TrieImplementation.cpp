#include <iostream>
using namespace std;

class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        this -> ch = ch;
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        this -> isTerminal = false;
    }
};

class Trie{
    public:
    
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertWordUtil(TrieNode* root, string word){
        if(!word.length()){
            root -> isTerminal = true;
            return;
        }
        
        TrieNode* child;
        int index = word[0] - 'A';
        
        if(root -> children[index]){
            child = root -> children[index];
        }else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        insertWordUtil(child, word.substr(1));
    }
    
    void insertWord(string word){
        insertWordUtil(root, word);
    }
    
    bool searchWordUtil(TrieNode* root, string word){
        if(!word.length()){
            return root -> isTerminal;
        }
        
        TrieNode* child;
        int index = word[0] - 'A';
        
        if(root -> children[index]){
            child = root -> children[index];
        }else{
            return false;
        }
        
        return searchWordUtil(child, word.substr(1));
    }
    
    bool searchWord(string word){
        return searchWordUtil(root, word);
    }
    
    bool removeWordUtil(TrieNode* root, string word){
        
       if(!word.length()){
           if(root -> isTerminal){
               root -> isTerminal = false;
               //if node has no children, tell parent it can delete this node
               for(int i = 0; i<26; i++){
                   //if has any child then don't delete
                   if(root -> children[i]) return false;
               }
               
               return true;
           }
           return false;
       }
        
     
        int index = word[0] - 'A';
        TrieNode* child = root -> children[index];
      
        //word not found 
        if(!child) return false;
        bool shouldDelete = removeWordUtil(child, word.substr(1));
        
        if(shouldDelete){
            cout << "deleting child: " << child -> ch << endl;
            delete child;
            //make parent node to point the nullptr instead of deleted child
            root -> children[index] = nullptr;
            
            //check if current node  is not terminal for any other word and does not have any childrend after the one which we have deleted then delete that as well
            if(!root -> isTerminal){
                for(int i = 0; i<26; i++){
                if(root -> children[i]) return false;
                }
                return true;
            }
        }
        
        //should not be deleted
        return false;
    }
    
    bool removeWord(string word){
        return removeWordUtil(root, word);
    }
};


int main() {
    Trie* t = new Trie();
    t -> insertWord("ABCD");
    t -> insertWord("ABLK");
    t -> insertWord("ABCG");
    t -> insertWord("GKLM");
    t -> insertWord("PQRS");
    cout << "present ABCD before: " << t -> searchWord("ABCD") << endl;
    
    cout << (t -> removeWord("ABCD") ? "ABCD not present: " : "ABCD removed: ") << endl;
    
    cout << "present ABCD after: " << t -> searchWord("ABCD") << endl;
    return 0;
}

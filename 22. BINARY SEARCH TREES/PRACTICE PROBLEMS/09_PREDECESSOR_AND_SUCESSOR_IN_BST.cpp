/*
#Predecessor and Successor

link:- https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

/*
The logic is pretty simple, we have to take predecessor that value which is greatest but smaller than the key, and successor value to that which is smallest but greater than key
*/
class Solution {
  public:
    void solve(Node* root, int key, vector<Node*> &ans){
        if(!root) return;
        
        if(root->data < key){
            int temp = ans[0] != NULL ? ans[0]->data : -1;
            if(root->data > temp) ans[0] = root;
        }
        
        if(root->data > key){
            int temp = ans[1] != NULL ? ans[1]->data : INT_MAX;
            if(root->data < temp) ans[1] = root;
        }
        
        solve(root->left, key, ans);
        solve(root->right, key, ans);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans = {NULL, NULL};
        if(!root) return ans;
        
        solve(root, key, ans);
        
        return ans;
    }
};

int main(){
    
    return 0;
}
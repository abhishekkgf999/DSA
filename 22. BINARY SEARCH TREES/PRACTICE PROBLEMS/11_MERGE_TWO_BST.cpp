/*
#MERGE TWO BST

LINK:- https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};

/*
The solution is inspired from BST iterator approach, where we use stack to preserve the inorder, and we know that inorder of bst is always sorted, so we use that thought process in this as well
where We maintaining two stacks for these two bst, and keeping the inorder traversal in stack, and pushing values in answer vector in sorted manner
*/
//Using Stack - O(n + m) Time and O(n + m) Space
class Solution {
    void pushAll(Node* root, stack<Node*> &st){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
  public:
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        stack<Node*> st1, st2;
        vector<int> ans;
        
        pushAll(root1, st1);
        pushAll(root2, st2);
        
        while(!st1.empty() && !st2.empty()){
            if(st1.top()->data <= st2.top()->data){
                Node* temp1 = st1.top();
                st1.pop();
                ans.push_back(temp1->data);
                pushAll(temp1->right, st1);
            }else{
                Node* temp2 = st2.top();
                st2.pop();
                ans.push_back(temp2->data);
                pushAll(temp2->right, st2);
            }
        }
        
        while(!st1.empty()){
            Node* temp1 = st1.top();
            st1.pop();
            ans.push_back(temp1->data);
            pushAll(temp1->right, st1);
        }
        
        while(!st2.empty()){
            Node* temp2 = st2.top();
            st2.pop();
            ans.push_back(temp2->data);
            pushAll(temp2->right, st2);
        }
        
        return ans;
        
    }
};

int main(){
    

    return 0;
}
/*
#FIND CEIL VALUE IN BST

LINK:- https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        while(root){
            if(root->data > x) ans = root->data;
            if(root->data == x) return x;
            
            if(x > root->data) root = root->right;
            else root = root->left;
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}
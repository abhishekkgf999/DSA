/*
#SEARCH IN BST

LINK:- https://leetcode.com/problems/search-in-a-binary-search-tree/description/
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;

        while(root){
            if(root->val == val) return root;
            else if(val > root->val) root = root->right;
            else root = root->left;
        }

        return root;
    }
};

int main(){
    
    return 0;
}
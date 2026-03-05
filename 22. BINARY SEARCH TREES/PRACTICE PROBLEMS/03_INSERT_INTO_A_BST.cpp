/*
#INSERT INTO A BST

LINK:- https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
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

/*
The solution is pretty simple, I will iterate to the correct leaf node, and keep track of parent node, if my curr pointer reaches to null
and then simply point the given value node to its correct position
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr = root;
        TreeNode* parent = curr;
        while(curr){
            parent = curr;
            if(val < curr->val) curr = curr->left;
            else curr = curr->right;
        }

        if(val > parent->val) parent->right = new TreeNode(val);
        else parent->left = new TreeNode(val);

        return root;
    }
};

int main(){
    
    return 0;
}
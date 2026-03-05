/*
#Construct Binary Tree from Inorder and Postorder Traversal

link:- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
Same logic as preorder and inorder 

but the changes are, in postorder, root is at extreme right, so we start the pointer from end, and keep the end pointer at beginning of the postorder, and logic according to that
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                        vector<int>& postorder, int postStart, int postEnd,
                        unordered_map<int, int>& mpp) {
        if (inStart > inEnd || postStart < postEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postStart]);

        int inRoot = mpp[root->val];
        int numsRight = inEnd - inRoot;

        root->left = buildTree(inorder, inStart, inRoot - 1, postorder,
                                postStart - numsRight - 1, postEnd, mpp);

        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder,
                               postStart - 1, postStart - numsRight, mpp);
                                
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder,
                                   postorder.size() - 1, 0, mpp);

        return root;
    }
};

int main(){
    
    return 0;
}
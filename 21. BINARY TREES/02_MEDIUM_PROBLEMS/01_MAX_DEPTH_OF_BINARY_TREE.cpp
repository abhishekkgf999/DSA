/*
#Maximum depth of binary tree

link:- https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
-> both sides ko depth search krna hai, and, both height mai se maximum height ko hi consider krna hai
-> do it for each level, explore left side and then explore right side and then take maximum of these and add 1

Comlexity:
TC - O(num of nodes) as we are traversing all the nodes of the tree
SC - O(height of the tree) for the recursive stack
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);
        return max(leftdepth, rightdepth) + 1;
    }
};

int main(){
    
    return 0;
}
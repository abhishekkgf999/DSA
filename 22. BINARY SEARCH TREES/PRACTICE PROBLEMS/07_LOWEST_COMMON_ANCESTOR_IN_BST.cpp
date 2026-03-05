/*
#LOWEST COMMON ANCESTOR IN BST

LINK:- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
The logic is simple, its a BST, so if either both p and q located in left subtree or right subtree, if not then the point they diverges, that root node will be the answer
if there is a case when the root node is itself the target p or q node, then simply that node will be the answer
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p-> val || root->val == q-> val) return root;

        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

int main(){
    
    return 0;
}
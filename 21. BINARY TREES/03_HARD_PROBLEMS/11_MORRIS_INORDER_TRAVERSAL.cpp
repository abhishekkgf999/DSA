/*
#MORRIS INORDER TRAVERSAL
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
====================================================
MORRIS INORDER TRAVERSAL
====================================================

💡 GOAL:
- Perform Inorder Traversal (Left → Root → Right)
- WITHOUT using:
    ❌ Recursion
    ❌ Stack
- Achieve O(1) extra space

====================================================
KEY IDEA: THREADED BINARY TREE ⭐
----------------------------------------------------
Instead of using a stack,
we temporarily modify the tree structure
by creating links (threads).

These threads allow us to:
✔ Return back to parent
✔ Without recursion or stack

====================================================
CORE CONCEPT:
----------------------------------------------------
For every node (curr):

CASE 1: curr->left == NULL
--------------------------------
- No left subtree
- Visit curr
- Move to curr->right

CASE 2: curr->left != NULL
--------------------------------
- Find inorder predecessor:
    ➜ Go to curr->left
    ➜ Then go to its extreme right

Let this node be `prev`

--------------------------------
SUBCASE A:
prev->right == NULL
- Thread not created yet
- Create thread:
      prev->right = curr
- Move curr to left subtree

--------------------------------
SUBCASE B:
prev->right == curr
- Thread already exists
- This means left subtree is processed
- Remove thread:
      prev->right = NULL
- Visit curr
- Move curr to right subtree

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ Thread acts like a return path
✔ Each edge is modified at most twice
✔ Tree structure restored at the end
✔ No extra memory used

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node visited at most twice)

SPACE COMPLEXITY:
➡ O(1)
(no recursion, no stack)

====================================================
IMPORTANT POINTS:
----------------------------------------------------
✔ Tree is temporarily modified
✔ Structure is restored before completion
✔ Works only for traversal (not modification)

====================================================
*/

vector<int> morrisInorderTraversal(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;   
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

int main(){
    
    return 0;
}
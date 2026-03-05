/*
#DELETE NODE IN BST

LINK:- https://leetcode.com/problems/delete-node-in-a-bst/description/
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
💡 PROBLEM SUMMARY:
- Given a Binary Search Tree (BST)
- Delete the node with given key
- Maintain BST property after deletion

BST PROPERTY:
- Left subtree  → values < root
- Right subtree → values > root

====================================================
MAIN CASES OF DELETION:
----------------------------------------------------
When target node is found:

CASE 1: Node has NO child (Leaf)
✔ Simply delete it (return NULL)

CASE 2: Node has ONE child
✔ Return that child
✔ Parent will link directly to child

CASE 3: Node has TWO children ⭐
✔ Need to preserve BST property
✔ Replace node properly

====================================================
STRATEGY USED HERE (LEFT SUBTREE PROMOTION):
----------------------------------------------------
If node has two children:

1️⃣ Store right subtree
2️⃣ Find rightmost node of left subtree
   (largest value in left subtree)
3️⃣ Attach original right subtree to:
      rightmost->right
4️⃣ Return left subtree as new root

This maintains BST order.

====================================================
HELPER FUNCTION:
----------------------------------------------------
helper(root):
✔ Handles deletion logic for found node
✔ Returns new subtree root after deletion

----------------------------------------------------
findLastRight(root):
✔ Finds rightmost node of subtree
✔ Used to attach right subtree correctly

====================================================
SEARCH LOGIC:
----------------------------------------------------
- Traverse BST to find key
- Keep track of parent
- Once found:
    ➜ Replace parent’s child using helper()

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ Rightmost of left subtree is predecessor
✔ All values remain in correct BST order
✔ Structure remains valid

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(H)
(H = height of tree)
➡ O(log N) average
➡ O(N) worst case (skewed)

SPACE COMPLEXITY:
➡ O(H) (due to recursion in findLastRight)

====================================================
ALTERNATIVE METHOD:
----------------------------------------------------
Instead of predecessor,
we can use inorder successor
(leftmost of right subtree).

Both approaches are valid.

====================================================
*/
class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;

        return findLastRight(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) { //key = 10
        if(!root) return root;

        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                }else{
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};

int main(){
    
    return 0;
}
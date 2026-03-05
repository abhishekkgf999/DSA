/*
#VALIDATE BINARY SEARCH TREE

LINK:- https://leetcode.com/problems/validate-binary-search-tree/description/
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
- Check whether a binary tree is a valid BST
- BST property:
    ✔ Left subtree  → values < root
    ✔ Right subtree → values > root
- This must hold for ALL nodes (not just immediate children)

====================================================
COMMON MISTAKE ❌
----------------------------------------------------
Only comparing:
    root->left < root
    root->right > root

This is NOT enough!

Example:
        5
       / \
      1   7
         /
        4   ❌ (invalid)

Here 4 < 5 but lies in right subtree → invalid.

So we need RANGE CHECKING.

====================================================
KEY IDEA: RANGE VALIDATION ⭐
----------------------------------------------------
Every node must lie within a valid range.

Initially:
- root can have any value
  → range = (-∞, +∞)

When moving:
----------------------------------------------------
Left subtree:
    range = (minVal, root->val)

Right subtree:
    range = (root->val, maxVal)

====================================================
VALIDATION LOGIC:
----------------------------------------------------
At each node:
1️⃣ If node is NULL → return true
2️⃣ If node->val NOT in (minVal, maxVal)
       → return false
3️⃣ Recursively validate:
       left subtree
       right subtree

====================================================
WHY LONG TYPE?
----------------------------------------------------
- To handle edge cases like:
    INT_MIN, INT_MAX
- Prevent overflow issues

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node visited once)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack)
➡ Worst case (skewed tree): O(N)

====================================================
ALTERNATIVE APPROACH:
----------------------------------------------------
✔ Inorder traversal
✔ Check if sequence is strictly increasing

Both methods are valid.

====================================================
*/
class Solution {
public:
    bool validate(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};

int main(){
    
    return 0;
}
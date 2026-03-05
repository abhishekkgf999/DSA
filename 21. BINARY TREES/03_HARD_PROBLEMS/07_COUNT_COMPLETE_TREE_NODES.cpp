/*
#COUNT COMPLETE TREE NODES

LINK:- https://leetcode.com/problems/count-complete-tree-nodes/

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
💡 PROBLEM SUMMARY:
- Given a COMPLETE binary tree
- Count total number of nodes efficiently
- Complete tree:
    ➜ All levels filled except possibly last
    ➜ Last level filled from LEFT to RIGHT

====================================================
KEY OBSERVATION:
----------------------------------------------------
In a complete binary tree:
- If leftmost height == rightmost height
  ➜ Tree is a PERFECT binary tree

For a perfect binary tree:
➡ Number of nodes = 2^h - 1

====================================================
APPROACH: HEIGHT COMPARISON ⭐
----------------------------------------------------
IDEA:
- Compute height of:
    ✔ Extreme left path
    ✔ Extreme right path

----------------------------------------------------
CASES:
----------------------------------------------------
CASE 1: hl == hr
- Tree is perfect
- Directly return:
      2^hl - 1

CASE 2: hl != hr
- Tree is not perfect
- Count nodes recursively:
      1 (root)
    + left subtree
    + right subtree

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Complete tree property guarantees structure
✔ Height check tells if subtree is perfect
✔ Avoids visiting every node

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O((log N)²)
- Height calculation = O(log N)
- Done at each recursive level

SPACE COMPLEXITY:
➡ O(log N)
- Recursion stack

====================================================
EDGE CASES:
----------------------------------------------------
✔ Empty tree
✔ Single node tree
✔ Perfect binary tree
✔ Last level partially filled

====================================================
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int hl = 0, hr = 0;

        TreeNode* l = root, * r = root;

        while (l) { hl++;l = l->left; }

        while (r) { hr++;r = r->right; }

        if (hl == hr) return pow(2, hl) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {

    return 0;
}
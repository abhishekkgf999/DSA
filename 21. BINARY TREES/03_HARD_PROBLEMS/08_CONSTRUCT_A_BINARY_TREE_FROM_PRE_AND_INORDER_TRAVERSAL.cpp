/*
#Construct Binary Tree from Preorder and Inorder Traversal

link:- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
- Given:
    ✔ Preorder traversal
    ✔ Inorder traversal
- Construct the original binary tree

----------------------------------------------------
Traversal Properties:
----------------------------------------------------
Preorder  → Root → Left → Right
Inorder   → Left → Root → Right

====================================================
KEY OBSERVATION:
----------------------------------------------------
1️⃣ First element in Preorder is always ROOT
2️⃣ In Inorder:
      - Elements left of root → left subtree
      - Elements right of root → right subtree

This allows us to divide the problem recursively.

====================================================
APPROACH: RECURSIVE DIVIDE & CONQUER ⭐
----------------------------------------------------

STEP 1: Pick Root
----------------------------------------------------
- root = preorder[preStart]

STEP 2: Find Root in Inorder
----------------------------------------------------
- Use map for O(1) lookup
- inRoot = index of root in inorder
- Number of nodes in left subtree:
      numsLeft = inRoot - inStart

STEP 3: Recursively Build Subtrees
----------------------------------------------------
Left Subtree:
    preorder range:
        preStart + 1
        preStart + numsLeft
    inorder range:
        inStart
        inRoot - 1

Right Subtree:
    preorder range:
        preStart + numsLeft + 1
        preEnd
    inorder range:
        inRoot + 1
        inEnd

----------------------------------------------------
BASE CASE:
----------------------------------------------------
If:
    preStart > preEnd OR
    inStart > inEnd
→ return NULL

====================================================
WHY MAP IS IMPORTANT?
----------------------------------------------------
✔ Avoids O(N) search in inorder each time
✔ Reduces time complexity
✔ Makes solution efficient

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node processed once)

SPACE COMPLEXITY:
➡ O(N)
(map + recursion stack)

====================================================
IMPORTANT NOTES:
----------------------------------------------------
✔ Works only when all elements are UNIQUE
✔ Preorder gives root
✔ Inorder gives subtree boundaries

====================================================
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
            inorder, inStart, inRoot - 1, mpp);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
            inorder, inRoot + 1, inEnd, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;

        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
            inorder.size() - 1, mpp);

        return root;
    }
};

int main() {

    return 0;
}
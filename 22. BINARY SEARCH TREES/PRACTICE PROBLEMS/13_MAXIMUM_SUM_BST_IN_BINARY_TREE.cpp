/*
#MAXIMUM SUM BST IN BINARY TREE

LINK:- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
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
- Given a binary tree
- Find the maximum sum of any subtree
  that forms a VALID BST
- Subtree can be any node as root

====================================================
KEY IDEA: POSTORDER + TREE DP ⭐⭐⭐
----------------------------------------------------
We must check:
1️⃣ Whether a subtree is a BST
2️⃣ If yes, what is its sum
3️⃣ Track maximum sum among all BST subtrees

----------------------------------------------------
WHY POSTORDER?
----------------------------------------------------
Left → Right → Root

✔ When we reach root,
  we already know:
      - Left subtree info
      - Right subtree info
✔ So we can decide if current subtree is BST

====================================================
CUSTOM RETURN TYPE:
----------------------------------------------------
For every subtree, return 3 values:

✔ minNode → minimum value in subtree
✔ maxNode → maximum value in subtree
✔ sum     → total sum of subtree

This helps parent verify BST property.

====================================================
BST VALIDATION CONDITION:
----------------------------------------------------
For current node to be BST:

    left.maxNode < root->val < right.minNode

If true:
    ✔ Current subtree is valid BST

====================================================
CASE 1: SUBTREE IS BST ⭐
----------------------------------------------------
- Compute:
      currSum = left.sum + right.sum + root->val
- Update global maxSum
- Return:
      minNode = min(root->val, left.minNode)
      maxNode = max(root->val, right.maxNode)
      sum     = currSum

====================================================
CASE 2: NOT A BST ❌
----------------------------------------------------
- Return invalid range:
      minNode = INT_MIN
      maxNode = INT_MAX
      sum     = 0

This ensures parent BST check fails.

====================================================
BASE CASE (NULL NODE):
----------------------------------------------------
Return:
    minNode = INT_MAX
    maxNode = INT_MIN
    sum     = 0

This helps leaf nodes satisfy BST condition.

====================================================
WHY INVALID RANGE WORKS?
----------------------------------------------------
- If subtree is invalid,
  parent condition automatically fails
- Ensures no incorrect BST sum is counted

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node processed once)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack)
➡ Worst case: O(N)

====================================================
KEY INTUITION:
----------------------------------------------------
Each node returns:
✔ Whether it forms a BST
✔ What is its sum
✔ Its value range

This is a classic Tree DP pattern.

====================================================
*/
class NodeValue {
public:
    int minNode, maxNode, sum;

    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
    int maxSum = 0;

    NodeValue helper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};

int main(){
    
    return 0;
}
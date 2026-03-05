/*
#BALANCED BINARY TREE

LINK:- https://leetcode.com/problems/balanced-binary-tree/description/
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
NAIVE IDEA (NOT USED):
----------------------------------------------------
- For every node:
    ➜ Find height of left subtree
    ➜ Find height of right subtree
    ➜ Check difference
- This causes repeated height calculations

❌ Time Complexity: O(N²) in worst case

====================================================
OPTIMIZED APPROACH: HEIGHT + EARLY EXIT ⭐
----------------------------------------------------
KEY OBSERVATION:
- Height calculation and balance check can be done TOGETHER
- We only need to know:
    ➜ Is subtree balanced?
    ➜ What is its height?

----------------------------------------------------
TRICK USED:
----------------------------------------------------
- Main function expects a `bool`
- But `bool` does NOT give enough information
- So we use a helper function returning `int`

----------------------------------------------------
HELPER FUNCTION (checkHeight):
----------------------------------------------------
Returns:
✔ Height of subtree → if balanced
❌ -1 → if subtree is unbalanced

----------------------------------------------------
STEPS:
1️⃣ If root == NULL:
   ➜ height = 0

2️⃣ Recursively get left subtree height
   ➜ If left == -1 → return -1 (unbalanced)

3️⃣ Recursively get right subtree height
   ➜ If right == -1 → return -1 (unbalanced)

4️⃣ Check balance condition:
   ➜ If |left - right| > 1 → return -1

5️⃣ Otherwise:
   ➜ return max(left, right) + 1

----------------------------------------------------
FINAL CHECK:
----------------------------------------------------
- Call checkHeight(root)
- If result != -1 → tree is balanced
- Else → not balanced
*/

//time complexity :- O(n), space complexity :- O(n)
class Solution {
public:
    int checkHeight(TreeNode* root){
        if(!root) return 0;

        int left = checkHeight(root->left);
        if(left == -1) return -1;

        int right = checkHeight(root->right);
        if(right == -1) return -1;

        if(abs(left-right) > 1) return -1;

        return max(left, right) + 1;

    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

int main(){
    
    return 0;
}
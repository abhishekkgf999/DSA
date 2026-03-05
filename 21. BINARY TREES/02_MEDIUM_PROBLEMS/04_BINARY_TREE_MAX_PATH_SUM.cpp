/*
#BINARY TREE MAXIMUM PATH SUM

LINK:- https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
- Find the maximum path sum in a binary tree
- A path:
    ➜ Can start and end at ANY node
    ➜ Must go downward (parent-child)
    ➜ Must be continuous
- Path does NOT need to pass through root

====================================================
KEY INTUITION:
----------------------------------------------------
At every node, two types of paths are possible:

1️⃣ COMPLETE PATH (CANNOT be extended upward):
   - left subtree + node + right subtree

2️⃣ PARTIAL PATH (CAN be extended to parent):
   - node only
   - node + left subtree
   - node + right subtree

👉 We UPDATE result using ALL cases
👉 But RETURN only partial path (single direction)

====================================================
WHY WE CANNOT RETURN COMPLETE PATH?
----------------------------------------------------
- Complete path uses BOTH left and right
- If we return it upward, path will branch
- Path must be linear → invalid

====================================================
APPROACH: POSTORDER DFS + GLOBAL MAX ⭐
----------------------------------------------------
We compute:
✔ Maximum path sum passing THROUGH each node
✔ Maximum single-branch path sum to return upward

----------------------------------------------------
HELPER FUNCTION: solve(root, result)
----------------------------------------------------
Returns:
✔ Maximum sum of a path that:
   - starts at `root`
   - goes downward in ONE direction

Also:
✔ Updates `result` with best path sum found so far

----------------------------------------------------
STEPS:
1️⃣ Base case:
   - If root == NULL → return 0

2️⃣ Recursively calculate:
   - left subtree max path
   - right subtree max path

3️⃣ Update global result considering:
   - root->val
   - root->val + left
   - root->val + right
   - root->val + left + right

4️⃣ Return to parent:
   - max(root->val, root->val + max(left, right))

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node visited once)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack, H = tree height)
➡ Worst case: O(N)

====================================================
IMPORTANT EDGE CASES:
----------------------------------------------------
✔ Tree with all negative values
✔ Single node tree
✔ Path not passing through root

====================================================
*/

class Solution {
public:
    int solve(TreeNode* root, int &result){
        if(!root) return 0;

        int left = solve(root->left, result);
        int right = solve(root->right, result);
        
        result = max({result,root->val, root->val+max(left, right), left+right+root->val});

        return max({root->val+max(left, right), root->val});
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        if(root->left == NULL && root->right == NULL) return root->val;

        int result = INT_MIN;

        solve(root, result);

        return result;
    }
};

int main(){
    
    return 0;
}
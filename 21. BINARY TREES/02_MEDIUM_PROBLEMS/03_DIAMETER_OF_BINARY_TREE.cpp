/*
#Diameter of binary tree

link:- https://leetcode.com/problems/diameter-of-binary-tree/
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
- Diameter of a binary tree = length of the LONGEST path between any two nodes
- Path may or may not pass through the root
- Diameter is measured in number of EDGES (not nodes)

====================================================
IMPORTANT INTUITION:
----------------------------------------------------
Think of every node as a junction:
- Left subtree height = left leg
- Right subtree height = right leg

👉 Longest path THROUGH that node =
   left height + right height

Tree ka diameter = maximum of this value over all nodes

====================================================
KEY OBSERVATION:
----------------------------------------------------
- Height calculation aur diameter calculation ek hi DFS me ho sakte hain
- Diameter is NOT necessarily through root

====================================================
APPROACH: POSTORDER DFS (HEIGHT + DIAMETER) ⭐
----------------------------------------------------
We use recursion and compute:
1️⃣ Height of left subtree
2️⃣ Height of right subtree
3️⃣ Update diameter at current node

----------------------------------------------------
HELPER FUNCTION: solve(root, maxi)
----------------------------------------------------
Returns:
✔ Height of subtree rooted at `root`

Also:
✔ Updates `maxi` with best diameter found so far

----------------------------------------------------
STEPS:
1️⃣ Base case:
   - If root == NULL → height = 0

2️⃣ Recursively find:
   - left subtree height
   - right subtree height

3️⃣ Update diameter:
   - diameter through this node = left height + right height
   - maxi = max(maxi, left + right)

4️⃣ Return height:
   - max(left, right) + 1

----------------------------------------------------
FINAL RESULT:
----------------------------------------------------
- `maxi` holds the diameter of the tree
- Return `maxi`

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node visited once)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack, H = height of tree)
➡ Worst case (skewed tree): O(N)

====================================================
COMMON CONFUSION:
----------------------------------------------------
❓ Why not +1 in diameter?
✔ Because diameter is counted in EDGES
✔ Height counts nodes, diameter counts edges

====================================================
*/

class Solution {
public:
    int solve(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);

        maxi = max(maxi, left+right);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};

int main(){
    
    return 0;
}
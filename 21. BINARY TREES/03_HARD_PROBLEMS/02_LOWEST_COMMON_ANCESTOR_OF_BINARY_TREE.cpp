/*
#LOWEST COMMON ANCESTOR OF BINARY TREE

LINK:- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
- Given a binary tree and two nodes p & q
- Find their Lowest Common Ancestor (LCA)
- LCA = deepest node that has BOTH p and q
  as descendants (a node can be ancestor of itself)

====================================================
APPROACH 1 (CONCEPTUAL – NOT IMPLEMENTED):
----------------------------------------------------
- Find root-to-node paths for p and q
- Compare both paths
- Last common node before divergence = LCA

❌ Drawback:
- Extra space for paths
- More complex

====================================================
APPROACH 2: SINGLE DFS (OPTIMAL) ⭐
----------------------------------------------------
KEY IDEA:
- Traverse tree normally (DFS)
- Stop traversal when:
    ➜ root == p OR root == q
    ➜ root == NULL

----------------------------------------------------
RETURN MEANING:
----------------------------------------------------
At each recursive call, return:
✔ p or q → if found
✔ NULL   → if not found in that subtree
✔ LCA    → if both p & q found in different subtrees

----------------------------------------------------
LOGIC BREAKDOWN:
----------------------------------------------------
1️⃣ Base Case:
   - If root == NULL → return NULL
   - If root == p OR root == q → return root

2️⃣ Recurse:
   - Search in left subtree
   - Search in right subtree

3️⃣ While returning:
   - If left == NULL → return right
   - If right == NULL → return left
   - If both left & right are NOT NULL:
        ➜ Current root is LCA
        ➜ Return root

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ If p and q are in different subtrees → root is LCA
✔ If both are in same subtree → LCA propagates upward
✔ Stops early when target nodes are found

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
KEY EDGE CASES:
----------------------------------------------------
✔ p is ancestor of q
✔ q is ancestor of p
✔ p == q
✔ Root is one of the nodes

====================================================
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            return root;
        }
    }
};

int main(){
    
    return 0;
}
/*
#CONSTRUCT BST FROM PREORDER TRAVERSAL

LINK:- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
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
- Given preorder traversal of a BST
- Construct the original BST
- Preorder = Root → Left → Right

====================================================
POSSIBLE SOLUTIONS:
----------------------------------------------------

1️⃣ Brute Force (O(N²)) ❌
----------------------------------------------------
- Insert each element one by one into BST
- Worst case (sorted input) → skewed tree
- Each insertion takes O(N)

TIME: O(N²)

----------------------------------------------------

2️⃣ Preorder + Inorder Method (O(N log N)) ❌
----------------------------------------------------
- Inorder of BST is always SORTED
- Copy preorder → sort it → get inorder
- Use standard tree construction
  (preorder + inorder)

TIME:
  O(N log N) (sorting)
+ O(N) (build tree)

Better but not optimal.

----------------------------------------------------

3️⃣ RANGE-BASED RECURSION (OPTIMAL) ⭐⭐⭐
----------------------------------------------------
KEY OBSERVATION:
- In BST:
    Left subtree  → values < root
    Right subtree → values > root
- Each node has a valid VALUE RANGE
  based on ancestors

----------------------------------------------------
CORE IDEA:
----------------------------------------------------
Use preorder index + upper bound

At each step:
- If current value > bound → stop
- Else:
    ✔ Create node
    ✔ Recursively build LEFT subtree
        (new bound = root->val)
    ✔ Recursively build RIGHT subtree
        (bound remains same)

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Preorder gives root first
✔ Range ensures BST property
✔ No sorting needed
✔ Each element used exactly once

----------------------------------------------------
IMPORTANT DETAILS:
----------------------------------------------------
- `i` is passed by reference
  → keeps track of preorder index
- Initial bound = INT_MAX

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each element processed once)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack)
➡ O(N) worst case (skewed tree)

====================================================
KEY INTUITION:
----------------------------------------------------
We don't need inorder.
BST property + preorder order is enough
if we control value bounds properly.

====================================================
*/
class Solution {
public:
    TreeNode* build(vector<int> &arr, int &i, int bound){
        if(i == arr.size() || arr[i] > bound) return NULL;
        TreeNode* root = new TreeNode(arr[i++]);
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};

int main(){
    
    return 0;
}
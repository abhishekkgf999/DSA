/*
#CHILDREN SUM PROPERTY

LINK:- https://www.naukri.com/code360/problems/childrensumproperty_790723?leftPanelTabValue=PROBLEM
*/

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/*
💡 PROBLEM SUMMARY:
- Convert a binary tree so that it follows
  the Children Sum Property:
      node->data = left->data + right->data
- IMPORTANT CONSTRAINT:
      ❗ We are allowed to INCREASE node values
      ❗ We are NOT allowed to DECREASE any value

====================================================
KEY IDEA (VERY IMPORTANT):
----------------------------------------------------
We enforce the property in TWO PHASES:
1️⃣ While going DOWN the tree
2️⃣ While coming BACK UP the tree

This ensures the property holds everywhere.

====================================================
PHASE 1: TOP → DOWN ADJUSTMENT
----------------------------------------------------
At current node:

Let:
childSum = left->data + right->data

CASE 1:
✔ If childSum >= root->data
   → Increase root->data to childSum

CASE 2:
✔ If childSum < root->data
   → Increase child node(s) to root->data
   → (because decreasing root is NOT allowed)

This guarantees:
✔ root->data ≤ sum of children (or equal)

----------------------------------------------------
WHY THIS IS NEEDED?
----------------------------------------------------
- We can only increase values
- So deficit is pushed DOWN to children

====================================================
PHASE 2: BOTTOM → UP FIX
----------------------------------------------------
After recursive calls return:

- Children values might have increased
- So we RE-CALCULATE:

    root->data = left->data + right->data

(only if root has at least one child)

This FINAL step ensures:
✔ Children Sum Property is satisfied exactly

====================================================
RECURSIVE FLOW SUMMARY:
----------------------------------------------------
1️⃣ Fix current node (top-down)
2️⃣ Recursively fix left subtree
3️⃣ Recursively fix right subtree
4️⃣ Fix current node again (bottom-up)

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ Values only increase (constraint satisfied)
✔ Deficit pushed downward
✔ Final correction done while returning
✔ Property holds at every node

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
EDGE CASES:
----------------------------------------------------
✔ Leaf nodes (no change needed)
✔ Nodes with only one child
✔ Already valid tree

====================================================
*/


void changeTree(BinaryTreeNode* root) {
    // Write your code here.
    if(!root) return;

    int child = 0;

    if(root->left) child += root->left->data;

    if(root->right) child += root->right->data;

    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;

}  

int main() {

    return 0;
}
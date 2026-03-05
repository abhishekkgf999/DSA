/*
#BST ITERATOR

link:- https://leetcode.com/problems/binary-search-tree-iterator/description/
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
- Implement an iterator over a BST
- next() → returns next smallest element
- hasNext() → returns true if more elements exist
- Must run:
    ✔ Average O(1) time per operation
    ✔ O(H) space (H = height of tree)

====================================================
KEY OBSERVATION:
----------------------------------------------------
Inorder traversal of BST gives:
    SORTED order (ascending)

So we simulate INORDER traversal
using a stack.

====================================================
CORE IDEA ⭐
----------------------------------------------------
- Stack always stores the path
  from current node to its leftmost node
- Stack top = next smallest element

====================================================
HOW IT WORKS:
----------------------------------------------------

INITIALIZATION (Constructor):
--------------------------------
- Push all left nodes starting from root
- Stack now contains smallest element on top

FUNCTION next():
--------------------------------
1️⃣ Pop top node (smallest available)
2️⃣ If popped node has right child:
     ➜ Push all left nodes of right subtree
3️⃣ Return popped node value

FUNCTION hasNext():
--------------------------------
- If stack not empty → more elements exist

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ We lazily perform inorder traversal
✔ Each node pushed & popped once
✔ No need to store full inorder array
✔ Space optimized to O(H)

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ next()  → Amortized O(1)
➡ hasNext() → O(1)

(Each node processed once overall)

SPACE COMPLEXITY:
➡ O(H)
(stack stores path from root to leaf)

====================================================
KEY INTUITION:
----------------------------------------------------
Instead of storing entire inorder,
we simulate traversal step-by-step
using stack.

====================================================
*/
class BSTIterator {
    stack<TreeNode*> myStack;
    void pushAll(TreeNode* node){
        while(node){
            myStack.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

int main(){
    
    return 0;
}
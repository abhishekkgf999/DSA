/*
#FLATTEN BINARY TREE TO LINKED LIST

LINK:-https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
- Convert binary tree into a linked list IN-PLACE
- Linked list must follow PREORDER traversal
- After flattening:
    ✔ left pointers → NULL
    ✔ right pointers → next node in preorder

Example:
Preorder: Root → Left → Right
Final structure should follow this order

====================================================
SOLUTION 1: REVERSE PREORDER (RECURSIVE) ⭐
----------------------------------------------------
IDEA:
- Traverse in reverse preorder:
    Right → Left → Root
- Maintain a global pointer `prev`
  which stores previously processed node

----------------------------------------------------
STEPS:
1️⃣ Recursively flatten right subtree
2️⃣ Recursively flatten left subtree
3️⃣ Set:
      root->right = prev
      root->left  = NULL
4️⃣ Update prev = root

----------------------------------------------------
WHY REVERSE ORDER?
----------------------------------------------------
✔ We want preorder output
✔ Processing right first ensures correct linking

----------------------------------------------------
TIME:  O(N)
SPACE: O(N) (recursion stack)

====================================================
SOLUTION 2: ITERATIVE USING STACK ⭐
----------------------------------------------------
IDEA:
- Simulate preorder traversal using stack

----------------------------------------------------
STEPS:
1️⃣ Push root into stack
2️⃣ While stack not empty:
   - Pop node
   - Push right child
   - Push left child
   - Set:
        curr->right = stack.top()
        curr->left = NULL

----------------------------------------------------
WHY PUSH RIGHT FIRST?
----------------------------------------------------
✔ Stack is LIFO
✔ Left subtree should be processed first
✔ So push right before left

----------------------------------------------------
TIME:  O(N)
SPACE: O(N)

====================================================
SOLUTION 3: MORRIS-STYLE (OPTIMAL) ⭐⭐⭐
----------------------------------------------------
IDEA:
- Use Morris traversal concept
- Avoid extra stack or recursion
- Modify tree in-place

----------------------------------------------------
STEPS:
For each node:
1️⃣ If left child exists:
   - Find rightmost node of left subtree
   - Connect:
        rightmost->right = curr->right
   - Move left subtree to right:
        curr->right = curr->left
   - Set curr->left = NULL

2️⃣ Move curr = curr->right

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Left subtree inserted between root and right subtree
✔ Preserves preorder sequence
✔ No extra memory

----------------------------------------------------
TIME:  O(N)
SPACE: O(1)

====================================================
COMPARISON:
----------------------------------------------------
Recursive → Easy, extra stack
Stack     → Iterative, extra stack
Morris    → Best (O(1) space)

====================================================
*/
class Solution1 {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);

            if(!st.empty()) curr->right = st.top();
            curr->left = nullptr;
        }
    }
};


class Solution3 {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

int main(){
    
    return 0;
}
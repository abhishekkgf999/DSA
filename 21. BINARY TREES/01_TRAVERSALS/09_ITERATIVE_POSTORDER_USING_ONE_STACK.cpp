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
BINARY TREE POSTORDER TRAVERSAL (ITERATIVE – 1 STACK)
====================================================

Postorder = LEFT → RIGHT → ROOT

💡 GOAL:
- Perform postorder traversal WITHOUT recursion
- Use only ONE stack

====================================================
CORE IDEA:
----------------------------------------------------
- Stack stores the path from root to current node
- We go as LEFT as possible first
- Then try RIGHT subtree
- If both left & right are done → process ROOT

----------------------------------------------------
IMPORTANT POINTERS:
- `curr` → helps in traversing left/right
- Stack → stores ancestors (path)
- Right child check decides next move

====================================================
STEP-BY-STEP LOGIC:
----------------------------------------------------
1️⃣ Start with `curr = root`

2️⃣ While `curr != NULL` OR stack is not empty:

   🔹 If `curr != NULL`:
      - Push curr into stack
      - Move curr to left child
      (Left subtree pehle)

   🔹 Else (left subtree finished):
      - Check right child of stack top

      ➜ If right child EXISTS:
           - Move curr to right child
           - Traverse its left subtree

      ➜ If right child DOES NOT exist:
           - Process current node
           - Pop it from stack
           - Add its value to postorder

           - BACKTRACK:
             While stack is not empty AND
             popped node == right child of stack top:
                - Process parent node
                - Pop and add to postorder

====================================================
WHY BACKTRACK LOOP IS NEEDED?
----------------------------------------------------
- Ensures that after finishing RIGHT subtree,
  we correctly process the ROOT
- Prevents re-visiting nodes
- Mimics recursive call return

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node pushed & popped once)

SPACE COMPLEXITY:
➡ O(N)
(stack in worst-case skewed tree)

*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};

int main() {

    return 0;
}
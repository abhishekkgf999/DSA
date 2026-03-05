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
We use stack data structure to iterate preOrderTraversal 

we have to first put right and then left, because left is gonna pop first and then right

preorder traveral order:- ROOT, LEFT, RIGHT
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root == NULL) return preOrder;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            if(temp->right != NULL) st.push(temp->right);
            if(temp->left != NULL) st.push(temp->left);

            preOrder.push_back(temp->val);
        }

        return preOrder;
    }
};

int main() {

    return 0;
}
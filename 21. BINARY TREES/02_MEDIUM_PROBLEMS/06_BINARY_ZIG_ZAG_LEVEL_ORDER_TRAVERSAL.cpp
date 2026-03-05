/*
#BINARY ZIG ZAG LEVEL ORDER TRAVERSAL

LINK:- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
Simple logic, just traverse level order wise, and keep a check or bool variable for odd or even rows or switch to true or false each time
=> whever we have to insert right to left, we just reverse the level array and insert in answer
*/

//Time complexity:- O(n), space complexity:- O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int l = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            if(l&1){
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }else ans.push_back(level);
            l++;
        }

        return ans;

    }
};

int main(){
    
    return 0;
}
/*
#BINARY TREE RIGHT SIDE VIEW

LINK:- https://leetcode.com/problems/binary-tree-right-side-view/description/
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
Same logic as vertical/top/bottom view iteration order

We just keep the record of horizontal level wise order, and update element everytime (extreme right element automatically comes last and store in map)

//For left side iteration, just update the map horizontal level element once only (mpp[horizontal level] == mpp[end] then update only)
*/
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int x = temp.second;

            mpp[x] = node->val;

            if(node->left != NULL) q.push({node->left, x+1});
            if(node->right != NULL) q.push({node->right, x+1});
        }

        for(auto &it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};

/*
the key part is, vector size indicate the current level, and traverse right side first, so if there is any element at right, then it will gonna push in our answer array
and the array size will increase(which means we have to now look for the next level) no other element at same level gonna push again.
*/
class Solution2 {
public:
    void rightSideView(TreeNode* root, int horizontalLevel, vector<int> &ans){
        if(!root) return;

        if(horizontalLevel == ans.size()) ans.push_back(root->val);
        rightSideView(root->right, horizontalLevel+1, ans);
        rightSideView(root->left, horizontalLevel+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        rightSideView(root, 0, ans);

        return ans;
    }
};

int main(){
    
    return 0;
}
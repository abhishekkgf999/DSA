/*
#BINARY TREE PATHS

LINK:- https://leetcode.com/problems/binary-tree-paths/
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

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

/*
Simple traversal, just check for the leaf node and insert only value without "->"
We can use backtracking as well, but here we used simple recursion
*/
class Solution {
public:
    void solve(TreeNode* root, vector<string>& ans, string temp) {
        if (!root) return;

        if (!root->left && !root->right) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp += to_string(root->val);
        temp += "->";

        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        string temp = "";
        solve(root, ans, temp);

        return ans;
    }
};

/*
Same question with backtracking
*/
class Solution2 {
  public:
    void solve(Node* root, vector<vector<int>>& ans, vector<int> &temp) {
        if (!root) return;

        if (!root->left && !root->right) {
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        temp.push_back(root->data);

        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
        
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if (!root) return ans;
        
        vector<int> temp;
        solve(root, ans, temp);

        return ans;
    }
};

int main(){
    
    return 0;
}
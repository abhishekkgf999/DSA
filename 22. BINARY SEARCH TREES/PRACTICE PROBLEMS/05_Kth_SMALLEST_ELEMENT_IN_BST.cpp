/*
#Kth SMALLEST ELEMENT IN BST

LINK:- https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE :- O(N) 
//SIMPLE USE OF INORDER, KEEP COUNT FOR KTH SMALLEST ELEMENT, AND UPDATE ANSWER WHEN IT GET EQUALS
//INORDER IN BST IS ALWAYS SORTED GURANTEED
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    int ans;
    void solve(TreeNode* root, int k, int &count){
        if(!root) return;

        solve(root->left, k, count);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        solve(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        int count = 0;
        solve(root, k, count);
        return ans;
    }
};

int main(){
    
    return 0;
}
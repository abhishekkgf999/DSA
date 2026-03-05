/*
#CHECK IF TWO TREES ARE IDENTICAL OR NOT

LINK:- https://leetcode.com/problems/same-tree/description/

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
=>Simple solutin, just check for the structure similarity and value similarity, if not return false, else traverse both root in same direction (left and right) simultaneously
*/

//time complexity:- O(n), space complexity:- O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        if((p == NULL && q != NULL) || (p != NULL && q == NULL) || (p->val != q->val)) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
    
    return 0;
}
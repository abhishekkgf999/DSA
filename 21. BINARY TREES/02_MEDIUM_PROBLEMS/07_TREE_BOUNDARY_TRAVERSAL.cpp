/*
#TREE BOUNDARY TRAVERSAL

LINK:- https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/

#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


/*
💡 PROBLEM SUMMARY:
- Print the boundary of a binary tree in ANTI-CLOCKWISE order
- Boundary includes:
    1️⃣ Root
    2️⃣ Left boundary (excluding leaf nodes)
    3️⃣ All leaf nodes (left to right)
    4️⃣ Right boundary (excluding leaf nodes, in reverse order)

====================================================
IMPORTANT RULES:
----------------------------------------------------
✔ No node should be printed more than once
✔ Leaf nodes must appear only in leaf traversal
✔ Order matters (anti-clockwise)

====================================================
OVERALL STRATEGY:
----------------------------------------------------
1️⃣ Add root node
2️⃣ Traverse LEFT boundary (top → bottom)
3️⃣ Traverse all LEAF nodes (left → right)
4️⃣ Traverse RIGHT boundary (bottom → top)

====================================================
LEFT BOUNDARY TRAVERSAL:
----------------------------------------------------
- Exclude leaf nodes
- Prefer left child
- If left child does not exist → go right

Pseudo idea:
✔ root → root->left → ... until leaf

====================================================
LEAF NODE TRAVERSAL:
----------------------------------------------------
- Leaf = node with no left & no right
- Use simple DFS
- Traverse both left and right subtrees

====================================================
RIGHT BOUNDARY TRAVERSAL:
----------------------------------------------------
- Exclude leaf nodes
- Prefer right child
- If right child does not exist → go left
- Add nodes AFTER recursion
  (to get bottom → top order)

====================================================
WHY REVERSE ORDER FOR RIGHT BOUNDARY?
----------------------------------------------------
- Boundary traversal is anti-clockwise
- Right boundary should be printed from bottom to top

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node visited once)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack, H = height of tree)
➡ Worst case: O(N)

====================================================
EDGE CASES:
----------------------------------------------------
✔ Empty tree
✔ Single node tree
✔ Left skewed / Right skewed tree

====================================================
*/

class Solution {
  public:
    void traverseLeft(Node* root, vector<int> &ans){
        if((!root) || (root->left == NULL && root->right == NULL)) return;
        
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(!root) return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if((!root) || (root->left == NULL && root->right == NULL)) return;
        
        if(root->right){
            traverseRight(root->right, ans);
        }else{
            traverseRight(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        ans.push_back(root->data);
        
        //left part store
        traverseLeft(root->left, ans);
        
        //store leaf 
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
        //right part stort
        traverseRight(root->right, ans);
        
        return ans;
    }
};

int main(){
    
    return 0;
}
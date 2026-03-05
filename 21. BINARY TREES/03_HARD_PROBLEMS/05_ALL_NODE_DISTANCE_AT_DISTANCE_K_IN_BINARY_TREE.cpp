/*
#ALL NODES DISTANCE K IN BINARY TREE

LINK:- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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
- Given a binary tree, a target node, and an integer K
- Find all nodes that are exactly K distance away from target
- Distance = number of edges

====================================================
MAIN CHALLENGE:
----------------------------------------------------
- In a tree, we can easily move DOWN (left/right)
- But we CANNOT directly move UP (to parent)
- However, distance K nodes can be:
    ➜ in subtree
    ➜ in parent direction
    ➜ in sibling subtrees

====================================================
KEY IDEA: TREE → GRAPH TRANSFORMATION ⭐
----------------------------------------------------
- Treat tree as an undirected graph
- For that, we need:
    ✔ child → parent connection
    ✔ child → child (already exists)

----------------------------------------------------
STEP 1: STORE PARENT INFORMATION
----------------------------------------------------
- Traverse the tree
- For every node:
    ➜ store (child → parent) mapping
- Use a map:
    TreeNode* → TreeNode*

This allows upward traversal.

====================================================
STEP 2: BFS FROM TARGET NODE
----------------------------------------------------
- BFS gives level-wise traversal
- Each BFS level = distance from target

----------------------------------------------------
IMPORTANT ADDITION:
----------------------------------------------------
During BFS, from a node we can go to:
✔ left child
✔ right child
✔ parent (using map)

----------------------------------------------------
VISITED SET (VERY IMPORTANT):
----------------------------------------------------
- Prevent revisiting nodes
- Avoid infinite loops (graph behavior)
- Each node is visited only once

====================================================
BFS LOGIC:
----------------------------------------------------
1️⃣ Push target node into queue
2️⃣ Mark target as visited
3️⃣ While queue is not empty:
   - If K == 0 → stop BFS
   - For current level:
        ➜ explore left, right, parent
        ➜ push unvisited nodes
   - Decrement K

4️⃣ Remaining nodes in queue are
   exactly at distance K

====================================================
FINAL STEP:
----------------------------------------------------
- Extract values from queue
- Store them in answer vector

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(parent mapping + BFS)

SPACE COMPLEXITY:
➡ O(N)
(map + visited + queue)

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ Parent mapping allows backward movement
✔ BFS guarantees correct distance
✔ Visited set prevents cycles
✔ Clean separation of steps

====================================================
*/

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mpp;
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left) mpp[root->left] = root;
        inorder(root->left);

        if(root->right) mpp[root->right] = root;
        inorder(root->right);
    }

    void BFS(TreeNode* root, int k){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> visited;
        visited.insert(root);

        while(!q.empty()){
            int size = q.size();
            if(k == 0) break;
            for(int i = 0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left != NULL && !visited.count(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                if(curr->right != NULL && !visited.count(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }


                if(mpp.find(curr) != mpp.end() && !visited.count(mpp[curr])){
                    q.push(mpp[curr]);
                    visited.insert(mpp[curr]);
                }
            }
            k--;
        }

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        BFS(target, k);
        return ans;
    }
};

int main(){
    
    return 0;
}
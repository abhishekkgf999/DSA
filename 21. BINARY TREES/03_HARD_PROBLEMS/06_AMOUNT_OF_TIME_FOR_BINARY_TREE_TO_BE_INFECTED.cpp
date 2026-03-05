/*
#AMOUNT OF TIME FOR BINARY TREE TO BE INFECTED

LINK:- https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
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
- Given a binary tree
- Infection starts from a node `start`
- Infection spreads to:
    ➜ left child
    ➜ right child
    ➜ parent
- Each spread takes 1 minute
- Find total time to infect ALL nodes

====================================================
SOLUTION 1: TREE → GRAPH + BFS (EASIER TO THINK) ⭐
----------------------------------------------------
KEY IDEA:
- Same as "All Nodes Distance K"
- Treat tree as an undirected graph
- Each BFS level = 1 minute

----------------------------------------------------
STEP 1: STORE PARENT POINTERS
----------------------------------------------------
- Traverse tree
- Store child → parent mapping
- Enables upward traversal

----------------------------------------------------
STEP 2: BFS FROM INFECTED NODE
----------------------------------------------------
- Start BFS from `start` node
- Use visited set to avoid cycles
- Traverse:
    ✔ left
    ✔ right
    ✔ parent

----------------------------------------------------
TIME CALCULATION:
----------------------------------------------------
- Each BFS level = 1 minute
- When BFS finishes → all nodes infected
- Total levels traversed = answer

----------------------------------------------------
TIME & SPACE:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)

SPACE COMPLEXITY:
➡ O(N)
(parent map + queue + visited)

----------------------------------------------------
WHEN TO USE?
----------------------------------------------------
✔ Easy to understand
✔ Direct BFS logic
✔ Slightly extra space

====================================================
*/

class Solution1 {
public:
    unordered_map<TreeNode*, TreeNode*> mpp;
    int time;
    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left) mpp[root->left] = root;
        inorder(root->left);

        if(root->right) mpp[root->right] = root;
        inorder(root->right);
    }

    void BFS(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        unordered_set<int> visited;
        q.push(root);
        int ans = -1;
        visited.insert(root->val);

        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left != NULL && !visited.count(curr->left->val)){
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if(curr->right != NULL && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if(mpp.find(curr) != mpp.end() && !visited.count(mpp[curr]->val)){
                    q.push(mpp[curr]);
                    visited.insert(mpp[curr]->val);
                }
            }
            ans++;
        }

        time = ans;
    }

    void solve(TreeNode* root, int start){
        if(!root) return;

        if(root->val == start){
            BFS(root);
            return;
        }

        solve(root->left, start);
        solve(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        inorder(root);
        time = 0;
        solve(root, start);

        return time;
    }
};

/*
====================================================
SOLUTION 2: TREE DP (MOST OPTIMAL & TRICKY) ⭐⭐⭐
----------------------------------------------------

💡 CORE INTUITION:
----------------------------------------------------
- Infection time = maximum distance
  from infected node to any other node
- Especially the farthest LEAF node

----------------------------------------------------
KEY TRICK:
----------------------------------------------------
- Return NEGATIVE value if infected node
  exists in subtree
- Absolute value represents distance
  from current node to infected node

----------------------------------------------------
MEANING OF RETURN VALUES:
----------------------------------------------------
Return value from solve(node):

✔ Positive value:
   - Height of subtree
   - Infected node NOT in this subtree

✔ Negative value:
   - Distance to infected node
   - Infected node EXISTS below

----------------------------------------------------
CASE HANDLING:
----------------------------------------------------
1️⃣ Current node IS infected node:
   - Update result with max(leftHeight, rightHeight)
   - Return -1 to mark infection path upward

2️⃣ Both children return positive:
   - No infection below
   - Return max height + 1

3️⃣ One child positive, one negative:
   - Infection path + height path meet here
   - Distance =
        abs(left) + abs(right)
   - Update global result
   - Return negative distance upward

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Tracks distance from infected node upward
✔ Simultaneously tracks subtree heights
✔ Calculates longest infection path
✔ Single DFS traversal

----------------------------------------------------
TIME & SPACE:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(single traversal)

SPACE COMPLEXITY:
➡ O(H)
(recursion stack)

----------------------------------------------------
WHEN TO USE?
----------------------------------------------------
✔ Optimal solution
✔ Interview-favorite
✔ Shows strong tree DP understanding

====================================================
*/

class Solution2 {
public:
    int result = INT_MIN;
    int solve(TreeNode* root, int start){
        if(root == NULL) return 0;

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start){
            result = max(LH, RH);
            return -1;
        }else if(LH >=0 && RH >= 0){
            return max(LH, RH) + 1;
        }else{
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);

        return result;
    }
};

int main(){
    
    return 0;
}
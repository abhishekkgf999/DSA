/*
#VERTICAL ORDER TRAVERSAL OF BINARY TREE

LINK:- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
- Print nodes column by column (vertical order)
- Ordering rules:
    1️⃣ Column (vertical) from left → right
    2️⃣ Row (level) from top → bottom
    3️⃣ If multiple nodes share same position:
        ➜ smaller value comes first

====================================================
COORDINATE SYSTEM (KEY IDEA):
----------------------------------------------------
- Treat tree like a 2D grid

For each node:
- x = vertical index (column)
- y = horizontal index (row / depth)

Root:
- (x = 0, y = 0)

Left child:
- (x - 1, y + 1)

Right child:
- (x + 1, y + 1)

====================================================
DATA STRUCTURE USED:
----------------------------------------------------
map<int, map<int, multiset<int>>> node;

Meaning:
- Outer map:
    ➜ vertical order (x), sorted automatically
- Inner map:
    ➜ level order (y), sorted automatically
- Multiset:
    ➜ stores values at same (x, y) in sorted order

====================================================
TRAVERSAL METHOD:
----------------------------------------------------
- Use Level Order Traversal (BFS)
- Queue stores:
    ➜ TreeNode*
    ➜ (x, y) coordinates

----------------------------------------------------
BFS STEPS:
----------------------------------------------------
1️⃣ Push root with (0,0)
2️⃣ While queue is not empty:
   - Pop front node and cooridinates {x,y}, x-> vertical, y->horizontal
   - Insert node->val into node[x][y]
   - Push left child → (x-1, y+1)
   - Push right child → (x+1, y+1)

====================================================
BUILDING FINAL ANSWER:
----------------------------------------------------
1️⃣ Traverse outer map (x from left to right)
2️⃣ For each vertical:
    - Traverse levels (y from top to bottom)
    - Insert all multiset values into a vector
3️⃣ Push vector into final answer

====================================================
WHY BFS?
----------------------------------------------------
✔ Maintains correct top-to-bottom order
✔ Ensures nodes are processed level-wise

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N log N)
(map & multiset operations)

SPACE COMPLEXITY:
➡ O(N)
(storing all nodes)

====================================================
EDGE CASES:
----------------------------------------------------
✔ Multiple nodes at same (x, y)
✔ Skewed tree
✔ Single node tree

====================================================
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> node;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int x = p.second.first, y = p.second.second;
            node[x][y].insert(temp->val);
            if(temp->left != NULL){
                q.push({temp->left, {x-1, y+1}});
            }
            if(temp->right != NULL){
                q.push({temp->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto i : node){
            vector<int> level;
            for(auto j : i.second){
                level.insert(level.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(level);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}
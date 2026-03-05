/*
#MAXIMUM WIDTH OF BINARY TREE

LINK:- https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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
- Width of a level = number of nodes between
  the leftmost and rightmost NON-NULL nodes
- NULL nodes between them are also counted
- Return the maximum width among all levels

====================================================
KEY IDEA: INDEXING LIKE A HEAP ⭐
----------------------------------------------------
- Assign an index to every node similar to heap indexing

If a node has index `i`:
- Left child  → 2*i
- Right child → 2*i + 1

Width of a level:
➡ lastIndex - firstIndex + 1

====================================================
PROBLEM WITH DIRECT INDEXING:
----------------------------------------------------
❌ Indices can become VERY LARGE
❌ Skewed trees cause overflow
❌ Even `long long` can break

====================================================
OPTIMIZATION: NORMALIZED INDEXING ⭐
----------------------------------------------------
At each level:
- Find the minimum index (minIndex)
- Subtract it from all indices of that level

This keeps indices:
✔ Small
✔ Safe
✔ Relative positions intact

====================================================
APPROACH: LEVEL ORDER (BFS)
----------------------------------------------------
Queue stores:
- TreeNode*
- Its index (long long)

----------------------------------------------------
STEPS:
----------------------------------------------------
1️⃣ Push root with index = 0

2️⃣ While queue is not empty:
   - Get current level size
   - Store minimum index of this level

3️⃣ For each node in the level:
   - Normalize index:
        index = index - minIndex
   - Track:
        first index (i == 0)
        last index  (i == size-1)
   - Push children with:
        left  → 2 * index
        right → 2 * index + 1

4️⃣ Width of current level:
   ➜ last - first + 1

5️⃣ Update maximum width

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ Indexing preserves relative positions
✔ Normalization prevents overflow
✔ BFS ensures correct level-wise width

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node processed once)

SPACE COMPLEXITY:
➡ O(N)
(queue in worst case)

====================================================
EDGE CASES:
----------------------------------------------------
✔ Empty tree
✔ Single node tree
✔ Skewed tree
✔ Very deep tree

====================================================
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second;
            long long first, last;
            for(int i = 0; i<size; i++){
                pair<TreeNode*, long long> temp = q.front();
                q.pop();

                temp.second -= minIndex;

                if(i == 0) first = temp.second;
                if(i == size-1) last = temp.second;

                if(temp.first->left){
                    q.push({temp.first->left, 2*temp.second});
                }

                if(temp.first->right){
                    q.push({temp.first->right, 2*temp.second+1});
                }
            }

            ans = max(ans, last-first+1);
        }

        return (int)ans;
    }
};

int main(){
    
    return 0;
}
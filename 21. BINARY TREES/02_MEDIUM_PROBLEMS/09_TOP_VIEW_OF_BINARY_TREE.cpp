/*
#TOP VIEW OF BINARY TREE

LINK:- https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
💡 PROBLEM SUMMARY:
- Print nodes visible when the tree is viewed from TOP
- Nodes are selected based on vertical (column) position
- For each vertical column, only the FIRST node is visible

====================================================
KEY OBSERVATION:
----------------------------------------------------
- Similar to Vertical Order Traversal
- Difference:
    ➜ We ONLY care about vertical index (x)
    ➜ We ignore horizontal level (depth)
    ➜ First node encountered at a vertical column is the top view

====================================================
APPROACH: BFS + MAP ⭐
----------------------------------------------------
WHY BFS?
- BFS processes nodes level by level (top to bottom)
- So the first node seen at any vertical column
  is guaranteed to be the TOP-most node

----------------------------------------------------
DATA STRUCTURES USED:
----------------------------------------------------
map<int, queue<int>> mpp;
- Key   → vertical index (column)
- Value → queue to store nodes in encounter order

queue<pair<Node*, int>> q;
- Stores node with its vertical index

----------------------------------------------------
STEPS:
----------------------------------------------------
1️⃣ If root is NULL → return empty answer

2️⃣ Push root into queue with vertical = 0

3️⃣ While queue is not empty:
   - Pop front node
   - If this vertical is seen first time:
        ➜ push node->data into map
   - Push left child with (vertical - 1)
   - Push right child with (vertical + 1)

4️⃣ Traverse map from left to right:
   - Take front element of each queue
   - Add it to answer

====================================================
WHY QUEUE INSIDE MAP?
----------------------------------------------------
- First inserted element = top-most node
- Any later nodes in same column are below it
- So only front() is visible from top

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N log N)
(map insertion)

SPACE COMPLEXITY:
➡ O(N)
(queue + map storage)

====================================================
EDGE CASES:
----------------------------------------------------
✔ Empty tree
✔ Single node tree
✔ Left or right skewed tree

====================================================
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        map<int, queue<int>> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int y = temp.second;
            
            mpp[y].push(node->data);
            
            if(node->left != NULL) q.push({node->left, y-1});
            if(node->right != NULL) q.push({node->right, y+1});
        }
        
        for(auto i : mpp){
            ans.push_back(i.second.front());
        }
        
        return ans;
    }
};

//Little bit optimized, not using queue, only storing first element which occuring
class Solution2 {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> mpp;  // HD -> node data
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* node = temp.first;

            // store only first node for each HD
            if (mpp.find(temp.second) == mpp.end()) {
                mpp[temp.second] = node->data;
            }

            if (node->left) q.push({node->left, temp.second - 1});
            if (node->right) q.push({node->right, temp.second + 1});
        }

        for (auto &it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};


int main(){
    
    return 0;
}
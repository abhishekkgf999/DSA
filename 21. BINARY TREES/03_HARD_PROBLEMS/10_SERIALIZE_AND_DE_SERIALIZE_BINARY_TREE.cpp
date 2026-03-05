/*
#SERIALIZE AND DESERIALIZE

LINK:- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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
- Serialize:
    ➜ Convert binary tree into a string
- Deserialize:
    ➜ Convert string back into original tree

Goal:
✔ Structure must be preserved
✔ NULL nodes must also be handled

====================================================
APPROACH: LEVEL ORDER (BFS) ⭐
----------------------------------------------------
WHY BFS?
- Tree structure can be stored level by level
- Easy to rebuild using queue
- Naturally handles missing children

====================================================
PART 1: SERIALIZATION
----------------------------------------------------
IDEA:
- Traverse tree using BFS
- For each node:
    ✔ If node exists → store value + ","
    ✔ If node is NULL → store "N,"

----------------------------------------------------
STEPS:
1️⃣ If root is NULL → return empty string
2️⃣ Push root into queue
3️⃣ While queue not empty:
   - Pop node
   - If node exists:
        ➜ append value + ","
        ➜ push left child
        ➜ push right child
   - Else:
        ➜ append "N,"

----------------------------------------------------
WHY STORE NULLS?
----------------------------------------------------
✔ To preserve exact tree structure
✔ Without NULLs, tree reconstruction impossible

====================================================
PART 2: DESERIALIZATION
----------------------------------------------------
IDEA:
- Extract values from string (split by ",")
- Build tree again using BFS order

----------------------------------------------------
STEPS:
1️⃣ Convert string into vector<string>
2️⃣ Create root using first element
3️⃣ Push root into queue
4️⃣ Use index pointer `i` to track nodes

5️⃣ While queue not empty:
   - Pop current node
   - If nodes[i] != "N":
        ➜ create left child
        ➜ push into queue
   - Increment i
   - If nodes[i] != "N":
        ➜ create right child
        ➜ push into queue
   - Increment i

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Serialization stored nodes in BFS order
✔ Deserialization rebuilds tree in same order
✔ Queue ensures correct parent-child mapping

====================================================
TIME & SPACE ANALYSIS:
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N)
(each node processed once)

SPACE COMPLEXITY:
➡ O(N)
(string + queue + vector)

====================================================
EDGE CASES:
----------------------------------------------------
✔ Empty tree
✔ Single node tree
✔ Skewed tree
✔ Tree with many NULL nodes

====================================================
*/

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "N,";
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<string> nodes;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (nodes[i] != "N") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            if (nodes[i] != "N") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};


int main(){
    
    return 0;
}
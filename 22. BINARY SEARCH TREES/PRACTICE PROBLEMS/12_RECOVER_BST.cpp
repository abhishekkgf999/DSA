/*
#RECOVER BST

LINK:- https://leetcode.com/problems/recover-binary-search-tree/description/
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*

💡 PROBLEM SUMMARY:
- In a BST, exactly TWO nodes are swapped by mistake
- Restore the tree WITHOUT changing its structure
- Only swap values back

----------------------------------------------------
KEY PROPERTY:
----------------------------------------------------
Inorder traversal of BST = Sorted order

If two nodes are swapped:
✔ Inorder sequence will have violations
✔ There will be 1 or 2 "inversions"

====================================================
SOLUTION 1: BRUTE FORCE ⭐
----------------------------------------------------
IDEA:
1️⃣ Perform inorder traversal
2️⃣ Store all values in vector
3️⃣ Sort the vector
4️⃣ Perform inorder again
5️⃣ Replace node values using sorted vector

----------------------------------------------------
TIME:
➡ O(N)   (inorder)
➡ O(N log N) (sorting)
➡ O(N)   (rewrite)

Total: O(N log N)

SPACE:
➡ O(N)

----------------------------------------------------
WHY IT WORKS?
----------------------------------------------------
✔ Sorted inorder restores BST
✔ Simple but not optimal

====================================================
*/
class Solution1 {
public:
    vector<int> in;
    int i;

    void inorder(TreeNode* root, bool collect){
        if(!root) return;

        inorder(root->left, collect);

        if(collect) {
            in.push_back(root->val);
        } else {
            root->val = in[i++];
        }

        inorder(root->right, collect);
    }

    void recoverTree(TreeNode* root) {
        if(!root) return;

        inorder(root, true);      
        sort(in.begin(), in.end());  
        i = 0;                    
        inorder(root, false);     
    }
};

/*
====================================================
SOLUTION 2: OPTIMAL (INORDER VIOLATION DETECTION) ⭐⭐⭐
----------------------------------------------------

💡 CORE IDEA:
----------------------------------------------------
During inorder traversal:
- Values must appear in strictly increasing order
- If we see:
      prev->val > current->val
  → Violation detected

----------------------------------------------------
POSSIBLE SCENARIOS:
----------------------------------------------------

CASE 1: Swapped nodes are NOT adjacent
Example:
    1 5 3 4 2 6
Violations:
    5 > 3
    4 > 2

We record:
    first  = 5
    middle = 3
    last   = 2

Swap first & last.

----------------------------------------------------

CASE 2: Swapped nodes are adjacent
Example:
    1 3 2 4 5
Violation:
    3 > 2

We record:
    first  = 3
    middle = 2

Swap first & middle.

----------------------------------------------------
VARIABLE MEANING:
----------------------------------------------------
prev   → previously visited node
first  → first incorrect node
middle → node next to first (first violation)
last   → second incorrect node (if exists)

----------------------------------------------------
STEPS:
----------------------------------------------------
1️⃣ Perform inorder traversal
2️⃣ Detect violations
3️⃣ After traversal:
    - If first & last exist → swap them
    - Else swap first & middle

----------------------------------------------------
TIME:
➡ O(N)

SPACE:
➡ O(1)
(ignoring recursion stack)

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Inorder of BST must be sorted
✔ Only two nodes are misplaced
✔ Detect inversion(s) and fix

====================================================
*/
class Solution2 {
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL &&  (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

int main(){
    
    return 0;
}
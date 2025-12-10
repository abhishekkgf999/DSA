/*
#IS BINARY TREE HEAP

LINK:- https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
*/

#include<bits/stdc++.h>
using namespace std;


class Node {
 public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

/*
isCBT(root, index, totalCount)

* Checks if the binary tree is a Complete Binary Tree.
* Rule:

  * If index >= totalCount → NOT CBT.	// we encountered an index which is not possible acc. to CBT
  * Otherwise, recursively check:

    * Left child → index = 2*i + 1
    * Right child → index = 2*i + 2

------------------------------------------------------------------------------------------------------------------------

isMax(root)

* Checks Max-Heap property.
* Conditions:

  * Leaf → valid.
  * Node with only left child → root->data > left->data
  * Node with two children → root->data > left AND root->data > right, then recursively check both subtrees.
*/
class Solution {
  public:
    int countNode(Node* root){
        if(root == NULL)return 0;
        
        int ans = 1 + countNode(root->left) + countNode(root->right);
        
        return ans;
    }
    
    bool isCBT(Node* root, int index, int totalCount){
        if(root == NULL)return true;
        
        if(index >= totalCount) return false;
        else{
            bool left = isCBT(root->left, 2*index+1, totalCount);
            bool right = isCBT(root->right, 2*index+2, totalCount);
            return (left&&right);
        }
    }
    
    bool isMax(Node* root){
        if(root->left == NULL && root->right == NULL)return true;   //leaf node
        
        if(root->right == NULL) return root->data > root->left->data;
        else{
            return  (root->data > root->left->data) && 
                    (root->data > root->right->data) && 
                    (isMax(root->left) && isMax(root->right));
        }
    }
    bool isHeap(Node* root) {
        // code here
        int index = 0;
        int totalCount = countNode(root);
        return (isCBT(root, index, totalCount) && isMax(root));
    }
};


int main(){
  Solution sol;

  // --- Test Case 1: Max Heap (Should return true) ---
  // 10
  // / \
  // 9  8
  // / \
  // 7  6
  
  Node* root1 = new Node(10);
  root1->left = new Node(9);
  root1->right = new Node(8);
  root1->left->left = new Node(7);
  root1->left->right = new Node(6);
  
  cout << "Test Case 1 (Max Heap): " << (sol.isHeap(root1) ? "True" : "False") << endl; // Expected: True

  // --- Test Case 2: Not a Max Heap (Fails Max Heap Property) ---
  // 5
  // / \
  // 10  4 <-- 10 > 5, fails max heap property
  
  Node* root2 = new Node(5);
  root2->left = new Node(10); 
  root2->right = new Node(4);
  
  cout << "Test Case 2 (Not Max Heap Property): " << (sol.isHeap(root2) ? "True" : "False") << endl; // Expected: False

  // --- Test Case 3: Not a CBT (Fails Completeness Property) ---
  // 10
  // / 
  // 9 
  //  \ 
  //   6 <-- gap in tree, fails completeness
  
  Node* root3 = new Node(10);
  root3->left = new Node(9);
  // root3->left->left is NULL (missing node at index 3 in array representation)
  root3->left->right = new Node(6); 
  
  cout << "Test Case 3 (Not CBT): " << (sol.isHeap(root3) ? "True" : "False") << endl; // Expected: False

  // Clean up memory
  // (In a real application, you'd want a proper cleanup/deletion function, but for a simple test case, this is often omitted)

  return 0;
}
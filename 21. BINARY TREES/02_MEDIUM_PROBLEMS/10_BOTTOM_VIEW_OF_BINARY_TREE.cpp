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
Same logic as top view of binary tree, only change is that we using stack data strcuture
Imagine like that if we see from the bottom, the element which occuring late will be seen and the above element which comes earlier cannot be seen from bottom
*/
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        map<int, stack<int>> mpp;
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
            ans.push_back(i.second.top());
        }
        
        return ans;
    }
};


//without using stack, just overwrite that current horizontal distance element
class Solution2 {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> mpp;   // HD -> node data
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* node = temp.first;

            // overwrite for bottom view
            mpp[temp.second] = node->data;

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
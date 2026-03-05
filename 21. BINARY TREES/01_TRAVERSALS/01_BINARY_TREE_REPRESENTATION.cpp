#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

int main() {
    Node* head = new Node(1);
    head->left = new Node(5);
    head->right = new Node(6);
    return 0;
}
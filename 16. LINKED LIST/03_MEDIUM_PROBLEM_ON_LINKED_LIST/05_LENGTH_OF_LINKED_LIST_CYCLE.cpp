/*
#LENGTH OF LINKED LIST CYCLE

LINK:- https://www.geeksforgeeks.org/problems/find-length-of-loop/1
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void create_linked_list_with_loop(Node*& head, int n, int k) {
    if (n == 0) return;
    head = new Node(1);
    Node* current = head;
    Node* loop_start = nullptr;
    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
        current = current->next;
        if (i == k) {
            loop_start = current;
        }
    }
    if (loop_start != nullptr) {
        current->next = loop_start;
    }
}

class Solution {
public:
    int lengthOfLoop(Node* head) {
        // Code here
        Node* fast = head;
        Node* slow = head;


        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {

                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                Node* temp = slow->next;
                int count = 1;
                while (temp != slow) {
                    temp = temp->next;
                    count++;
                }

                return count;


            }
        }
        return 0;
    }
};

int main() {
    Solution obj;

    // Test Case 1: Linked list with a loop of length 3
    // 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts at 3)
    Node* head1 = nullptr;
    create_linked_list_with_loop(head1, 5, 3);
    cout << "Test Case 1: Length of loop is " << obj.lengthOfLoop(head1) << endl;

    // Test Case 2: Linked list with no loop
    Node* head2 = nullptr;
    create_linked_list_with_loop(head2, 5, 0); // k=0 means no loop
    cout << "Test Case 2: Length of loop is " << obj.lengthOfLoop(head2) << endl;

    // Test Case 3: Linked list with a single-node loop
    Node* head3 = new Node(10);
    head3->next = head3;
    cout << "Test Case 3: Length of loop is " << obj.lengthOfLoop(head3) << endl;

    // Note: In a real-world scenario, you would need to break the loops
    // and properly deallocate memory to avoid leaks.

    return 0;
}
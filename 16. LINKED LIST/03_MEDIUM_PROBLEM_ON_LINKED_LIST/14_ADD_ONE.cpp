/*
#ADD_ONE IN A LINKED LIST

LINK:- https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        Node* reversed_head = reverse(head);
        Node* current = reversed_head;
        int carry = 1;

        while (current != nullptr) {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;

            if (carry == 0) {
                break;
            }
            if (current->next == nullptr && carry > 0) {
                Node* newNode = new Node(carry);
                current->next = newNode;
                carry = 0; // Terminate loop
            }
            current = current->next;
        }

        return reverse(reversed_head);
    }
};

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Simple addition without carry
    // List: 1 -> 2 -> 3
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    cout << "Original list: ";
    display(head1);
    Node* result1 = sol.addOne(head1);
    cout << "After adding one: ";
    display(result1);
    cout << "----------------------" << endl;

    // Test Case 2: Addition with carry
    // List: 1 -> 9 -> 9
    Node* head2 = new Node(1);
    head2->next = new Node(9);
    head2->next->next = new Node(9);
    cout << "Original list: ";
    display(head2);
    Node* result2 = sol.addOne(head2);
    cout << "After adding one: ";
    display(result2);
    cout << "----------------------" << endl;

    // Test Case 3: Addition that requires a new node
    // List: 9 -> 9 -> 9
    Node* head3 = new Node(9);
    head3->next = new Node(9);
    head3->next->next = new Node(9);
    cout << "Original list: ";
    display(head3);
    Node* result3 = sol.addOne(head3);
    cout << "After adding one: ";
    display(result3);
    cout << "----------------------" << endl;

    return 0;
}
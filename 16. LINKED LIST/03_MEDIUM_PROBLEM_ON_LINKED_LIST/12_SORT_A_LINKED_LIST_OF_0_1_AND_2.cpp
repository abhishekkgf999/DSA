/*
#Sort a linked list of 0s, 1s and 2s

Link:- https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution_brute_force_solution {
public:
    Node* segregate(Node* head) {
        // code here
        vector<int> arr(3, 0);
        Node* temp = head;
        while (temp != nullptr) {
            int val = temp->data;
            arr[val]++;
            temp = temp->next;
        }

        temp = head;

        while (arr[0]) {
            temp->data = 0;
            temp = temp->next;
            arr[0]--;
        }

        while (arr[1]) {
            temp->data = 1;
            temp = temp->next;
            arr[1]--;
        }

        while (arr[2]) {
            temp->data = 2;
            temp = temp->next;
            arr[2]--;
        }

        return head;
    }
};


class Solution_using_3_pointer_concept {
public:
    Node* segregate(Node* head) {

        if (head == nullptr || head->next == nullptr) return head;
        // code here
        Node* zero_head = new Node(-1);
        Node* one_head = new Node(-1);
        Node* two_head = new Node(-1);

        Node* zero_tail = zero_head;
        Node* one_tail = one_head;
        Node* two_tail = two_head;

        Node* temp = head;
        while (temp != nullptr) {
            int val = temp->data;
            switch (val) {
            case 0:
                zero_tail->next = temp;
                zero_tail = zero_tail->next;
                temp = temp->next;
                break;
            case 1:
                one_tail->next = temp;
                one_tail = one_tail->next;
                temp = temp->next;
                break;
            case 2:
                two_tail->next = temp;
                two_tail = two_tail->next;
                temp = temp->next;
                break;
            default:
                break;
            }
        }

        if (one_head->next != nullptr) {
            zero_tail->next = one_head->next;
        }
        else {
            zero_tail->next = two_head->next;
        }

        one_tail->next = two_head->next;
        two_tail->next = nullptr;

        Node* new_head = zero_head->next;
        delete zero_head;
        delete one_head;
        delete two_head;

        return new_head;

    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution_brute_force_solution bruteForce;
    Solution_using_3_pointer_concept threePointer;

    // Test Case 1: Brute Force
    vector<int> list1_vals = { 1, 2, 0, 1, 0, 2, 1 };
    Node* head1 = createList(list1_vals);
    cout << "Brute Force Solution:" << endl;
    cout << "Original List: ";
    display(head1);
    Node* sorted1 = bruteForce.segregate(head1);
    cout << "Sorted List: ";
    display(sorted1);
    cout << "-----------------------------------" << endl;

    // Test Case 2: Three Pointer
    vector<int> list2_vals = { 1, 2, 0, 1, 0, 2, 1 };
    Node* head2 = createList(list2_vals);
    cout << "Three Pointer Solution:" << endl;
    cout << "Original List: ";
    display(head2);
    Node* sorted2 = threePointer.segregate(head2);
    cout << "Sorted List: ";
    display(sorted2);
    cout << "-----------------------------------" << endl;

    // Test Case 3: List with no 0s
    vector<int> list3_vals = { 2, 1, 2, 1 };
    Node* head3 = createList(list3_vals);
    cout << "Three Pointer Solution (No 0s):" << endl;
    cout << "Original List: ";
    display(head3);
    Node* sorted3 = threePointer.segregate(head3);
    cout << "Sorted List: ";
    display(sorted3);
    cout << "-----------------------------------" << endl;

    // Note: In a real-world scenario, you would need to add deallocation logic
    // for all created nodes to prevent memory leaks.

    return 0;
}


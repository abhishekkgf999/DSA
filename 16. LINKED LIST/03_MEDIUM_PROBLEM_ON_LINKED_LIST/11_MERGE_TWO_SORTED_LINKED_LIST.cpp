/*
#MERGE TWO SORTED LINKED LIST

LINK:- https://leetcode.com/problems/merge-two-sorted-lists/description/

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution_using_dummy_node_with_pointer_concept {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the head of the merged list.
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Iterate through both lists until one is exhausted.
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes from the non-empty list.
        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        // The merged list starts after the dummy node.
        ListNode* merged_head = dummy->next;
        delete dummy; // Clean up the dummy node
        return merged_head;
    }
};


//TIME COMPLEXITY :- O(M+N)
class Solution_using_recursion {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* result;

        if (list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Test Case 1: Iterative Solution
    // Create List 1: 1 -> 3 -> 5
    ListNode* list1_iterative = new ListNode(1);
    list1_iterative->next = new ListNode(3);
    list1_iterative->next->next = new ListNode(5);

    // Create List 2: 2 -> 4 -> 6
    ListNode* list2_iterative = new ListNode(2);
    list2_iterative->next = new ListNode(4);
    list2_iterative->next->next = new ListNode(6);

    cout << "Iterative Solution:" << endl;
    cout << "List 1: ";
    display(list1_iterative);
    cout << "List 2: ";
    display(list2_iterative);

    Solution_using_dummy_node_with_pointer_concept iterative_solver;
    ListNode* merged_list_iterative = iterative_solver.mergeTwoLists(list1_iterative, list2_iterative);
    cout << "Merged List: ";
    display(merged_list_iterative);

    cout << "---------------------------------------" << endl;

    // Test Case 2: Recursive Solution
    // Create List 3: 10 -> 20 -> 30
    ListNode* list3_recursive = new ListNode(10);
    list3_recursive->next = new ListNode(20);
    list3_recursive->next->next = new ListNode(30);

    // Create List 4: 15 -> 25 -> 35
    ListNode* list4_recursive = new ListNode(15);
    list4_recursive->next = new ListNode(25);
    list4_recursive->next->next = new ListNode(35);

    cout << "Recursive Solution:" << endl;
    cout << "List 3: ";
    display(list3_recursive);
    cout << "List 4: ";
    display(list4_recursive);

    Solution_using_recursion recursive_solver;
    ListNode* merged_list_recursive = recursive_solver.mergeTwoLists(list3_recursive, list4_recursive);
    cout << "Merged List: ";
    display(merged_list_recursive);

    // Note: To avoid memory leaks, in a full application,
    // you'd need to deallocate the nodes of the merged lists.

    return 0;
}
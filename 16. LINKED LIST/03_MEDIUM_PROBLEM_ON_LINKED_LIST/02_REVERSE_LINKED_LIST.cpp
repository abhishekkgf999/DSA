/*
#REVERSE LINKED LIST

LINK:- https://leetcode.com/problems/reverse-linked-list/description/

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

/*

### 🔹 Approach 1: Iterative (3 pointers)

* Maintain 3 pointers:

  1. prev → initially NULL
  2. curr → starts at head
  3. temp (or next) → stores curr->next before breaking the link

* Steps:

  1. Save next node (temp = curr->next)
  2. Reverse the link (curr->next = prev)
  3. Move prev ahead (prev = curr)
  4. Move curr ahead (curr = temp)

* Repeat until curr == NULL.

* At the end, prev becomes the new head.
*/


class Solution_using_prev_and_current_pointer_concept {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

/*
### 🔹 Approach 2: Recursive Method

* Idea: Reversing is a repetitive process → recursion fits naturally.
* You keep moving forward until you reach the end (curr == nullptr).

#### Steps:

1. Base case:

   * If curr == nullptr, return prev (new head of reversed list).

2. Recursive step:

   * Save next node (temp = curr->next).
   * Reverse link (curr->next = prev).
   * Recurse with next node (return reverse(temp, curr)).

So recursion does the same job as the iterative approach — just replaces the while loop with repeated function calls.
*/

class Solution_recursive {
public:
    ListNode* solve(ListNode*& curr, ListNode*& prev) {
        if (curr == nullptr) {
            return prev;
        }

        ListNode* temp = curr->next;
        curr->next = prev;


        return solve(temp, curr);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        return solve(head, prev);
    }
};

void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    display(head);

    // Using the iterative solution
    Solution_using_prev_and_current_pointer_concept iterative_solver;
    ListNode* reversed_head_iterative = iterative_solver.reverseList(head);
    cout << "Reversed List (Iterative): ";
    display(reversed_head_iterative);

    // Re-create the original list for the recursive solution test
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Using the recursive solution
    Solution_recursive recursive_solver;
    ListNode* reversed_head_recursive = recursive_solver.reverseList(head);
    cout << "Reversed List (Recursive): ";
    display(reversed_head_recursive);

    // Note: To avoid memory leaks in a real application, you would need
    // to add code here to delete all the nodes from both reversed lists.

    return 0;
}

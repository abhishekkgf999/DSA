/*
#REMOVE Nth NODE FROM END OF LIST

LINK:- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
Uses a dummy node to make handling the head of the list simple and consistent.

The fast pointer is moved n+1 steps to ensure that slow stops exactly before the node that needs to be deleted.

The while loop continues until fast is nullptr, which correctly positions slow for the deletion.

The deletion logic is clear and correct: slow->next is updated to skip the node to be deleted, and the memory is freed.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* to_delete = slow->next;
        slow->next = slow->next->next;
        delete to_delete;

        return dummy->next;
    }
};

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Solution sol;

    // Test Case 1: Remove the 2nd node from the end
    // List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    display(head1);

    int n1 = 2;
    ListNode* result1 = sol.removeNthFromEnd(head1, n1);
    cout << "List after removing " << n1 << "th node from end: ";
    display(result1);

    cout << "---------------------------------------" << endl;

    // Test Case 2: Remove the head (1st node from the end)
    // List: 1
    ListNode* head2 = new ListNode(1);

    cout << "Original List: ";
    display(head2);

    int n2 = 1;
    ListNode* result2 = sol.removeNthFromEnd(head2, n2);
    cout << "List after removing " << n2 << "th node from end: ";
    display(result2);

    cout << "---------------------------------------" << endl;

    // Test Case 3: Remove the 2nd node from the end
    // List: 1 -> 2
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);

    cout << "Original List: ";
    display(head3);

    int n3 = 2;
    ListNode* result3 = sol.removeNthFromEnd(head3, n3);
    cout << "List after removing " << n3 << "th node from end: ";
    display(result3);

    // Note: The memory is correctly deallocated by the function itself for the removed node.
    // For a complete solution, one would need to deallocate the rest of the list as well.

    return 0;
}
/*
#DELETE THE MIDDLE NODE OF A LINKED LIST

LINK:- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
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
Use slow and fast pointer concept,

fast coverse 2x distance, while slow covers x distance,
we will iterate slow before head, because we want to point slow pointer before the middle node

*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

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

    // Test Case 1: List with an odd number of nodes (5 nodes)
    // List: 1 -> 2 -> 3 -> 4 -> 5
    // Middle node to be deleted: 3
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Original list (5 nodes): ";
    display(head1);
    ListNode* result1 = sol.deleteMiddle(head1);
    cout << "After deleting middle node: ";
    display(result1);
    cout << "--------------------------------------" << endl;

    // Test Case 2: List with an even number of nodes (4 nodes)
    // List: 1 -> 2 -> 3 -> 4
    // Middle node to be deleted: 3 (the second of the two middle nodes)
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);

    cout << "Original list (4 nodes): ";
    display(head2);
    ListNode* result2 = sol.deleteMiddle(head2);
    cout << "After deleting middle node: ";
    display(result2);
    cout << "--------------------------------------" << endl;

    // Test Case 3: List with a single node
    // List: 1
    // Middle node to be deleted: 1
    ListNode* head3 = new ListNode(1);

    cout << "Original list (1 node): ";
    display(head3);
    ListNode* result3 = sol.deleteMiddle(head3);
    cout << "After deleting middle node: ";
    display(result3);
    cout << "--------------------------------------" << endl;

    // Test Case 4: Empty list (already handled in function)
    ListNode* head4 = nullptr;
    cout << "Original list (0 nodes): ";
    display(head4);
    ListNode* result4 = sol.deleteMiddle(head4);
    cout << "After deleting middle node: ";
    display(result4);

    return 0;
}
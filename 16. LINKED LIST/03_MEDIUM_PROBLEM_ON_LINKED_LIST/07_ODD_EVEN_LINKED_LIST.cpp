/*
#ODD EVEN LINKED LIST

LINK:- https://leetcode.com/problems/odd-even-linked-list/description/
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
Odd Even Linked List - Logic:

Problem: Group all odd-positioned nodes together, followed by even-positioned nodes.

Approach: Maintain two separate chains (odd and even) then connect them.

Algorithm:
1. Initialize pointers:
   - odd = head (1st node, odd position)
   - even = head->next (2nd node, even position)
   - head2 = even (remember start of even chain)

2. Rearrange links:
   - odd->next = even->next (connect odd to next odd node)
   - even->next = odd->next (connect even to next even node)
   - Move both pointers forward

3. Continue until: even or even->next becomes null

4. Connect chains: odd->next = head2 (attach even chain to end of odd chain)

Example: 1→2→3→4→5
- After rearrangement: odd chain: 1→3→5, even chain: 2→4
- Final result: 1→3→5→2→4

Key insight: We're essentially separating nodes by position (1st, 3rd, 5th... vs 2nd, 4th, 6th...) then joining the two groups.

Time: O(n), Space: O(1)

Edge cases: Handle empty list or single node at the beginning.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* head2 = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = head2;

        return head;

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
    Solution sol;

    // Test Case 1: Odd number of nodes
    // List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Original list (odd nodes): ";
    display(head1);

    ListNode* reordered_head1 = sol.oddEvenList(head1);
    cout << "Reordered list (odd nodes): ";
    display(reordered_head1);

    cout << "---------------------------------------" << endl;

    // Test Case 2: Even number of nodes
    // List: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    cout << "Original list (even nodes): ";
    display(head2);

    ListNode* reordered_head2 = sol.oddEvenList(head2);
    cout << "Reordered list (even nodes): ";
    display(reordered_head2);

    // Note: In a real-world scenario, you would need to add code
    // to properly deallocate the memory for both lists to avoid leaks.

    return 0;
}
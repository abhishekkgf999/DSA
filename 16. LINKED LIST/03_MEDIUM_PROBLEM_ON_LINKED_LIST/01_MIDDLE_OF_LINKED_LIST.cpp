/*
#MIDDLE OF LINKED LIST

LINK:- https://leetcode.com/problems/middle-of-the-linked-list/

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
## Approach I: Length / 2 Method

1. Traverse the list once to find its length.
2. Traverse again till length/2 steps.
3. The node you reach is the middle.

*/


class Solution_By_finding_Length_of_Linked_list {
public:
    int len_calculate(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }

        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int len = len_calculate(head);

        ListNode* temp = head;


        for (int i = 0; i < (len / 2); i++) {
            temp = temp->next;
        }

        return temp;
    }
};

/*
## Approach II: Slow & Fast Pointer (Tortoise & Hare)

1. Use two pointers:

   * Slow → moves 1 step.
   * Fast → moves 2 steps.
2. When fast reaches end, slow will be at the middle.
*/

class SolutionP_using_the_concept_of_fast_and_slow_pointer {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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

    display(head);

    Solution_By_finding_Length_of_Linked_list obj1;
    SolutionP_using_the_concept_of_fast_and_slow_pointer obj2;

    ListNode* mid1 = obj1.middleNode(head);
    cout << "Middle (Length method): " << mid1->val << endl;

    ListNode* mid2 = obj2.middleNode(head);
    cout << "Middle (Slow-Fast method): " << mid2->val << endl;

    return 0;
}

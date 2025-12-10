/*
#LINKED LIST CYCLE II

LINK:- https://leetcode.com/problems/linked-list-cycle-ii/
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

class Solution_using_hashset {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> hashset;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (hashset.find(temp) != hashset.end())
                return temp;
            hashset.insert(temp);
            temp = temp->next;
        }
        return nullptr;
    }
};

/*
Floyd's Cycle Detection - Why It Works:

Mathematical Proof:

Phase 1: Detect if cycle exists
- Fast moves 2 steps, slow moves 1 step
- If cycle exists, they will eventually meet inside the cycle
- When they meet, slow has traveled distance d, fast has traveled 2d

Phase 2: Find cycle start
- Let's define distances:
  - a = distance from head to cycle start
  - b = distance from cycle start to meeting point
  - c = remaining distance in cycle (from meeting point back to cycle start)
  - Cycle length = b + c

Key insight: When pointers meet, fast has completed exactly one more full cycle than slow.

Distance equations:
- Slow traveled: a + b
- Fast traveled: a + b + (b + c) = a + 2b + c
- Since fast travels twice the distance: a + 2b + c = 2(a + b)
- Simplifying: a + 2b + c = 2a + 2b
- Therefore: c = a

This means: Distance from head to cycle start equals distance from meeting point to cycle start.

Phase 2 algorithm:
- Reset fast to head, keep slow at meeting point
- Move both one step at a time
- They will meet exactly at the cycle start because they both travel distance a

Why it works: The mathematical relationship c = a ensures that when one pointer starts from head and another from meeting point, they converge at cycle start.
*/
class Solution_using_fast_and_slow_pointer {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {

                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    // Test Case 1: Linked list with a cycle
    // List: 3 -> 2 -> 0 -> -4 -> 2
    ListNode* head1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* noden4 = new ListNode(-4);
    head1->next = node2;
    node2->next = node0;
    node0->next = noden4;
    noden4->next = node2; // Cycle back to node with value 2

    Solution_using_hashset hash_solver;
    ListNode* cycle_start_hash = hash_solver.detectCycle(head1);
    if (cycle_start_hash) {
        cout << "Test 1 (Hash Set): Cycle starts at node with value " << cycle_start_hash->val << endl;
    }
    else {
        cout << "Test 1 (Hash Set): No cycle detected." << endl;
    }

    Solution_using_fast_and_slow_pointer floyd_solver;
    ListNode* cycle_start_floyd = floyd_solver.detectCycle(head1);
    if (cycle_start_floyd) {
        cout << "Test 1 (Floyd's): Cycle starts at node with value " << cycle_start_floyd->val << endl;
    }
    else {
        cout << "Test 1 (Floyd's): No cycle detected." << endl;
    }

    // Since the list has a cycle, we can't properly deallocate all memory with `delete`.
    // In a real application, you'd need to break the cycle first.
    // For this example, we'll just demonstrate the functionality.


    cout << "------------------------------------------" << endl;


    // Test Case 2: Linked list with no cycle
    // List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    ListNode* no_cycle_start_hash = hash_solver.detectCycle(head2);
    if (no_cycle_start_hash) {
        cout << "Test 2 (Hash Set): Cycle starts at node with value " << no_cycle_start_hash->val << endl;
    }
    else {
        cout << "Test 2 (Hash Set): No cycle detected." << endl;
    }

    ListNode* no_cycle_start_floyd = floyd_solver.detectCycle(head2);
    if (no_cycle_start_floyd) {
        cout << "Test 2 (Floyd's): Cycle starts at node with value " << no_cycle_start_floyd->val << endl;
    }
    else {
        cout << "Test 2 (Floyd's): No cycle detected." << endl;
    }

    // Clean up memory for the second list
    ListNode* temp = head2;
    while (temp != nullptr) {
        ListNode* to_delete = temp;
        temp = temp->next;
        delete to_delete;
    }

    return 0;
}
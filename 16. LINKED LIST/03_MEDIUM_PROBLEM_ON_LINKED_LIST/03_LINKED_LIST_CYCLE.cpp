/*
#LINKED LIST CYCLE

LINK:- https://leetcode.com/problems/linked-list-cycle/description/
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
In this method, we use slow and fast pointer to detect cycle in linked list

if there any cycle exists, slow and fast pointer ultimately point towards the same node once while iterating
*/
class Solution_using_floyd_cycle_detection {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

/*
* How it works:
    1.  Initialize an empty hash set.
    2.  Iterate through the linked list, node by node.
    3.  For each node, check if it's already in the hash set.
        * If it is, you've found a cycle, so return true.
    4.  If the node is not in the set, add it and continue to the next node.
    5.  If you reach the end of the list (nullptr), there is no cycle, so return false.
*/

class Solution_using_hash_set {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> hashset;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (hashset.find(temp) != hashset.end())
                return true;
            hashset.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};


int main() {
    // Test Case 1: Linked list with a cycle
    ListNode* head_with_cycle = new ListNode(3);
    head_with_cycle->next = new ListNode(2);
    head_with_cycle->next->next = new ListNode(0);
    head_with_cycle->next->next->next = new ListNode(-4);
    head_with_cycle->next->next->next->next = head_with_cycle->next; // Creates a cycle

    // Test the solution using Floyd's algorithm
    Solution_using_floyd_cycle_detection floyd_solver;
    bool hasCycleFloyd = floyd_solver.hasCycle(head_with_cycle);
    cout << "Test 1 (Floyd's): List has cycle? " << (hasCycleFloyd ? "Yes" : "No") << endl;

    // Test the solution using a hash set
    Solution_using_hash_set hash_solver;
    bool hasCycleHash = hash_solver.hasCycle(head_with_cycle);
    cout << "Test 1 (Hash Set): List has cycle? " << (hasCycleHash ? "Yes" : "No") << endl;

    // Clean up memory to prevent memory leak (for the nodes not part of the cycle)
    delete head_with_cycle->next->next->next;
    delete head_with_cycle->next->next;
    delete head_with_cycle->next;
    delete head_with_cycle;


    // Test Case 2: Linked list without a cycle
    ListNode* head_no_cycle = new ListNode(1);
    head_no_cycle->next = new ListNode(2);
    head_no_cycle->next->next = new ListNode(3);

    // Test the solution using Floyd's algorithm
    hasCycleFloyd = floyd_solver.hasCycle(head_no_cycle);
    cout << "\nTest 2 (Floyd's): List has cycle? " << (hasCycleFloyd ? "Yes" : "No") << endl;

    // Test the solution using a hash set
    hasCycleHash = hash_solver.hasCycle(head_no_cycle);
    cout << "Test 2 (Hash Set): List has cycle? " << (hasCycleHash ? "Yes" : "No") << endl;

    // Clean up memory
    delete head_no_cycle->next->next;
    delete head_no_cycle->next;
    delete head_no_cycle;

    return 0;
}
/*
#ROTATE LIST

LINK:- https://leetcode.com/problems/rotate-list/description/
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
# Rotate List - Logic & Revision

## Problem Logic
Rotate linked list to the right by k positions.

## Core Logic Flow

### 1. Handle Edge Cases & Optimization
cpp
if(head == nullptr || head->next == nullptr) return head;
int rotate = k % len;  // Handle k > len
if(rotate == 0) return head;  // No rotation needed


### 2. Two-Pointer Strategy Logic

Goal: Find the new tail (break point) of rotated list

Key Insight: New tail is at position (len - k) from start
- If rotating right by k → last k nodes move to front
- Break point = len - k - 1 (0-indexed)

### 3. Fast Pointer Setup
cpp
for(int i = 0; i<rotate; i++)
    fast = fast->next;

Logic: Move fast pointer k steps ahead of slow
- Creates gap of exactly k nodes between pointers

### 4. Find Break Point
cpp
while(fast->next != nullptr)
    slow = slow->next, fast = fast->next;

Logic: When fast reaches last node, slow is at break point
- Slow points to new tail
- Slow->next points to new head

### 5. Perform Rotation
cpp
newHead = slow->next;  // New head
slow->next = nullptr;  // Break the list
fast->next = head;     // Connect old tail to old head


## Mental Model
Original: 1→2→3→4→5, k=2, rotate=2
Find Break: slow at position 2 (node 3), fast at position 4 (node 5)
Result: 4→5→1→2→3

Two-pointer maintains constant gap → when one reaches end, other is at exact break point

## Key Implementation Points
- Modulo optimization: k % len handles k > list length
- Gap technique: k-step gap finds break point in one pass
- Three connections: new_tail→null, old_tail→old_head, return new_head

Time: O(n) | Space: O(1)
*/
class Solution {
public:
    int calclen(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = calclen(head);
        int rotate = k % len;

        if (rotate == 0) return head;

        ListNode* newHead = nullptr;
        ListNode* fast = head;
        for (int i = 0; i < rotate; i++) {
            if (fast->next != nullptr) fast = fast->next;
        }

        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
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

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Test Case 1: Simple rotation
    // List: 1 -> 2 -> 3 -> 4 -> 5, k = 2
    // Result: 4 -> 5 -> 1 -> 2 -> 3
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    ListNode* head1 = createList(nums1);
    cout << "Original list: ";
    display(head1);
    int k1 = 2;
    ListNode* result1 = sol.rotateRight(head1, k1);
    cout << "Rotated list (k=" << k1 << "): ";
    display(result1);
    cout << "---------------------------------------" << endl;

    // Test Case 2: Rotation with k > length
    // List: 0 -> 1 -> 2, k = 4
    // Effective rotation: 4 % 3 = 1
    // Result: 2 -> 0 -> 1
    vector<int> nums2 = { 0, 1, 2 };
    ListNode* head2 = createList(nums2);
    cout << "Original list: ";
    display(head2);
    int k2 = 4;
    ListNode* result2 = sol.rotateRight(head2, k2);
    cout << "Rotated list (k=" << k2 << "): ";
    display(result2);
    cout << "---------------------------------------" << endl;

    // Test Case 3: Rotation with k = length
    // List: 1, k = 1
    // Effective rotation: 1 % 1 = 0
    // Result: 1
    vector<int> nums3 = { 1 };
    ListNode* head3 = createList(nums3);
    cout << "Original list: ";
    display(head3);
    int k3 = 1;
    ListNode* result3 = sol.rotateRight(head3, k3);
    cout << "Rotated list (k=" << k3 << "): ";
    display(result3);
    cout << "---------------------------------------" << endl;

    return 0;
}
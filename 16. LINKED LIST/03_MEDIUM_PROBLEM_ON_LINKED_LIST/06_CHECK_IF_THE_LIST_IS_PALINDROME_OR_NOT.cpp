/*
#PALINDROME LINKED LIST

LINK:- https://leetcode.com/problems/palindrome-linked-list/description/
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
Palindrome Linked List - Logic:

Problem: Check if linked list reads the same forwards and backwards.

Approach: Reverse first half and compare with second half.

Algorithm:
1. Calculate length of linked list
2. Reverse first half:
   - Traverse len/2 nodes while reversing links
   - prev points to reversed first half, curr points to second half start
3. Handle odd length: If odd, skip middle element (curr = curr->next)
4. Compare halves:
   - Compare prev (reversed first half) with curr (second half)
   - If any values don't match → not palindrome
5. Final check: Both pointers should reach null simultaneously

Key Steps:
- travel = len/2 → reverse exactly half the nodes
- if(len & 1) curr = curr->next → skip middle node for odd length
- Compare node by node: prev->val != curr->val

Example: 1→2→3→2→1
- After reversing first half: prev: 2→1, curr: 3→2→1
- Skip middle: curr: 2→1
- Compare: 2==2, 1==1 → palindrome

Time: O(n), Space: O(1)

Note: This modifies the original list structure during execution.
*/
class Solution {
public:
    bool isPalindrome(ListNode*& head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int travel = len / 2;
        while (travel > 0) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            travel--;
        }

        if (len & 1)curr = curr->next;
        while (prev != nullptr) {
            if (prev->val != curr->val) {
                return false;
            }

            prev = prev->next;
            curr = curr->next;
        }

        if ((prev != nullptr && curr == nullptr) || (prev == nullptr && curr != nullptr)) {
            return false;
        }

        return true;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to delete the linked list nodes
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test Case 1: Palindrome list (odd number of nodes)
    vector<int> nums1 = { 1, 2, 3, 2, 1 };
    ListNode* head1 = createLinkedList(nums1);
    cout << "Is {1, 2, 3, 2, 1} a palindrome? " << (sol.isPalindrome(head1) ? "true" : "false") << endl;
    deleteLinkedList(head1);

    // Test Case 2: Not a palindrome list
    vector<int> nums2 = { 1, 2, 3, 4, 5 };
    ListNode* head2 = createLinkedList(nums2);
    cout << "Is {1, 2, 3, 4, 5} a palindrome? " << (sol.isPalindrome(head2) ? "true" : "false") << endl;
    deleteLinkedList(head2);

    // Test Case 3: Palindrome list (even number of nodes)
    vector<int> nums3 = { 1, 2, 2, 1 };
    ListNode* head3 = createLinkedList(nums3);
    cout << "Is {1, 2, 2, 1} a palindrome? " << (sol.isPalindrome(head3) ? "true" : "false") << endl;
    deleteLinkedList(head3);

    // Test Case 4: Single node list
    vector<int> nums4 = { 1 };
    ListNode* head4 = createLinkedList(nums4);
    cout << "Is {1} a palindrome? " << (sol.isPalindrome(head4) ? "true" : "false") << endl;
    deleteLinkedList(head4);

    // Test Case 5: Empty list
    vector<int> nums5 = {};
    ListNode* head5 = createLinkedList(nums5);
    cout << "Is {} a palindrome? " << (sol.isPalindrome(head5) ? "true" : "false") << endl;
    deleteLinkedList(head5);

    return 0;
}
/*
#INTERSECTION OF TWO LINKED LIST

LINK:- https://leetcode.com/problems/intersection-of-two-linked-lists/

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
## Key Concept
Two-pointer technique with length alignment

## Algorithm Steps

### 1. Calculate Lengths
- Traverse both lists to find their lengths
- Use simple counter loop: while (head != nullptr)

### 2. Align Starting Points
- Find difference: diff = abs(lenA - lenB)
- Move the pointer of the longer list forward by diff positions
- Now both pointers are equidistant from potential intersection

### 3. Find Intersection
- Move both pointers simultaneously (one step each)
- Compare pointers (not values): if (pA == pB)
- Return the node when pointers meet

## Important Points

Pointer Comparison vs Value Comparison
- Use pA == pB (memory address comparison)
- NOT pA->val == pB->val (value comparison)

Edge Cases
- No intersection → return nullptr
- Different lengths → align first, then traverse
- Same lengths → direct simultaneous traversal

## Time & Space Complexity
- Time: O(m + n) where m, n are list lengths
- Space: O(1) - only using pointers


## Code Pattern
1. Helper function to calculate length
2. Align longer list's starting position
3. Traverse both lists simultaneously
4. Return intersection node or nullptr
*/
class Solution {
public:
    int len(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = len(headA);
        int lenB = len(headB);

        int diff = abs(lenA - lenB);

        ListNode* pA = headA;
        ListNode* pB = headB;

        if (lenA > lenB) {
            while (diff) {
                pA = pA->next;
                diff--;
            }
        }
        else if (lenB > lenA) {
            while (diff) {
                pB = pB->next;
                diff--;
            }
        }

        while (pA != nullptr && pB != nullptr) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }

        return nullptr;
    }
};

void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Intersecting lists
    // List A: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    // List B: 8 -> 9 -> 5 (intersection at node with value 5)
    ListNode* intersection = new ListNode(5);
    intersection->next = new ListNode(6);
    intersection->next->next = new ListNode(7);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = intersection;

    ListNode* headB = new ListNode(8);
    headB->next = new ListNode(9);
    headB->next->next = intersection;

    cout << "Test Case 1: Intersecting Lists" << endl;
    cout << "List A: ";
    display(headA);
    cout << "List B: ";
    display(headB);

    ListNode* intersectNode1 = sol.getIntersectionNode(headA, headB);
    if (intersectNode1) {
        cout << "Intersection found at node with value: " << intersectNode1->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }
    cout << "---------------------------------------" << endl;

    // Test Case 2: Non-intersecting lists
    // List A: 1 -> 2 -> 3
    // List B: 4 -> 5 -> 6
    ListNode* headA_no_intersect = new ListNode(1);
    headA_no_intersect->next = new ListNode(2);
    headA_no_intersect->next->next = new ListNode(3);

    ListNode* headB_no_intersect = new ListNode(4);
    headB_no_intersect->next = new ListNode(5);
    headB_no_intersect->next->next = new ListNode(6);

    cout << "Test Case 2: Non-Intersecting Lists" << endl;
    cout << "List A: ";
    display(headA_no_intersect);
    cout << "List B: ";
    display(headB_no_intersect);

    ListNode* intersectNode2 = sol.getIntersectionNode(headA_no_intersect, headB_no_intersect);
    if (intersectNode2) {
        cout << "Intersection found at node with value: " << intersectNode2->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }

    // Clean up memory
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB->next->next;
    delete headB->next;
    delete headB;

    delete headA_no_intersect->next->next;
    delete headA_no_intersect->next;
    delete headA_no_intersect;
    delete headB_no_intersect->next->next;
    delete headB_no_intersect->next;
    delete headB_no_intersect;

    return 0;
}
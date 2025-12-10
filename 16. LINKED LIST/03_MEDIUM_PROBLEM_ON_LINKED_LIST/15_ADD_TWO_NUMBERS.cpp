/*
#ADD_TWO NUMBERS

LINK:- https://leetcode.com/problems/add-two-numbers/
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
### 1. Handle Base Cases

if (both null) → return null
if (one null) → return the other


### 2. Setup Addition Process

Dummy node → simplifies result building
carry = 0 → tracks overflow from previous digit


### 3. Main Addition Loop
Logic: while (A != nullptr || B != nullptr)
- Why ||? Continue until both lists exhausted
- Start with sum = carry (from previous iteration)
- Add current digits if nodes exist
- Extract: digit = sum % 10, new carry = sum / 10

### 4. Handle Final Carry
After loop ends, if carry > 0 → create one more node

## Key Implementation Logic

Null Safety Pattern:

if (A != nullptr) {
    sum += A->val;
    A = A->next;
}


## Mental Model
Think of it as elementary school addition:
1. Add column by column (right to left)
2. Write down units digit
3. Carry tens digit to next column
4. Don't forget final carry!

Time: O(max(m,n)) | Space: O(max(m,n))
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* A = l1;
        ListNode* B = l2;
        ListNode* Dummy = new ListNode(0); // Dummy node to simplify head creation
        ListNode* temp = Dummy;

        int carry = 0;

        while (A != nullptr || B != nullptr) { // Changed condition to handle remaining nodes
            int sum = carry;
            if (A != nullptr) {
                sum += A->val;
                A = A->next;
            }
            if (B != nullptr) {
                sum += B->val;
                B = B->next;
            }

            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }

        // Handle the final carry if it exists
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }

        ListNode* result = Dummy->next;
        delete Dummy;
        return result;
    }
};

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Simple Addition
    // l1 = 2 -> 4 -> 3 (represents 342)
    // l2 = 5 -> 6 -> 4 (represents 465)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "Test Case 1: Simple Addition" << endl;
    cout << "l1: ";
    display(l1);
    cout << "l2: ";
    display(l2);
    ListNode* result1 = sol.addTwoNumbers(l1, l2);
    cout << "Result: ";
    display(result1); // Expected: 7 -> 0 -> 8 (807)
    cout << "---------------------------------------" << endl;

    // Test Case 2: Uneven Lengths
    // l1 = 9 -> 9 (represents 99)
    // l2 = 1 -> 8 -> 9 (represents 981)
    ListNode* l3 = new ListNode(9);
    l3->next = new ListNode(9);

    ListNode* l4 = new ListNode(1);
    l4->next = new ListNode(8);
    l4->next->next = new ListNode(9);

    cout << "Test Case 2: Uneven Lengths" << endl;
    cout << "l3: ";
    display(l3);
    cout << "l4: ";
    display(l4);
    ListNode* result2 = sol.addTwoNumbers(l3, l4);
    cout << "Result: ";
    display(result2); // Expected: 0 -> 8 -> 0 -> 1 (1080)
    cout << "---------------------------------------" << endl;

    // Test Case 3: Final Carry
    // l1 = 9 -> 9 (represents 99)
    // l2 = 1 (represents 1)
    ListNode* l5 = new ListNode(9);
    l5->next = new ListNode(9);

    ListNode* l6 = new ListNode(1);

    cout << "Test Case 3: Final Carry" << endl;
    cout << "l5: ";
    display(l5);
    cout << "l6: ";
    display(l6);
    ListNode* result3 = sol.addTwoNumbers(l5, l6);
    cout << "Result: ";
    display(result3); // Expected: 0 -> 0 -> 1 (100)
    cout << "---------------------------------------" << endl;

    // Deallocate memory for all created lists
    auto cleanup = [](ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        };
    cleanup(l1);
    cleanup(l2);
    cleanup(result1);
    cleanup(l3);
    cleanup(l4);
    cleanup(result2);
    cleanup(l5);
    cleanup(l6);
    cleanup(result3);

    return 0;
}
/*
#REVERSE LL IN GROUP OF GIVEN SIZE K

LINK:- https://leetcode.com/problems/reverse-nodes-in-k-group/

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
### 1. Helper Function - Standard Reverse
cpp
ListNode* reverse(ListNode* head)

Logic: 3-pointer technique (prev, curr, temp)
- Save next: temp = curr->next
- Reverse link: curr->next = prev
- Move forward: prev = curr, curr = temp

### 2. Main Logic Flow

Key Variables:
- begin → start of current k-group
- curr → traversal pointer
- prev → end of previous reversed group
- Head2 → final result head

### 3. K-Group Processing Logic

Step 1: Find K-Group
cpp
for(int i = 0; i<k-1; i++)  // Move k-1 steps from begin

- If we can't move k-1 steps → incomplete group → break

Step 2: Isolate K-Group
cpp
ListNode* temp = curr->next;  // Save what comes after
curr->next = nullptr;         // Cut the k-group


Step 3: Reverse Isolated Group
cpp
ListNode* newHead = reverse(begin);


Step 4: Connect Reversed Group
- Connect previous group's tail → prev->next = newHead
- Find new tail of reversed group
- Connect to remaining list → tail->next = temp

### 4. Connection Logic

First Group: Head2 = newHead (save final result head)
Subsequent Groups: prev->next = newHead (chain groups)
Update for Next: prev = tail (tail becomes new prev)

## Key Implementation Insights

Why isolate groups?
- curr->next = nullptr ensures reverse() only reverses k nodes
- Clean separation prevents accidentally reversing too much

Tail Finding Logic:
cpp
while(tail != nullptr && tail->next != nullptr)

- After reverse, original begin becomes tail
- Need to find actual tail to connect next group

Edge Case Handling:
- Incomplete final group → don't reverse, return as-is
- First group → save as final head
- Empty list → return original head

## Mental Model
1. Slide window of size k through list
2. Cut out each k-group
3. Reverse in isolation
4. Stitch back into main list
5. Repeat until insufficient nodes

Example: 1→2→3→4→5 with k=3
- Cut: 1→2→3, reverse to 3→2→1
- Connect: 3→2→1→4→5

Time: O(n) | Space: O(1)
*/
class Solution_My_solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* begin = nullptr;
        ListNode* Head2 = nullptr;
        while (curr != nullptr) {
            if (begin == nullptr) {
                begin = curr;
            }
            for (int i = 0; i < k - 1; i++) {
                if (curr != nullptr) curr = curr->next;
                else break;
            }
            if (curr == nullptr) break;

            ListNode* temp = curr->next;
            curr->next = nullptr;
            if (prev != nullptr) prev->next = nullptr;
            ListNode* newHead = reverse(begin);
            if (Head2 == nullptr) Head2 = newHead;

            if (prev != nullptr) {
                prev->next = newHead;
            }
            ListNode* tail = newHead;
            while (tail != nullptr && tail->next != nullptr) {
                tail = tail->next;
            }

            tail->next = temp;
            prev = tail;
            curr = temp;
            begin = nullptr;
        }

        return (Head2 != nullptr) ? Head2 : head;
    }
};


class Solution_with_recursion {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* tail = head;
        for (int i = 0; i < k; ++i) {
            if (!tail) return head;
            tail = tail->next;
        }

        ListNode* newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }

private:
    ListNode* reverse(ListNode* cur, ListNode* end) {
        ListNode* prev = nullptr;
        while (cur != end) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
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
    Solution_My_solution my_solver;
    Solution_with_recursion recursive_solver;

    // Test Case 1: My iterative solution
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    int k1 = 2;
    ListNode* head1 = createList(nums1);
    cout << "My Solution (Iterative):" << endl;
    cout << "Original List: ";
    display(head1);
    ListNode* result1 = my_solver.reverseKGroup(head1, k1);
    cout << "Reversed in groups of " << k1 << ": ";
    display(result1);
    cout << "---------------------------------------" << endl;

    // Test Case 2: My iterative solution with incomplete final group
    vector<int> nums2 = { 1, 2, 3, 4, 5, 6, 7 };
    int k2 = 3;
    ListNode* head2 = createList(nums2);
    cout << "My Solution (Iterative with incomplete group):" << endl;
    cout << "Original List: ";
    display(head2);
    ListNode* result2 = my_solver.reverseKGroup(head2, k2);
    cout << "Reversed in groups of " << k2 << ": ";
    display(result2);
    cout << "---------------------------------------" << endl;

    // Test Case 3: Recursive solution
    vector<int> nums3 = { 1, 2, 3, 4, 5 };
    int k3 = 2;
    ListNode* head3 = createList(nums3);
    cout << "Recursive Solution:" << endl;
    cout << "Original List: ";
    display(head3);
    ListNode* result3 = recursive_solver.reverseKGroup(head3, k3);
    cout << "Reversed in groups of " << k3 << ": ";
    display(result3);
    cout << "---------------------------------------" << endl;

    // Test Case 4: Recursive with incomplete group
    vector<int> nums4 = { 1, 2, 3, 4, 5, 6, 7 };
    int k4 = 3;
    ListNode* head4 = createList(nums4);
    cout << "Recursive Solution (with incomplete group):" << endl;
    cout << "Original List: ";
    display(head4);
    ListNode* result4 = recursive_solver.reverseKGroup(head4, k4);
    cout << "Reversed in groups of " << k4 << ": ";
    display(result4);

    return 0;
}
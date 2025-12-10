/*
#SORT LINKED LIST

LINK:- https://leetcode.com/problems/sort-list/description/
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


//BRUTE FORCE
class Solution_Taking_extra_space {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> store;
        ListNode* temp = head;
        while (temp != nullptr) {
            int data = temp->val;
            store.push_back(data);
            temp = temp->next;
        }

        sort(store.begin(), store.end());

        temp = head;
        for (int i = 0; i < store.size(); i++) {
            temp->val = store[i];
            temp = temp->next;
        }

        return head;
    }
};

//TIME COMPLEXITY :- O(NLOGN)
//SPACE COMPLEXITY :- O(1)
class Solution_using_merge_sort_concept {
public:
    ListNode* middle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* leftHead, ListNode* rightHead) {
        ListNode* Dummy = new ListNode(0);
        ListNode* current = Dummy;

        while (leftHead != nullptr && rightHead != nullptr) {
            if (leftHead->val <= rightHead->val) {
                current->next = leftHead;
                leftHead = leftHead->next;
            }
            else {
                current->next = rightHead;
                rightHead = rightHead->next;
            }
            current = current->next;
        }

        if (leftHead != nullptr) {
            current->next = leftHead;
        }
        else {
            current->next = rightHead;
        }

        ListNode* merged_head = Dummy->next;
        delete Dummy;
        return merged_head;
    }

    ListNode* mergeSort(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = middle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        ListNode* result = merge(leftHead, rightHead);

        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        return mergeSort(head);
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

int main() {
    // Create an unsorted linked list: 4 -> 2 -> 1 -> 3 -> 5
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    cout << "Original unsorted list:" << endl;
    display(head);

    // Test the merge sort solution
    Solution_using_merge_sort_concept merge_sorter;
    ListNode* sorted_head = merge_sorter.sortList(head);
    cout << "Sorted list using Merge Sort:" << endl;
    display(sorted_head);

    // To test the brute force solution, we need to create a new list
    ListNode* head2 = new ListNode(4);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(1);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(5);

    cout << "\nOriginal unsorted list for brute force:" << endl;
    display(head2);

    // Test the brute force solution
    Solution_Taking_extra_space brute_force_sorter;
    ListNode* sorted_head2 = brute_force_sorter.sortList(head2);
    cout << "Sorted list using Brute Force:" << endl;
    display(sorted_head2);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

//declaration of node data structure
class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void display(Node* head) {
    if (head->next == nullptr) {
        cout << "EMPTY LINKED LIST";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }cout << endl;
}

int lengthOfLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool search(Node* head, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    vector<int> arr = { 2, 5, 8, 7 };
    /*
    1. It returns a pointer (Node*) to the starting address of the newly created Node object.
    This address is then stored in the newNode pointer variable.

    2. This line creates a Node object on the heap (dynamic memory) and assigns its memory
    address to the pointer variable y.

    3. The Node object itself is allocated on the heap using the new keyword. It will persist until you explicitly
    delete it. This is the standard way to create nodes for a linked list.
    */
    Node* y = new Node(arr[0]);    //dynamic memory allocation. y stores a memory address
    cout << y << endl;
    cout << y->data << endl;    // -> used to access value 
    cout << y->next << endl;    // -> used to access next pointing address value

    /*
    1. This line creates a Node object on the stack (automatic memory) and assigns its value to the variable obj.

    2. Variable obj: Is a direct instance of the Node class. It contains the actual data of the object. When you
    print cout << obj.next << endl;, you are accessing the value of the next member variable of the obj object.
    Since it was initialized with nullptr, the output will be 0.

    3. Memory: The Node object itself is allocated on the stack. Its memory will be automatically deallocated when
    the program exits the scope in which obj was created.
    */
    Node obj = Node(arr[0]);
    cout << obj.data << endl;

    vector<int> nums = { 3,4,5,6 };
    Node* head = convertArr2LL(nums);
    cout << head->data << endl;
    display(head);
    cout << "Length of Linked list is:- " << lengthOfLL(head) << endl;
    search(head, 5) ? cout << "PRESENT" : cout << "NOT PRESENT";
    return 0;
}
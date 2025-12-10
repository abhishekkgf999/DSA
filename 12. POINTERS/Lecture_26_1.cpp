//POINTERS FOR ARRAYS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {23, 122, 41, 67};

    // Array name itself is the address of the first memory block of the entire array
    cout<<"Address of first memory block is :- "<<arr<<endl;
    cout<<arr[0]<<endl;
    // &arr[0] also gives the address of the first memory block
    cout<<"Address of first memory block is :- "<<&arr[0]<<endl;
    // Dereference operator * can be used to get the value at the first memory block
    cout<<"using dereference operator "<<*arr<<endl;
    // Incrementing the value of the first element by 1
    cout<<"Incrementing first element by 1 :- "<<*arr + 1<<endl;
    cout<<"Incrementing first element by 1 :- "<<*(arr) + 1<<endl;
    // Accessing the second element using pointer arithmetic
    cout<<"Accessing the second element:- "<<*(arr+1)<<endl;

    // arr[i] == *(arr + i)
    // i[arr] == *(i + arr), which is equivalent to arr[i]
    cout<<arr[2]<<endl;   // arr[2] == *(arr + 2)
    int i = 3;
    cout<<i[arr]<<endl; // 3[arr] == *(3 + arr)

    // Size of entire array
    int temp[10] = {1, 2};
    cout<<"Size of entire array is:- "<<sizeof(temp)<<endl;
    // Size of the value at temp (first element of the array)
    cout<<"Size of value at temp is:- "<<sizeof(*temp)<<endl;
    // Size of address of temp (address of the first memory block)
    cout<<"Size of address of temp is:- "<<sizeof(&temp)<<endl;

    // Size of a pointer to the first element of the array
    int *ptr = &temp[0];
    cout<<"Size of ptr is:- "<<sizeof(ptr)<<endl;
    // Size of the value at ptr (value at the first memory block)
    cout<<"Size of value at ptr is:- "<<sizeof(*ptr)<<endl;
    // Size of the address of ptr (size of the pointer itself)
    cout<<"Size of memory of ptr is:- "<<sizeof(&ptr)<<endl;

    // Address of the first memory block of array a
    int a[20] = {1,2,3,5};
    cout<<&a[0]<<endl;
    // Address of the entire array a
    cout<<&a<<endl;
    // Address of the first memory block, which is the same as &a[0]
    cout<<a<<endl;

    // Working with pointers
    int *p = &a[0];
    cout<<"value stored at p: "<<p<<endl;
    // Value stored at the address contained in p
    cout<<"value stored at address stored in p: "<<*p<<endl;
    // Address of the pointer variable p
    cout<<"Address of pointer p: "<<&p<<endl;

    // Uncommenting the next line will cause an error because array names are constant pointers and cannot be changed
    // a = a+1;

    cout<<"Before moving pointer: "<<p<<endl;
    // Moving the pointer to the next memory block
    p = p+1;
    cout<<"After updating pointer: "<<p<<endl;
    // Address of the second block of the array is the same as the updated pointer
    cout<<"Address of 2nd block of array is same as pointer: "<<&a[1]<<endl;

    return 0;
}

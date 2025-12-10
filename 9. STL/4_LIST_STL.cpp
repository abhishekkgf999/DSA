/*
==> Lists are sequence containers that allow non-contiguous memory allocation. As compared to the 
    vector, the list has slow traversal, but once a position has been found, insertion and deletion 
    are quick (constant time). Normally, when we say a List, we talk about a doubly linked list. For 
    implementing a singly linked list, we use a forward_list.

==> std::list is the class of the List container. It is the part of C++ Standard Template Library (STL) 
    and is defined inside <list> header file.

*/

#include<iostream>
#include<list>
using namespace std;

int main(){
    
    list<int> l;    //DEFINING LIST THROUGH STL

    list<int> new_list(l);  //CREATE COPY OF LIST l;

    list<int> a(5, 100);    //INITIALIZING ITS SIZE AND FILLING WITH ALL ELEMENTS WITH 100;

    l.push_back(1);
    l.push_front(2);

    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;

    l.erase(l.begin());
    cout<<"after erase"<<endl;
    for(int i : l){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}
/*
A Vectors in C++ can resize itself when more elements are added. It also allows deletion of elements.
Below is a very basic idea when array becomes full and user wishes to add an item.
1) Create a bigger sized memory on heap memory (for example memory of double size).
2) Copy current memory elements to the new memory.
3) New item is added now as there is bigger memory available now.
4) Delete the old memory.

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> a; // THATS HOW WE CREATE VECTOR IN STL

    cout << "Size--> " << a.capacity() << endl; // capacity() KEYWORD IS TO FIND HOW MUCH SIZE IS ALLOCATED TO THAT

    a.push_back(1); // ADDING ELEMENT IN VECTOR THROUGH push_back function, it adds element at the end;
    cout << "Size--> " << a.capacity() << endl;

    a.push_back(2);
    cout << "Size--> " << a.capacity() << endl;

    a.push_back(3);
    cout << "Size--> " << a.capacity() << endl;

    a.push_back(6);
    a.push_back(5);

    cout << "Size--> " << a.capacity() << endl; //at every time when we try to add element out of its range, it automatically double its size
    cout<<"how many elements inside vector:- "<<a.size()<<endl; //return the count of elements inside the vector

    cout<<"Element at 2nd index:- "<<a.at(1)<<endl; 

    cout<<"front element:- "<<a.front()<<endl;  //IT WILL GIVE 1ST ELEMENT OF VECTOR
    cout<<"last element:- "<<a.back()<<endl;    //IT WILL GIVE LAST ELEMENT OF VECTOR

    cout<<"BEFORE POP FUNCTOIN"<<endl;
    for(int i : a){
        cout<<i<<" ";
    }
    cout<<endl;

    a.pop_back();   //IT REMOVES ELEMENT FROM BACK OF THE VECTOR;
    cout<<"AFTER POP FUNCTOIN"<<endl;
    for(int i : a){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"before clear size is:- "<<a.size()<<endl;
    a.clear();
    cout<<"after clear size is:- "<<a.size()<<endl;

    //we can also declare a vector with defining its size, and filling entire vector with same elements

    vector<int> v(5, 100);  //defining a vector with all elements with 100
    cout<<"elements inside vector v is:- ";
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    // we can also copy a vector

    vector<int> newvector(v);
    cout<<"elements inside newvector is:- ";
    for(int i : newvector){
        cout<<i<<" ";
    }

    return 0;
}
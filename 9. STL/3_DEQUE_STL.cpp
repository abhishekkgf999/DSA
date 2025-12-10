/*
==> Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. 
    They are similar to vectors, but are more efficient in case of insertion and deletion of elements. 
    Unlike vectors, contiguous storage allocation may not be guaranteed. 



==> Double Ended Queues are basically an implementation of the data structure double-ended queue. A queue data 
    structure allows insertion only at the end and deletion from the front. This is like a queue in real life, 
    wherein people are removed from the front and added at the back. Double-ended queues are a special case of 
    queues where insertion and deletion operations are possible at both the ends.




The functions for deque are same as vector, with an addition of push and pop operations for both front and back.  

The time complexities for doing various operations on deques are-

Accessing Elements- O(1)
Insertion or removal of elements- O(N)
Insertion or removal of elements at start or end- O(1)
*/

#include<iostream>
#include<deque>
using namespace std;

int main(){
    
    deque<int> d;

    d.push_back(1);     //adds element to back 
    d.push_front(2);    //adds element from front
    d.push_back(3);

    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;

    // d.pop_back();   //removes element from back
    // for(int i : d){
    //     cout<<i<<" ";
    // }cout<<endl;

    // d.pop_front();  //removes element from fronT
    // for(int i : d){
    //     cout<<i<<" ";
    // }cout<<endl;

    cout<<"Printing 1st element:- "<<d.at(0)<<endl;

    cout<<"empty or not "<<d.empty()<<endl; 

    cout<<"Printing 2nd element:- "<<d.at(1)<<endl;
    cout<<"1st element is:- "<<d.front()<<endl;
    cout<<"last element is:- "<<d.back()<<endl;

    cout<<"before erase:- "<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+1);  //we have to give from where to where we have to delete the elements
    cout<<"after erase:- "<<d.size()<<endl;

    for(int i : d){
        cout<<i<<" ";
    }cout<<endl;


    return 0;
}
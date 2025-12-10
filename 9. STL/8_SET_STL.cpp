/*
==> Sets are a type of associative container in which each element has to be unique because the value of the 
    element identifies it. The values are stored in a specific sorted order i.e. either ascending or descending.
*/

#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int> s; //DEFINING SET THROUGH STL

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(int i : s){
        cout<<i<<" ";
    }cout<<endl;

    set<int> :: iterator it = s.begin();    //Defining iterator 
    advance(it, 3); //setting iterator value to 3

    s.erase(it);    //deleting iterator index
    for(auto i : s){
        cout<<i<<" ";
    }cout<<endl;
    
    cout<<"5 is present or not --> "<<s.count(5)<<endl;
    cout<<"-5 is present or not --> "<<s.count(-5)<<endl;

    set<int> :: iterator itr = s.find(5);       //if 5 is present, it gives its iterator

    for(auto it = itr; it!= s.end(); it++){
        cout<<*it<<" ";
    }cout<<endl;

    return 0;
}
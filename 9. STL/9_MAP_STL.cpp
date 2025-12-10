/*
==> Maps are associative containers that store elements in a mapped fashion. Each element has a key value and 
    a mapped value. No two mapped values can have the same key values.
*/

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<int, string> m;

    m[1] = "Abhishek";
    m[13] = "kumar";
    m[2] = "Gautam";

    m.insert( { 5, "bheem"});

    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"finding 13 -- > "<<m.count(13)<<endl;
    cout<<"finding -13 -- > "<<m.count(-13)<<endl;

    cout<<"before erase "<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    m.erase(13);
    cout<<"after erase"<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<endl;
    return 0;
}
/*
#REMOVE ALL OCCURANCES OF STRING

LINK:- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
*/


#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }

int main(){
     string s;
    cout<<"enter your string"<<endl;
    getline(cin, s);

    string part;
    cout<<"Enter part to delete all occrances:- "<<endl;
    getline(cin, part);
    cout<<removeOccurrences(s, part)<<endl;
    return 0;
}
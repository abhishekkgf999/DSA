#include<iostream>
#include<string>
using namespace std;

void reverse_String(string &str, int start, int end){
    if(start>end){
        return;
    }

    swap(str[start], str[end]);
    start++;
    end--;

    reverse_String(str, start, end);
}

int main(){
    string name = "Abhishek";
    reverse_String(name, 0, name.length()-1);
    cout<<endl<<endl;
    cout<<name;
    return 0;
}
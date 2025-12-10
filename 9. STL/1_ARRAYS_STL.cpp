//STL FOR ARRAYS
// GENERALLY NOT PREFFERED DUE TO STATIC IN NATURE

#include<iostream>
#include<array>
using namespace std;

int main(){
    int basic[] = {1, 2, 3};    //DEFAULT ARRAY

    array<int, 4> a = {1, 2, 3, 4};     //STL ARRAY DECLARATION METHOD

    int size = a.size();
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Element at 3rd index is:- "<<a.at(3)<<endl;

    cout<<"Empty or not:- "<<a.empty()<<endl;   //empty() operator gives bool value, if empty gives 0, otherwise 1

    cout<<"First Element--> "<<a.front()<<endl; //we can access front element by this operator
    cout<<"Last Element--> "<<a.back()<<endl;   //we can access last element by this operator


    return 0;
}
#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int size;
    cout<<"enter size of an array"<<endl;
    cin>>size;

    int array[100000];
    cout<<"Enter elements of an array"<<endl;
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    cout<<"Enter element to search in given array"<<endl;
    int key;
    cin>>key;

    bool present = search(array, size, key);
    if(present){
        cout<<key<<" is present in given array"<<endl;
    }
    else{
        cout<<key<<" is not present in given array"<<endl;
    }

    return 0;
}
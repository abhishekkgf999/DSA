#include<iostream>
using namespace std;

void printArray(char arr[], int size){
    cout<<"Printing the array"<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Printing done"<<endl;
}

int main(){
    //declare
    int number[15];

    cout<<"Value at 0 index is:- "<<number[0]<<endl;

    // cout<<"Value at 20 index is:- "<<number[20]<<endl;

    //initialising and array

    int second[3] = {5, 7, 11};

    //accessing an element
    cout<<"Value at 2nd index is:- "<<second[2]<<endl;

    int third[15] = {2, 7};

    //printing the array
    // printArray(third, 15);
    
    int fourth[10] = {0};  //We can initialize the array with any value by using the fill_n command 
    // printArray(fourth, 10);

    int fifth[10] = {1};
    int fifthSize = sizeof(fifth)/sizeof(int);
    cout<<"Size of Fifth is "<<fifthSize<<endl;


    //CHARACTER ARRAY
    char ch[50] = {'A', 'B', 'H', 'I', 'S', 'H', 'E', 'K'};
    printArray(ch, 8);
    
    cout<<endl<<"Everything is fine"<<endl;

    int arr[10];
    fill_n(arr,10,5);
    // SYNTAX:- fill_n(ForwardIterator first, Size n, const T& value)
    for(auto i :arr){
        cout<<i<<" ";
    }
    
    return 0;

}
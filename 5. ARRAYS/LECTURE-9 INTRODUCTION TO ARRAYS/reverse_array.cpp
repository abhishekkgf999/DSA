#include<iostream>
using namespace std;

void reverse(int arr[], int size){
    int start = 0;
    int end = size-1;
    for(; start<=end; start++, end--){
        swap(arr[start], arr[end]);
    }
}

void printarray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array1[5] = {1 ,2, 3 ,4 , 5};
    int array2[6] = {-1, -2, -5, 99, 88, 100};

    reverse(array1, 5);
    reverse(array2, 6);

    printarray(array1, 5);
    printarray(array2, 6);
    return 0;
}
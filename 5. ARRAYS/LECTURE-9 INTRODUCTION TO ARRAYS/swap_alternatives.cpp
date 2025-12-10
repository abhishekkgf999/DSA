#include<iostream>
using namespace std;

void swap_alternative(int arr[], int size){
    for(int i =0; i<size; i++){
        if(i+1<size){
            swap(arr[i], arr[i+1]);
        }
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

    swap_alternative(array1, 5);
    swap_alternative(array2, 6);

    printarray(array1, 5);
    printarray(array2, 6);
    return 0;
}
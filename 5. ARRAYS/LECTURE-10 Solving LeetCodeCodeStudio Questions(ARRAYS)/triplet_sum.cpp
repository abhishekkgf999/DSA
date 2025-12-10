#include<iostream>
using namespace std;

void swap_alternate(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+1<n){
            swap(arr[i], arr[i+1]);
        }
    }
}

void printarray(int arr[], int n){
    cout<<"NEW ARRAY AFTER SWAPPING ALTERNATE VALUES"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[6] = {1, 2, 3, 4, 5, 6};

    swap_alternate(array1, 5);
    swap_alternate(array2, 6);

    printarray(array1, 5);
    printarray(array2, 6);

    return 0;
}
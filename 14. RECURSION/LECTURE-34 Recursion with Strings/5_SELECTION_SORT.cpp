#include<iostream>
using namespace std;

//SELECTION SORT ALGORITHM
void sortArray(int *arr, int n){

    //BASE CASE
    if(n <=1 ) return;

    // Find the minimum element in the remaining array
    int min_index = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    // Swap the found minimum element with the first element
    swap(arr[0], arr[min_index]);

    sortArray(arr+1, n-1);

}


int main(){
    int arr[5] = {1,5,4,90,3};
    sortArray(arr, 5);
    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
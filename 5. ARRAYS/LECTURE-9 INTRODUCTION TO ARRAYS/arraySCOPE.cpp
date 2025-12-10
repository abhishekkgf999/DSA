#include<iostream>
using namespace std;

void update(int arr[], int n){
    cout<<endl<<"Inside the function"<<endl;

    //updating array's first element
    arr[0] = 143;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[3] = {0, 2, 4};

    update(arr, 3);

    for(int i=0; i<3; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
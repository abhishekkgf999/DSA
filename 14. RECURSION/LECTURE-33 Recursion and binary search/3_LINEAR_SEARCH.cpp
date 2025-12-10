#include<iostream>
using namespace std;


void print(int arr[], int size){
    cout<<"Sise of the array is:- "<<size<<endl;

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}
bool linearSearch(int arr[], int size, int key){

    print(arr, size);
    
    //BASE CASE
    if(size == 0){
        return false;
    }

    //PROCESS
    if(key == arr[0]){
        return true;
    }
    else{

        //RECURSIVE CALL
       return linearSearch(arr+1, size-1, key);
    }
}

int main(){

    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 2;
    bool ans = linearSearch(arr, size, key);

    if(ans){
        cout<<"Key element is found"<<endl;
    }
    else{
        cout<<"Key element is not found"<<endl;
    }


}
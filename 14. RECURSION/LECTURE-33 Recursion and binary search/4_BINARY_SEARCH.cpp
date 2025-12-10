//LINK:- https://www.naukri.com/code360/problems/binary-search_972?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_11&leftPanelTabValue=PROBLEM

//TIME COMPLEXITY :- O(logN)

#include<iostream>
using namespace std;

void print(int arr[], int s, int e){
    for(int i = s; i<e; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

bool binarySearch(int arr[], int start, int end, int key){
    cout<<endl<<endl;
    print(arr, start, end);

    //BASE CASE, IF START BECOMES GREATER THAN END
    if(start > end){
        return false;
    }

    //CALCULATING MID
    int mid = (start + end)/2;

    //PROCESS
    if(arr[mid] == key){
        return true;
    }
    else if(arr[mid] > key){    //SEARCHIHNG IN LEFT HALF
        return binarySearch(arr, start, mid-1, key);
    }
    else{
        return binarySearch(arr, mid+1, end, key);  //SEARCHING IN RIGHT HALF
    }
}

int main(){

    int arr[] = {2,4,6,10,14,16};
    int size = 6;
    // int key = 18;
    int key = 16;
    bool ans = binarySearch(arr, 0, size, key);

    cout<<endl<<endl;
    if(ans){
        cout<<"Key element is found"<<endl;
    }
    else{
        cout<<"Key element is not found"<<endl;
    }
    return 0;
}
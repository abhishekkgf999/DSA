#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int key){
    int left = 0;
    int right = size-1;

    // int mid = (left+right)/2;

    int mid = left + (right-left)/2 ; //integer ki range mai rehne ke liye, 
                                      // taaki agar left or right sum hokr integer ki range se bhar n ho jaye
    while(left<=right){              
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            left = mid+1;
        }

        else {
            right = mid-1;
        }
        mid = (left+right)/2;
    }
    return -1;
}

int main(){
    int even[6] = {1, 2, 32, 44, 55, 67};
    int odd[5] = {0, 23, 45, 55, 99};

    int evenIndex = binarySearch(even, 6, 55);

    cout<<"Index of given key 55 is "<<evenIndex<<endl;

    int oddIndex = binarySearch(odd, 5, 20);

    cout<<"Index of given key 99 is "<<oddIndex<<endl;


    return 0;
}
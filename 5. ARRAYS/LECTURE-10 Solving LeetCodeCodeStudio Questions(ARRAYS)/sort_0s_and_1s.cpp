#include<iostream>
#include<vector>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//USING FREQUENCY OF 0's & 1's
void sortOne1(int arr[], int n){
    vector<int> freq(2, 0);

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    int i=0;
    while(freq[0]--){
        arr[i++] = 0;
    }

    while(freq[1]--){
        arr[i++] = 1;
    }

}


//USING TWO POINTER APPROACH
void sortOne2(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        while(arr[left] == 0 && left < right )  {
            left++;
        }

        while(arr[right]==1 && left < right){
            right--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        if(left<right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

}

int main() {
    
    int arr[8] = {1,1,0,0,0,0,1,0};
    cout<<"Your array is:- ";
    printArray(arr, 8);
    
    sortOne2(arr, 8);
    printArray(arr, 8);

    return 0;
}
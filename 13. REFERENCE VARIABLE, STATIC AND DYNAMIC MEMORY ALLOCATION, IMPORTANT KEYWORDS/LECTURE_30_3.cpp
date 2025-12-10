// Inline Functions & Default Args

#include<bits/stdc++.h>
using namespace std;

//INLINE FUNCTION
inline int getMax(int &a, int &b){
    return (a>b)? a : b;
}

//DEFAULT ARGUMENT
void print(int arr[], int n, int start = 0){
    for(int i = start; i<n; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int a = 1, b = 2;
    int ans = 0;

    ans = getMax(a, b);
    cout<<ans<<endl;

    a = a+3;
    b = b+1;

    ans = getMax(a, b);
    cout<<ans<<endl;

    int arr[5] = {1,2,3,4,5};
    int size = 5;

    print(arr, size);
    cout<<endl;
    print(arr, size, 2);

    return 0;
}
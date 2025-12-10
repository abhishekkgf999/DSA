//DYNAMIC MEMORY ALLOCATION FOR 2D ARRAYS

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int row;
    cout<<"Enter number of rows:- "<<endl;
    cin>>row;

    int col;
    cout<<"Enter number of columns:- "<<endl;
    cin>>col;

    //CREATING A 2D ARRAY
    int **arr = new int*[row];
    for(int i = 0; i<row; i++){
        arr[i] = new int[col];
    }

    //TAKING INPUT
    cout<<"Enter elements of 2d array:- "<<endl;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    //OUTPUT
    cout<<"MATRIX IS:- "<<endl;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    //RELEASING MEMORY
    for(int i = 0; i<row; i++){
        delete []arr[i];
    }

    delete []arr;
    
    return 0;
}
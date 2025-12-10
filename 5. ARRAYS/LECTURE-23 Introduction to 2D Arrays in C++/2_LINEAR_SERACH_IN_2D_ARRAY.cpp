/*
#LINEAR SEARCH IN 2D ARRAY
*/

#include<bits/stdc++.h>
using namespace std;

bool isfound(int arr[3][4], int element, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == element) return 1;
        }
    }
    return 0;
}

int main(){
    int arr[3][4];

    //TAKING INPUT --> ROW WISE INPUT
    cout<<"Enter the elements of matrix(2-d array) ";
    for(int row=0; row<3; row++){     //--> this loop is running for rows
        for(int col=0; col<4; col++){     //--> this loop is running for columns
            cin>>arr[row][col];
        }
    }

     //PRINTING 
    for(int row=0; row<3; row++){     //--> this loop is running for rows
        for(int col=0; col<4; col++){     //--> this loop is running for columns
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<"enter the element to search:- ";
    int element;
    cin>>element;

    if(isfound(arr, element, 3, 4)){
        cout<<"Element found!"<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }
    return 0;
}
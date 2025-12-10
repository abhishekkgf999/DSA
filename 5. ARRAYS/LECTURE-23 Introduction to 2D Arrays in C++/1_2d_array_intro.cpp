#include<bits/stdc++.h>
using namespace std;

int main(){

    // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // int arr[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};
    int arr[3][4];
// /*
    //TAKING INPUT --> ROW WISE INPUT
    cout<<"Enter the elements of matrix(2-d array) ";
    for(int row=0; row<3; row++){     //--> this loop is running for rows
        for(int col=0; col<4; col++){     //--> this loop is running for columns
            cin>>arr[row][col];
        }
    }
// */

    // TAKING INPUT -->  COLUMN WISE INPUT
    // cout<<"Enter the elements of matrix(2-d array) ";
    // for(int col=0; col<4; col++){     //--> this loop is running for columns
    //     for(int row=0; row<3; row++){     //--> this loop is running for rows
    //         cin>>arr[row][col];
    //     }
    // }

    //PRINTING 
    for(int row=0; row<3; row++){     //--> this loop is running for rows
        for(int col=0; col<4; col++){     //--> this loop is running for columns
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}
/*
# LARGEST ROW SUM
*/

#include<bits/stdc++.h>
using namespace std;

void largest_row_sum(int arr[][3]){
    //ROW WISE SUM
    int maxi = INT32_MIN;
    int index = -1;
    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum+= arr[row][col];
        }
        
        if(sum>maxi){
            maxi = sum;
            index = row;
        }
        
    }
    cout<<"The maximum sum of row is:- "<<maxi<<" at row "<<index+1<<endl;
}



int main(){
    int arr[3][3];

    //TAKING INPUT --> ROW WISE INPUT
    cout<<"Enter the elements of matrix(2-d array) ";
    for(int row=0; row<3; row++){     //--> this loop is running for rows
        for(int col=0; col<3; col++){     //--> this loop is running for columns
            cin>>arr[row][col];
        }
    }

     //PRINTING 
    for(int row=0; row<3; row++){     //--> this loop is running for rows
        for(int col=0; col<3; col++){     //--> this loop is running for columns
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    largest_row_sum(arr);

    return 0;
}
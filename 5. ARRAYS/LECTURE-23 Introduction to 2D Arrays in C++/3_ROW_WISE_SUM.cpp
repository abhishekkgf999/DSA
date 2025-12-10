/*
# ROW WISE SUM & COLUMN WISE SUM
*/

#include<bits/stdc++.h>
using namespace std;

void row_wise_sum(int arr[][3]){
    //ROW WISE SUM
    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum+= arr[row][col];
        }
        cout<<"Sum of "<<row+1<<" row is:- "<<sum<<endl;
    }
}


void column_wise_sum(int arr[][3]){
    //COLUMN WISE SUM
     for(int col=0; col<3; col++){
        int sum = 0;
        for(int row=0; row<3; row++){
            sum+= arr[row][col];
        }
        cout<<"Sum of "<<col+1<<" column is:- "<<sum<<endl;
    }
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

    row_wise_sum(arr);
    cout<<endl;
    column_wise_sum(arr);

    return 0;
}
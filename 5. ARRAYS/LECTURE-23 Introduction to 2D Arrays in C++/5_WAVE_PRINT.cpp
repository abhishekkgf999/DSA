/*
#WE HAVE TO PRINT LIKE A WAVE

LINK:- https://www.codingninjas.com/studio/problems/print-like-a-wave_893268
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    
    for(int col=0; col<mCols; col++){
        
        if(col&1){
            for(int row = nRows-1; row>=0; row--) {
               // cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
                }
            }
        
        else{
            for(int row = 0; row<nRows; row++){
                //cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);  
                }
            }
        
        
        }
    return ans;
}

int main(){
    cout<<"Enter the number of rows and columns:- ";
    int nRows, mCols;
    cin>>nRows>>mCols;

    vector<vector<int>> arr(nRows, vector<int>(mCols));
    cout<<"Enter the elements of matrix:- ";
    for(int i=0; i<nRows; i++){
        for(int j=0; j<mCols; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<3; i++){     
        for(int j=0; j<3; j++){    
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> ans = wavePrint(arr,  nRows,  mCols);
    for(int i : ans){
        cout<<i<<" ";
    }


    return 0;
}
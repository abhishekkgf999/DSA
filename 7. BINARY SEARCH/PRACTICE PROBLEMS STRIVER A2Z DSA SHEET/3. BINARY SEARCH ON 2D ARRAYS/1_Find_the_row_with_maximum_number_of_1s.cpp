/*

#FIND THE ROW WITH MAXIMUM NUMBER OF 1'S

LINK:- https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

*/

#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s_Bruteforce(vector<vector<int> > &arr) {
        int row = arr.size();
        int col = arr[0].size();

        int ans = -1;
        int count = 0;

        for(int i = 0; i<row; i++){
            int tempcount = 0;
            for(int j = 0; j<col; j++){
                if(arr[i][j] == 1){
                    tempcount++;
                    if(tempcount > count){
                        count = tempcount;
                        ans = i;
                    }
                }
            }
        }

        return ans;
    }

//OPTIMAL SOLUTION
//We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.
int rowWithMax1s_OptimalSoution(vector<vector<int> > &arr) {
        int row = arr.size();
        int col = arr[0].size();

        int ans = -1;
        int count = 0;
        for(int i = 0; i<row; i++){
            int l = 0, r = col-1;
            int tempcount = 0;
            while(l<=r){
                int mid = (l+r)/2;
                if(arr[i][mid] == 1){
                    tempcount = tempcount + (r-mid+1);
                    if(tempcount > count){
                        count = tempcount;
                        ans = i;
                    }
                    r = mid-1;
                }
                else l = mid+1;
            }
        }

        return ans;
    }


int main(){
    vector<vector<int>> arr = {{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};
    // cout<<rowWithMax1s_Bruteforce(arr);
    cout<<rowWithMax1s_OptimalSoution(arr);
    return 0;
}
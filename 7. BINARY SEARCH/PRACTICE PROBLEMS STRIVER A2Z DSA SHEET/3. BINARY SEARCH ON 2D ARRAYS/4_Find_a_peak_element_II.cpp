/*

#FIND A PEAK ELEMENT II (mark for revision)

LINK:- https://leetcode.com/problems/find-a-peak-element-ii/description/

*/


#include<bits/stdc++.h>
using namespace std;

//OPTIMAL SOLUTION :- O(row*log(col))
/*

Start from middle column, and search for maximum element in that column, so that we dont 
need compare upward and downward.

Next we will compare that max. element from its correspoding left and right

Case I :- If the current element is smaller than left, then it means, some bigger is presenet
          on left half of the matrix, which maybe our answer

*/
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int l = 0, r = col-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int max_ele_in_col = -1;
            int ind_max_ele = 0;
            for(int i = 0; i<row; i++){
                if(mat[i][mid] > max_ele_in_col){
                    max_ele_in_col = mat[i][mid];
                    ind_max_ele = i;
                }
            }

            if(mid-1 >= 0 && mat[ind_max_ele][mid-1] > mat[ind_max_ele][mid]) r = mid-1;
            else if(mid+1 < col && mat[ind_max_ele][mid+1] > mat[ind_max_ele][mid]) l = mid+1;
            else return {ind_max_ele, mid};
        }

        return {-1,-1};
    }

int main(){
    vector<vector<int>> mat = {{1,4}, {3,2}};
    vector<int> ans = findPeakGrid(mat);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
/*
#DISTANCE OF NEAREST CELL HAVING ONE

LINK:- https://leetcode.com/problems/01-matrix/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
The approach is using multi source bfs traversal, where sources are location of '0's
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int,int>> q;
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto &d : dir){
                int ni = i + d[0];
                int nj = j + d[1];

                if(ni >= 0 && nj >= 0 && ni < row && nj <col && ans[ni][nj] == -1){
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
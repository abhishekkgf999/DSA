/*
#NUMBER OF ENCLAVES

LINK:- https://leetcode.com/problems/number-of-enclaves/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
Treating all the edge '1's as the source, and visite the all connected 1's from the edge source and mark them visited

After all traversing from source, we iterate again and see which nodes having value 1 are not visited, can be considered as our ans 
*/
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    
    return 0;
}
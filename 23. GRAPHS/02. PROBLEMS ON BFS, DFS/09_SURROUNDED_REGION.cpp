/*
#SURROUNDED REGION

LINK:- https://leetcode.com/problems/surrounded-regions/
*/


#include<bits/stdc++.h>
using namespace std;

/*
💡 PROBLEM SUMMARY
- Grid contains:
    'X' and 'O'

Goal:
✔ Capture regions of 'O' that are completely
  surrounded by 'X'.

Rules:
✔ 'O's connect only in 4 directions (horizontally and vertically)
✔ If a region touches the boundary,
  it cannot be captured.

====================================================
KEY IDEA: CONNECTED COMPONENT + BFS
----------------------------------------------------
Each connected group of 'O' cells forms a region.

For every region:
1️⃣ Traverse using BFS
2️⃣ Track all cells in the region
3️⃣ Check if the region touches boundary

If boundary touched:
    ❌ Cannot capture region

If boundary NOT touched:
    ✔ Convert all 'O' → 'X'

====================================================
APPROACH
----------------------------------------------------
STEP 1: Traverse entire board

If cell is:
    board[i][j] == 'O'
    and not visited

Start BFS to explore that region.

----------------------------------------------------

STEP 2: BFS Traversal

Use queue to explore neighbours.

During BFS:
✔ Store region cells in temp list
✔ Track boundary contact

Check neighbours in 4 directions.

----------------------------------------------------

STEP 3: Decide Region Fate

If region touches boundary:
    Leave it unchanged

Else:
    Convert all stored cells → 'X'

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N × M)

SPACE COMPLEXITY:
➡ O(N × M)

====================================================
KEY INTUITION
----------------------------------------------------
Treat every 'O' region as a connected component.

If it touches boundary → safe.

Otherwise → flip the entire region.
====================================================
*/


class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<int>> &visited, int x, int y, int row, int col){
        queue<pair<int,int>> q;
        vector<pair<int,int>> temp;
        q.push({x, y});
        visited[x][y] = 1;

        bool isEdge = false;
        if(x == 0 || x == row-1 || y == 0 || y == col-1) isEdge = true;

        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            temp.push_back({i,j});

            for(auto &d : dir){
                int nx = i + d[0];
                int ny = j + d[1];

                if(nx >= 0 && nx <row && ny >= 0 && ny < col && board[nx][ny] == 'O' && visited[nx][ny] == 0){
                    if(nx == 0 || nx == row-1 || ny == 0 || ny == col-1) isEdge = true;
                    else{
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }

        if(!isEdge){
            for(auto &it :temp){
                board[it.first][it.second] = 'X';
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == 'O' && visited[i][j] == 0){
                    bfs(board, visited, i, j, row, col);
                }
            }
        }
    }
};

int main(){
    
    return 0;
}
/*
#MAP OF HIGHEST PEAK

LINK:- https://leetcode.com/problems/map-of-highest-peak/
*/

#include<bits/stdc++.h>
using namespace std;

/*
💡 PROBLEM SUMMARY:
- Grid contains:
    1 → Water cell
    0 → Land cell

Rules:
✔ Water height = 0
✔ Adjacent cells can differ in height by at most 1
✔ Assign heights to land cells such that all conditions hold

Goal:
✔ Return the height map with maximum possible heights.

====================================================
KEY IDEA: MULTI-SOURCE BFS ⭐
----------------------------------------------------
Instead of starting BFS from one node,
we start BFS from ALL water cells.

Reason:
Water height is fixed = 0,
so we expand outward from water.

Each BFS level increases height by 1.

====================================================
INITIALIZATION
----------------------------------------------------
1️⃣ Create result matrix `ans`
   Initialize all values = -1

2️⃣ Traverse grid:
   If cell is water:
        ans[i][j] = 0
        push (i, j) into queue

Queue now contains all sources.

====================================================
BFS PROCESS
----------------------------------------------------
For each cell popped from queue:

Check its 4-direction neighbours:
    up
    down
    left
    right

If neighbour not visited (ans == -1):

    ans[new_i][new_j] = ans[i][j] + 1

Push neighbour into queue.

----------------------------------------------------
This guarantees:
✔ shortest distance from water
✔ height difference constraint satisfied

====================================================
WHY BFS WORKS HERE?
----------------------------------------------------
✔ BFS expands level-by-level
✔ Each level corresponds to height increase
✔ Multi-source ensures nearest water is used

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N × M)
(each cell visited once)

SPACE COMPLEXITY:
➡ O(N × M)
(queue + result matrix)

====================================================
KEY INTUITION
----------------------------------------------------
This problem is essentially
"distance from nearest water cell".

So we run Multi-Source BFS
starting from all water cells.

====================================================
*/
class Solution1 {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i-1 >= 0 && ans[i-1][j] == -1){
                ans[i-1][j] = ans[i][j] + 1;
                q.push({i-1,j});
            }
            
            if(i+1 < row && ans[i+1][j] == -1){
                ans[i+1][j] = ans[i][j] + 1;
                q.push({i+1,j});
            }

            if(j-1 >= 0 && ans[i][j-1] == -1){
                ans[i][j-1] = ans[i][j] + 1;
                q.push({i,j-1});
            }

            if(j+1 < col && ans[i][j+1] == -1){
                ans[i][j+1] = ans[i][j] + 1;
                q.push({i,j+1});
            }
        }

        return ans;
    }
};

/*
More clean version of the same approach above
*/
class Solution2 {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int,int>> q;

        // Push all water cells as starting points
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto &d : dir){
                int ni = i + d[0];
                int nj = j + d[1];

                if(ni >= 0 && nj >= 0 && ni < row && nj < col && ans[ni][nj] == -1){
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
/*
#ROTTING ORANGES

LINK:- https://leetcode.com/problems/rotting-oranges/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
💡 PROBLEM SUMMARY:
- Grid values:
    0 → Empty cell
    1 → Fresh orange
    2 → Rotten orange

Rule:
✔ Every minute, rotten oranges infect
  adjacent fresh oranges (4 directions)

Goal:
✔ Find minimum minutes required
  to rot all oranges
✔ If impossible → return -1

====================================================
KEY IDEA: MULTI-SOURCE BFS ⭐
----------------------------------------------------
Instead of starting BFS from one node,
we start BFS from ALL rotten oranges.

Each rotten orange acts as a source of infection.

----------------------------------------------------
WHY BFS (NOT DFS)?
----------------------------------------------------
✔ BFS processes nodes LEVEL by LEVEL
✔ Each level represents 1 minute
✔ DFS would spread infection in depth,
  which doesn't simulate time correctly

====================================================
INITIALIZATION
----------------------------------------------------
1️⃣ Traverse grid:
   - Count fresh oranges
   - Push all rotten oranges into queue

Queue initially contains ALL infection sources.

====================================================
BFS PROCESS
----------------------------------------------------
Each BFS level = 1 minute.

For every rotten orange in queue:
    infect its 4-direction neighbours
    if neighbour is fresh:
        ✔ make it rotten
        ✔ push to queue
        ✔ decrease fresh count

----------------------------------------------------
Queue size is used to ensure that
all infections in one minute are processed
before moving to next minute.

====================================================
FINAL CHECK
----------------------------------------------------
After BFS:

✔ If freshOranges > 0
      → some oranges couldn't rot
      → return -1

✔ Else
      → return minutes - 1
      (last level increments minute once extra)

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N × M)
(each cell processed once)

SPACE COMPLEXITY:
➡ O(N × M)
(queue in worst case)

====================================================
KEY INTUITION
----------------------------------------------------
This problem is identical to
"spreading infection / fire / virus"
in a grid → solved using Multi-Source BFS.

====================================================
*/
class Solution {
    int bfs(vector<vector<int>> grid, queue<pair<int,int>> &q, int freshOranges, int n, int m){
        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;

                if(i+1 < n && grid[i+1][j] == 1){
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                    freshOranges--;
                }

                if(i-1 >= 0 && grid[i-1][j] == 1){
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                    freshOranges--;
                }

                if(j+1 < m && grid[i][j+1] == 1){
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                    freshOranges--;
                }

                if(j-1 >= 0 && grid[i][j-1] == 1){
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                    freshOranges--;
                }
            }

            minutes++;
        }

        if(freshOranges != 0) return -1;
        return minutes-1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) freshOranges++;
                else if (grid[i][j] == 2) q.push({i,j});
            }
        }

        if(freshOranges == 0) return 0;
        return bfs(grid, q, freshOranges, n, m);
    }
};

int main(){
    
    return 0;
}
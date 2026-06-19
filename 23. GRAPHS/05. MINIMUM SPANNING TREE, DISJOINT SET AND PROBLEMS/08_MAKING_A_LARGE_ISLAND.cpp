/*
====================================================
MAKING A LARGE ISLAND
LeetCode:
https://leetcode.com/problems/making-a-large-island/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Binary grid

        1 → Land
        0 → Water

Operation:
✔ Change at most ONE water cell
  into land

Goal:
✔ Return maximum island size
  obtainable after the change

====================================================
CORE OBSERVATION ⭐
----------------------------------------------------
We are allowed to convert:

    one 0 → 1

Question becomes:

✔ Which water cell should we convert
  to obtain maximum island size?

====================================================
MAIN INTUITION
----------------------------------------------------
Suppose we have:

    1 0 1

----------------------------------------------------
If we convert middle 0:

    1 1 1

Two islands become connected.

----------------------------------------------------
So every 0 cell acts like:

✔ A bridge between neighbouring islands

====================================================
IMPORTANT IDEA ⭐
----------------------------------------------------
Before checking any 0:

✔ First identify all existing islands

✔ Calculate size of every island

DSU is perfect for this.

----------------------------------------------------
Once islands are known:

For every 0 cell:

✔ Look at its neighbouring islands

✔ Merge their sizes

✔ Add +1 for current converted cell

====================================================
WHY DSU ?
----------------------------------------------------
We need:

✔ Fast component identification

✔ Fast component size lookup

DSU provides:

✔ findUPar(node)
✔ size[ultimateParent]

====================================================
PHASE 1: BUILD EXISTING ISLANDS ⭐
----------------------------------------------------
Traverse entire grid.

Whenever land cell found:

✔ Create DSU node

✔ Connect with neighbouring lands

----------------------------------------------------
After unions:

Every island has:

✔ one ultimate parent
✔ one stored size

====================================================
2D TO 1D CONVERSION
----------------------------------------------------
DSU works on nodes.

Convert:

    (i,j)

into:

    node = i * col + j

----------------------------------------------------
Example:

col = 4

(0,0) → 0
(0,1) → 1
(1,0) → 4
(2,3) → 11

====================================================
PHASE 2: TRY CONVERTING EVERY 0 ⭐
----------------------------------------------------
For every water cell:

Look at:
✔ top
✔ right
✔ bottom
✔ left

----------------------------------------------------
Collect neighbouring islands.

Example:

      A
      |
B --- 0 --- C

----------------------------------------------------
If converted:

New size:

    size(A)
  + size(B)
  + size(C)
  + 1

====================================================
VERY IMPORTANT EDGE CASE ⭐
----------------------------------------------------
Same island may appear from
multiple directions.

Example:

    1 1
    1 0

----------------------------------------------------
Neighbour check may encounter:

✔ same component multiple times

If we directly add:

    size + size + size

Answer becomes incorrect.

----------------------------------------------------
Solution:

Use:
    set<int>

Store:
✔ unique ultimate parents only

====================================================
WHY SET IS REQUIRED ?
----------------------------------------------------
Example:

    1 1
    1 0

All neighbouring cells belong to
same island.

Without set:

    3 + 3 + 3 + 1

Wrong answer.

----------------------------------------------------
With set:

    3 + 1

Correct answer.

====================================================
SPECIAL EDGE CASE ⭐
----------------------------------------------------
Grid contains only 1s.

Example:

    1 1
    1 1

No 0 exists.

----------------------------------------------------
Largest island already exists.

So:
✔ maximum existing component size
  should also be tracked

This is why:

    largestIsland

is updated while forming DSU.

====================================================
APPROACH
----------------------------------------------------

STEP 1:
✔ Create DSU

----------------------------------------------------

STEP 2:
✔ Build all existing islands

✔ Union neighbouring lands

----------------------------------------------------

STEP 3:
✔ Store largest existing island

----------------------------------------------------

STEP 4:
✔ For every 0 cell

Collect:
✔ unique neighbouring components

----------------------------------------------------

STEP 5:
✔ Sum all unique component sizes

✔ Add +1 for converted cell

----------------------------------------------------

STEP 6:
✔ Update maximum answer

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Only one 0 can be converted
✔ Same island counted once
✔ Use set for uniqueness
✔ Track already existing largest island
✔ DSU stores island sizes efficiently

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(N² × α(N²))

DSU operations are nearly constant.

----------------------------------------------------
SPACE:
➡ O(N²)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem says:

✔ Merge neighbouring components
✔ Maximize connected component size
✔ One modification allowed

Think:

✔ Disjoint Set Union (DSU)

Core Formula:
----------------------------------------------------
For every 0:

    1
    +
    Sum(All Unique Adjacent
        Component Sizes)

Take maximum over all cells.

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
public:

    vector<int> parent, size;

    DisJointSet(int n, int m){
        parent.resize(n * m, -1);
        size.resize(n * m, 0);
    }

    int findUPar(int node){

        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){

        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if(ult_u == ult_v){
            return;
        }

        if(size[ult_u] < size[ult_v]){

            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];

        }
        else{

            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> vis(row, vector<int>(col, 0));

        DisJointSet ds(row, col);

        int largestIsland = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){

                if(vis[i][j] == 0 && grid[i][j] == 1){

                    vis[i][j] = 1;

                    int node = i * col + j;

                    ds.parent[node] = node;
                    ds.size[node] = 1;

                    for(int k = 0; k < 4; k++){

                        int new_i = i + dx[k];
                        int new_j = j + dy[k];

                        if(new_i >= 0 && new_i < row &&
                           new_j >= 0 && new_j < col &&
                           vis[new_i][new_j] == 1){

                            int new_node = new_i * col + new_j;

                            if(ds.findUPar(node) != ds.findUPar(new_node)){
                                ds.unionBySize(node, new_node);
                            }
                        }
                    }

                    largestIsland = max(
                        largestIsland,
                        ds.size[ds.findUPar(node)]
                    );
                }
            }
        }

        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){

                if(grid[i][j] == 0){

                    set<int> visited;

                    int temp = 0;

                    for(int k = 0; k < 4; k++){

                        int new_i = i + dx[k];
                        int new_j = j + dy[k];

                        if(new_i >= 0 && new_i < row &&
                           new_j >= 0 && new_j < col &&
                           vis[new_i][new_j] == 1){

                            int new_node =
                                ds.findUPar(new_i * col + new_j);

                            if(visited.find(new_node) == visited.end()){
                                temp += ds.size[new_node];
                            }

                            visited.insert(new_node);
                        }
                    }

                    largestIsland =
                        max(largestIsland, temp + 1);
                }
            }
        }

        return largestIsland;
    }
};

int main(){
    
    return 0;
}
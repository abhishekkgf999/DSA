/*
====================================================
MOST STONES REMOVED WITH SAME ROW OR COLUMN
LeetCode:
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Stones placed on 2D grid

Rule:
✔ A stone can be removed if:
      another stone exists in:
          • same row
          OR
          • same column

Goal:
✔ Remove maximum possible stones

====================================================
CORE OBSERVATION ⭐
----------------------------------------------------
The MOST IMPORTANT observation:

✔ Stones connected through
  same row/column form a GROUP
  (connected component)

----------------------------------------------------
Inside one connected component:

✔ We can remove ALL stones
  except ONE

Why?
----------------------------------------------------
Because:
✔ at least one connected stone
  will always remain to support removal

====================================================
MATHEMATICAL OBSERVATION ⭐
----------------------------------------------------
Suppose groups are:

Group 1:
    x1 stones

Group 2:
    x2 stones

Group 3:
    x3 stones

----------------------------------------------------
Removable stones:

    (x1 - 1)
  + (x2 - 1)
  + (x3 - 1)

----------------------------------------------------
Rearranging:

    (x1 + x2 + x3 + ...)
    -
    (1 + 1 + 1 + ...)

----------------------------------------------------
Now:

✔ Total stones:
      x1 + x2 + x3 + ...
      = n

✔ Number of groups:
      1 + 1 + 1 + ...
      = connected components

So final formula becomes:

    answer = n - components

====================================================
APPROACH 1: DFS / CONNECTED COMPONENTS ⭐
----------------------------------------------------
Treat each stone as:
✔ graph node

Two stones are connected if:
✔ same row
✔ same column

----------------------------------------------------
Run DFS:
✔ each DFS traversal forms one group

After complete DFS:
✔ increase component count

Finally:
✔ return:
      n - groups

====================================================
WHY DFS WORKS
----------------------------------------------------
DFS visits:
✔ all stones reachable from current stone

Meaning:
✔ all stones belonging to same group

====================================================
APPROACH 2: DISJOINT SET (DSU) ⭐
----------------------------------------------------
Same logic:
✔ answer = n - groups

Only difference:
✔ groups found using DSU

====================================================
HOW DSU WORKS HERE
----------------------------------------------------
Initially:
✔ every stone is separate component

----------------------------------------------------
If two stones share:
✔ same row
OR
✔ same column

Then:
✔ union them

----------------------------------------------------
After all unions:

✔ count unique ultimate parents

That gives:
✔ total connected components

====================================================
WHY UNIQUE PARENTS = GROUPS
----------------------------------------------------
In DSU:

✔ Every component has one
  ultimate parent

So:
✔ parent[i] == i
  indicates root component

Counting such roots:
✔ gives total groups

====================================================
APPROACH
----------------------------------------------------

DFS APPROACH
----------------------------------------------------
STEP 1:
✔ Treat stones as graph nodes

STEP 2:
✔ DFS all connected stones

STEP 3:
✔ Count connected components

STEP 4:
✔ return:
      n - groups

----------------------------------------------------

DSU APPROACH
----------------------------------------------------
STEP 1:
✔ Initialize DSU

STEP 2:
✔ Union stones sharing row/column

STEP 3:
✔ Count unique parents

STEP 4:
✔ return:
      n - groups

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Stones connected transitively
✔ Same row OR same column
✔ One stone must remain per group
✔ Components determine answer

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------

DFS APPROACH
----------------------------------------------------
TIME:
➡ O(N²)

SPACE:
➡ O(N)

----------------------------------------------------

DSU APPROACH
----------------------------------------------------
TIME:
➡ O(N² × α(N))

SPACE:
➡ O(N)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem says:
✔ remove maximum elements
✔ while maintaining connectivity

Think:
✔ Connected Components

And often:
✔ answer becomes:
      total nodes - components

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {

    void dfs(vector<vector<int>>& stones, int index, vector<bool> &visited){

        visited[index] = true;

        for(int i = 0; i < stones.size(); i++){

            int r = stones[index][0];
            int c = stones[index][1];

            if(visited[i] == false &&
               (stones[i][0] == r || stones[i][1] == c)){

                dfs(stones, i, visited);
            }
        }
    }

public:

    int removeStones(vector<vector<int>>& stones) {

         int n = stones.size();

         vector<bool> visited(n, false);

         int group = 0;

         for(int i = 0; i < n; i++){

            if(visited[i] == true){
                continue;
            }

            dfs(stones, i, visited);

            group++;
         }

         return n - group;
    }
};

class DisjointSet{

public:

    vector<int> parent, rank;

    DisjointSet(int n){

        parent.resize(n, 0);
        rank.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int node){

        if(parent[node] == node){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v){

        int ult_u = find(u);
        int ult_v = find(v);

        if(ult_u == ult_v){
            return;
        }

        if(rank[ult_u] < rank[ult_v]){

            parent[ult_u] = ult_v;

        }
        else if(rank[ult_v] < rank[ult_u]){

            parent[ult_v] = ult_u;

        }
        else{

            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution_2 {

public:

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        DisjointSet ds(n);

        for(int i = 0; i < n; i++){

            for(int j = i + 1; j < n; j++){

                if(stones[i][0] == stones[j][0] ||
                   stones[i][1] == stones[j][1]){

                    ds.unionByRank(i, j);
                }
            }
        }

        int groups = 0;

        for(int i = 0; i < n; i++){

            if(ds.parent[i] == i){
                groups++;
            }
        }

        return (n - groups);
    }
};

int main(){
    
    return 0;
}
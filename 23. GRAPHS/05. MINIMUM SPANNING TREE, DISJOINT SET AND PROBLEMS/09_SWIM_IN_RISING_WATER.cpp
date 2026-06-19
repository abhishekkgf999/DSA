/*
====================================================
SWIM IN RISING WATER
LeetCode:
https://leetcode.com/problems/swim-in-rising-water/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Grid where each cell contains
      a unique height

At time t:

✔ We can enter cells whose value
  is <= t

Goal:
✔ Reach:

      (0,0) → (n-1,n-1)

✔ Find minimum time required

====================================================
KEY OBSERVATION ⭐
----------------------------------------------------
The answer is NOT:

✔ shortest path length

The answer is:

✔ minimum possible maximum height
  encountered on the path

----------------------------------------------------
Because:

At time t:

✔ all cells with value <= t
  become accessible

So we need smallest t such that
a complete path exists.

====================================================
APPROACH 1: BINARY SEARCH + DFS ⭐
====================================================

INTUITION
----------------------------------------------------
Notice the wording:

✔ Minimize the maximum time

This is a classic hint for:

✔ Binary Search on Answer

====================================================
SEARCH SPACE
----------------------------------------------------
Minimum possible answer:

    grid[0][0]

because start cell itself
must be accessible.

----------------------------------------------------
Maximum possible answer:

    n² - 1

Given in constraints:
    grid[i][j] < n²

====================================================
BINARY SEARCH CHECK
----------------------------------------------------
Suppose:

    mid = current time

Question:

✔ Can we reach destination
  using only cells:

        grid[i][j] <= mid ?

----------------------------------------------------
If YES:

✔ Try smaller answer

        r = mid - 1

----------------------------------------------------
If NO:

✔ Need larger time

        l = mid + 1

====================================================
DFS ROLE
----------------------------------------------------
DFS checks:

✔ Is destination reachable
  using current time limit?

----------------------------------------------------
Only visit cells:

    grid[i][j] <= time

====================================================
TIME COMPLEXITY
----------------------------------------------------
Binary Search:
    O(log(n²))

DFS:
    O(n²)

Total:

➡ O(n² log(n²))

====================================================
APPROACH 2: DIJKSTRA ⭐
====================================================

MAIN OBSERVATION
----------------------------------------------------
We can think of:

Each cell = node

----------------------------------------------------
Cost of path:

NOT sum of heights

Instead:

✔ Maximum height encountered
  on that path

====================================================
MODIFIED DIJKSTRA
----------------------------------------------------
Normal Dijkstra:

    newCost = cost + edge

----------------------------------------------------
Here:

    newCost =
        max(currentCost,
            grid[newCell])

Because:

✔ path cost is determined by
  worst (maximum) height seen so far

====================================================
WHY DIJKSTRA WORKS
----------------------------------------------------
Priority Queue always processes:

✔ smallest maximum cost path first

----------------------------------------------------
The first time destination
is popped:

✔ answer is guaranteed minimum

====================================================
RELAXATION
----------------------------------------------------
For neighbour:

    newCost =
        max(cost,
            grid[new_x][new_y])

----------------------------------------------------
Update only if:

    newCost < dist[new_x][new_y]

====================================================
TIME COMPLEXITY
----------------------------------------------------
➡ O(n² log(n²))

====================================================
APPROACH 3: DISJOINT SET (DSU) ⭐
====================================================

MAIN OBSERVATION
----------------------------------------------------
At time t:

✔ Every cell with value <= t
  becomes active

----------------------------------------------------
As time increases:

✔ More cells become active
✔ More components get connected

Eventually:

✔ Source and destination
  become part of same component

====================================================
CLEVER TRICK
----------------------------------------------------
Grid values are unique.

Create:

    pos[value] = {x,y}

----------------------------------------------------
Meaning:

At time t

we instantly know:

✔ which cell becomes active

====================================================
DSU PROCESS
----------------------------------------------------
For every time:

    t = 0 → n²-1

----------------------------------------------------
STEP 1:

Activate:

    pos[t]

----------------------------------------------------
STEP 2:

Connect with active neighbours

using DSU

----------------------------------------------------
STEP 3:

Check:

    source parent
        ==
    destination parent ?

----------------------------------------------------
If YES:

✔ Current time is answer

====================================================
WHY THIS WORKS
----------------------------------------------------
At every time:

✔ DSU represents all cells
  submerged under water level t

----------------------------------------------------
First time source and destination
become connected:

✔ minimum valid time found

====================================================
TIME COMPLEXITY
----------------------------------------------------
DSU Operations:

➡ O(n² × α(n²))

Practically near O(n²)

====================================================
COMPARISON OF ALL APPROACHES
----------------------------------------------------

1️⃣ Binary Search + DFS

✔ Easy intuition
✔ Answer space search

Time:
➡ O(n² log(n²))

----------------------------------------------------

2️⃣ Dijkstra

✔ Most common interview solution
✔ Direct shortest-path modelling

Time:
➡ O(n² log(n²))

----------------------------------------------------

3️⃣ DSU

✔ Most elegant
✔ Uses connectivity concept

Time:
➡ O(n²)

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Grid values are unique
✔ Movement only in 4 directions
✔ Answer = minimum possible
  maximum height on path
✔ Dijkstra uses max() instead of +
✔ DSU activates cells by time

====================================================
KEY TAKEAWAY
----------------------------------------------------
This problem can be solved using
three completely different ideas:

✔ Binary Search on Answer
✔ Modified Dijkstra
✔ Disjoint Set Union

Core observation:

    Path Cost =
    Maximum Height Encountered

NOT:

    Sum of Heights

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_Binary_search {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n;

    bool isPossible(vector<vector<int>>& grid, int time, int x, int y, vector<vector<bool>> &visited){

        if(x < 0 || x >= n || y < 0 || y >= n ||
           visited[x][y] == true ||
           grid[x][y] > time){
            return false;
        }

        visited[x][y] = true;

        if(x == n - 1 && y == n - 1){
            return true;
        }

        for(int i = 0; i < 4; i++){

            int new_X = x + dx[i];
            int new_Y = y + dy[i];

            if(isPossible(grid, time, new_X, new_Y, visited)){
                return true;
            }
        }

        return false;
    }

public:

    int swimInWater(vector<vector<int>>& grid) {

        n = grid.size();

        int l = grid[0][0];
        int r = (n * n) - 1;

        int result = 0;

        while(l <= r){

            int mid = l + (r - l) / 2;

            vector<vector<bool>> visited(
                n,
                vector<bool>(n, false)
            );

            if(isPossible(grid, mid, 0, 0, visited)){

                result = mid;
                r = mid - 1;

            }
            else{

                l = mid + 1;
            }
        }

        return result;
    }
};

class Solution_using_Dijkstras_algorithm {
public:

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> dist(
            n,
            vector<int>(n, INT_MAX)
        );

        dist[0][0] = grid[0][0];

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty()){

            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(cost > dist[x][y]){
                continue;
            }

            if(x == n - 1 && y == n - 1){
                return cost;
            }

            for(int k = 0; k < 4; k++){

                int new_x = x + dx[k];
                int new_y = y + dy[k];

                if(new_x >= 0 && new_x < n &&
                   new_y >= 0 && new_y < n){

                    int new_cost =
                        max(cost, grid[new_x][new_y]);

                    if(new_cost < dist[new_x][new_y]){

                        dist[new_x][new_y] = new_cost;

                        pq.push({
                            new_cost,
                            {new_x, new_y}
                        });
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};

class DSU{

public:

    vector<int> parent, size;

    DSU(int n){

        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){

        if(node == parent[node]){
            return node;
        }

        return parent[node] =
            findUPar(parent[node]);
    }

    void unionBySize(int u, int v){

        u = findUPar(u);
        v = findUPar(v);

        if(u == v){
            return;
        }

        if(size[u] < size[v]){
            swap(u, v);
        }

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution_By_DisJointSet {
public:

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<pair<int,int>> pos(n * n);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                pos[grid[i][j]] = {i, j};
            }
        }

        DSU ds(n * n);

        vector<vector<bool>> active(
            n,
            vector<bool>(n, false)
        );

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for(int t = 0; t < n * n; t++){

            auto [x, y] = pos[t];

            active[x][y] = true;

            int node = x * n + y;

            for(int k = 0; k < 4; k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || nx >= n ||
                   ny < 0 || ny >= n ||
                   !active[nx][ny]){
                    continue;
                }

                int adjNode = nx * n + ny;

                ds.unionBySize(node, adjNode);
            }

            if(ds.findUPar(0) ==
               ds.findUPar(n * n - 1)){

                return t;
            }
        }

        return -1;
    }
};

int main(){
    
    return 0;
}
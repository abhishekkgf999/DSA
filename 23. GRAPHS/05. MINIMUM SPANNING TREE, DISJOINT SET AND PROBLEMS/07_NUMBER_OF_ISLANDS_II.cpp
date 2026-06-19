/*
====================================================
NUMBER OF ISLANDS II
CodingNinjas:
https://www.naukri.com/code360/problems/number-of-islands-ii_1266048
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Initially all cells are water
    • Queries are provided

Each query:
✔ Converts one water cell into land

Goal:
✔ After every query,
  return current number of islands

----------------------------------------------------
Island means:
✔ Connected land cells
✔ Connected in 4 directions

====================================================
CORE IDEA: DYNAMIC ISLAND FORMATION ⭐
----------------------------------------------------
Unlike Number of Islands-I:

✔ Grid is not fixed

Here:
✔ Islands are created dynamically

After every operation:
✔ We need current island count

----------------------------------------------------
Running DFS/BFS after every query
would be too expensive.

So:
✔ Use Disjoint Set Union (DSU)

====================================================
MAIN OBSERVATION ⭐
----------------------------------------------------
Whenever a new land appears:

Initially:
✔ it forms a new island itself

So:
    islands++

----------------------------------------------------
Example:

Before:

    0 0
    0 0

Add:

    (0,0)

Now:

    1 0
    0 0

Total islands:
✔ 1

====================================================
WHAT HAPPENS NEXT ?
----------------------------------------------------
After creating land:

Check all 4 neighbours.

----------------------------------------------------
If neighbour is:

✔ Water
      ignore

✔ Land
      possible merge

====================================================
IMPORTANT INSIGHT ⭐
----------------------------------------------------
Suppose:

    1 1

Initially:

✔ left land = island 1
✔ right land = island 2

Total:
    islands = 2

----------------------------------------------------
When we connect them:

Two islands become one.

So:

    islands--

----------------------------------------------------
Therefore:

Every successful union:
✔ decreases island count by 1

====================================================
WHY DSU WORKS ?
----------------------------------------------------
DSU helps answer:

✔ Are these two lands already
  part of same island?

----------------------------------------------------
If:

findUPar(u) == findUPar(v)

Then:
✔ already connected
✔ don't decrease islands

----------------------------------------------------
If different:

✔ merge them
✔ islands--

====================================================
SPECIAL EDGE CASE ⭐
----------------------------------------------------
Query may repeat:

Example:

Add:
    (1,2)

Again:

Add:
    (1,2)

----------------------------------------------------
Cell already land.

So:
✔ No change required

Simply:
✔ append current island count

====================================================
2D TO 1D MAPPING
----------------------------------------------------
DSU works on nodes.

Grid cells are coordinates:

    (row, col)

Convert into node number:

    node = row * m + col
    node = i*column + j

----------------------------------------------------
Example:

m = 4

(0,0) → 0
(0,1) → 1
(1,0) → 4
(2,3) → 11

====================================================
WHY PARENT IS INITIALIZED WITH -1 ?
----------------------------------------------------
Normal DSU:

✔ Every node exists initially

----------------------------------------------------
Here:

Initially:
✔ every cell is water

Meaning:
✔ node doesn't exist yet

So:

    parent[node] = -1

----------------------------------------------------
When land appears:

✔ create DSU node

    parent[node] = node
    size[node] = 1

====================================================
APPROACH
----------------------------------------------------

STEP 1: Initialize DSU
----------------------------------------------------
✔ parent = -1
✔ size = 0

Because:
✔ no land exists initially

----------------------------------------------------

STEP 2: Process each query
----------------------------------------------------
If cell already visited:

✔ answer = current islands
✔ continue

----------------------------------------------------

STEP 3: Create new island
----------------------------------------------------
✔ mark land

✔ initialize DSU node

✔ islands++

----------------------------------------------------

STEP 4: Check 4 neighbours
----------------------------------------------------
If neighbour:

✔ within bounds
✔ already land

Then:

✔ try union

----------------------------------------------------

STEP 5: Successful merge
----------------------------------------------------
If union succeeds:

✔ islands--

because:
✔ two islands become one

----------------------------------------------------

STEP 6: Store answer
----------------------------------------------------
After every query:

✔ push current islands count

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Repeated query possible
✔ Use 4-direction connectivity
✔ Successful union reduces islands
✔ Water cells are not DSU nodes
✔ Parent initialized with -1

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
Let:

Q = number of queries

----------------------------------------------------
TIME:
➡ O(Q × α(N×M))

Almost constant DSU operations.

----------------------------------------------------
SPACE:
➡ O(N × M)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem says:

✔ Dynamic island creation
✔ Online queries
✔ Merge neighbouring components

Think:

✔ Disjoint Set Union (DSU)

Core Formula:
----------------------------------------------------
New Land:
    islands++

Successful Union:
    islands--

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
public:

	vector<int> parent, size;

	DisJointSet(int N, int M){
		parent.resize(N * M, -1);
		size.resize(N * M, 0);
	}

	int findUPar(int node){

		if(parent[node] == node){
            return node;
        }

		return parent[node] = findUPar(parent[node]);
	}

	bool unionBySize(int u, int v){

		int ult_u = findUPar(u);
		int ult_v = findUPar(v);

		if(ult_u == ult_v){
            return false;
        }

		if(size[ult_u] < size[ult_v]){

			parent[ult_u] = ult_v;
			size[ult_v] += size[ult_u];

		}
        else{

			parent[ult_v] = ult_u;
			size[ult_u] += size[ult_v];
		}

		return true;
	}
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){

	DisJointSet ds(n, m);

	vector<vector<int>> vis(n, vector<int>(m, 0));

	vector<int> ans;

	int islands = 0;

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	for(auto it : q){

		int X = it[0];
		int Y = it[1];

		if(vis[X][Y] == 1){

			ans.push_back(islands);
			continue;
		}

		vis[X][Y] = 1;

		int node = (X * m) + Y;

		ds.parent[node] = node;
		ds.size[node] = 1;

		islands++;

		for(int k = 0; k < 4; k++){

			int new_X = X + dx[k];
			int new_Y = Y + dy[k];

			if(new_X >= 0 && new_X < n &&
			   new_Y >= 0 && new_Y < m &&
			   vis[new_X][new_Y] == 1){

				int new_node = (new_X * m) + new_Y;

				if(ds.unionBySize(node, new_node)){
                    islands--;
                }
			}
		}

		ans.push_back(islands);
	}

	return ans;
}

int main(){
    
    return 0;
}
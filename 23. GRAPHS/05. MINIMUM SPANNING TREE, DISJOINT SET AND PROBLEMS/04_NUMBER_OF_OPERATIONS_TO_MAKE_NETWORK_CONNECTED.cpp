/*
#NUMBER OF OPERATIONS TO MAKE NETWORK CONNECTED

LINK:-  https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/


#include<bits/stdc++.h>
using namespace std;

/*
💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • n computers
    • some existing cable connections

Goal:
✔ Connect all computers into
  one connected network

Operation:
✔ You can remove an existing cable
  and place it somewhere else

✔ Return minimum operations required

✔ If impossible → return -1

====================================================
CORE IDEA: CONNECTED COMPONENTS + DSU ⭐
----------------------------------------------------
Main observation:

To connect:
    n nodes

We need at least:
    n - 1 edges

----------------------------------------------------
If:
    total edges < n - 1

Then:
✔ impossible to connect graph

because:
✔ not enough cables exist

====================================================
MAIN INTUITION
----------------------------------------------------
Initially:

✔ every computer is separate component

Existing edges already connect
some computers together.

----------------------------------------------------
Example:
----------------------------------------------------
Components:

    {0,1,2}
    {3,4}
    {5}

Total components = 3

To connect all components:
✔ we need:
      components - 1

So:
✔ answer = 2

====================================================
WHY COMPONENTS - 1 ?
----------------------------------------------------
Suppose:

✔ k disconnected components exist

To connect them into ONE component:

✔ minimum required edges =
      k - 1

This is a standard graph property.

====================================================
WHY DISJOINT SET (DSU) ?
----------------------------------------------------
We need efficient way to:

✔ check whether two nodes
  already belong to same component

✔ merge components

DSU provides:
✔ find ultimate parent
✔ union components

====================================================
HOW DSU WORKS HERE
----------------------------------------------------
Initially:
✔ every node is its own parent

So:
✔ total components = n

----------------------------------------------------
For every edge:

If:
    parent(u) != parent(v)

Then:
✔ components are different
✔ connect them
✔ decrease component count

Otherwise:
✔ already connected
✔ no need to merge

====================================================
APPROACH
----------------------------------------------------

STEP 1: Check edge requirement
----------------------------------------------------
If:
    total edges < n-1

Then:
✔ impossible → return -1

----------------------------------------------------

STEP 2: Initialize DSU
----------------------------------------------------
Initially:
✔ every node is separate component

components = n

----------------------------------------------------

STEP 3: Process all connections
----------------------------------------------------
For every edge:

✔ If nodes belong to different components:
      merge them
      decrease components count

----------------------------------------------------

STEP 4: Final answer
----------------------------------------------------
If:
    connectedComponents remain

Then:
✔ required operations =
      connectedComponents - 1

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Minimum edges needed = n-1
✔ Components determine answer
✔ DSU efficiently merges components
✔ Path compression optimizes find()

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(E × α(N))

Nearly constant time DSU operations.

----------------------------------------------------
SPACE:
➡ O(N)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:
✔ connect graph components
✔ dynamic connectivity
✔ merge groups efficiently

Think:
✔ Disjoint Set Union (DSU)

Golden formula:
----------------------------------------------------
If graph has:
    k components

Required edges:
    k - 1

====================================================
*/
class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u = parent[u];
        int ult_v = parent[v];
        if(ult_u == ult_v) return;

        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];            
        } 
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(size < n-1) return -1;

        DisjointSet ds(n);

        int connectedComponents = n;

        for(int i = 0; i<size; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);

                connectedComponents--;
            }
        }

        return connectedComponents-1;
    }
};

int main(){
    
    return 0;
}
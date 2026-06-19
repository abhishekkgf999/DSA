/*
====================================================
PRIM'S ALGORITHM
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Prim's Algorithm is used to find:

✔ Minimum Spanning Tree (MST)

----------------------------------------------------
Minimum Spanning Tree means:

✔ Connect all nodes
✔ Graph remains connected
✔ No cycles formed
✔ Sum of edge weights is minimum

====================================================
CORE IDEA: GREEDY APPROACH ⭐
----------------------------------------------------
At every step:

✔ Choose the minimum weight edge
  that connects:
      visited node → unvisited node

----------------------------------------------------
This greedy choice guarantees:
✔ minimum total weight MST

====================================================
WHAT IS THE MAIN INTUITION ?
----------------------------------------------------
We gradually grow the MST.

Initially:
✔ only one node is included

Then:
✔ keep attaching nearest possible node
  using minimum weight edge

----------------------------------------------------
Priority Queue helps us:
✔ always fetch minimum edge first

====================================================
VERY IMPORTANT OBSERVATION ⭐
----------------------------------------------------
We DO NOT mark neighbours visited
while pushing into PQ.

Why?
----------------------------------------------------
Because:
✔ there may exist another edge
  with smaller weight reaching
  the same node later.

----------------------------------------------------
So:
✔ node is marked visited ONLY
  when popped from PQ

That guarantees:
✔ minimum weight edge is selected

====================================================
HOW MST IS FORMED
----------------------------------------------------
Whenever we pop:

    {weight, node}

from PQ:

✔ that edge becomes part of MST

✔ add its weight into answer

✔ expand its neighbours

====================================================
HOW TO PRINT MST EDGES ?
----------------------------------------------------
This code only returns:
✔ total weight of MST

----------------------------------------------------
To print actual MST:

Store:
    {weight, node, parent}

inside PQ.

Whenever node gets selected:
✔ edge:
      parent → node
  becomes part of MST.

====================================================
WHY PRIM'S WORKS
----------------------------------------------------
At every step:

✔ minimum safe edge is selected

Safe edge means:
✔ edge that does not form cycle
✔ still helps expand MST

====================================================
APPROACH
----------------------------------------------------

STEP 1: Initialize structures
----------------------------------------------------
✔ Min heap:
      {weight, node}

✔ visited array

✔ Start from node 0
      with weight 0

----------------------------------------------------

STEP 2: Process minimum edge
----------------------------------------------------
While PQ not empty:

✔ Extract minimum edge

✔ If already visited:
      skip

✔ Otherwise:
      include in MST

----------------------------------------------------

STEP 3: Expand neighbours
----------------------------------------------------
For every neighbour:

✔ If not visited:
      push edge into PQ

----------------------------------------------------

STEP 4: Final answer
----------------------------------------------------
✔ Sum of selected edges
  gives MST weight

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph must be connected
✔ MST exists only for connected graph
✔ Greedy choice ensures optimality
✔ Node marked visited only after pop
✔ Avoid cycles using visited array

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(E log V)

SPACE:
➡ O(V + E)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:
✔ connect all nodes
✔ minimum total edge weight
✔ no cycles

Think:
✔ Minimum Spanning Tree

And for MST:
✔ Prim's Algorithm
✔ Kruskal's Algorithm

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        int spanningTree(int V, vector<vector<int>> adj[]){

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            vector<int> vis(V, 0);

            pq.push({0,0});

            int sum = 0;

            while(!pq.empty()){

                auto [wt, node] = pq.top();
                pq.pop();

                if(vis[node] == 1) continue;

                vis[node] = 1;

                sum += wt;

                for(auto it : adj[node]){

                    int adjNode = it[0];
                    int adjWt = it[1];

                    if(!vis[adjNode]){
                        pq.push({adjWt, adjNode});
                    }
                }
            }

            return sum;
        }
};

int main(){
    
    return 0;
}
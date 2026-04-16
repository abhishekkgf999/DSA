/*
#DETECT A CYCLE IN AN UNDIRECTED GRAPH USING BFS
*/

#include<bits/stdc++.h>
using namespace std;

/*
====================================================
DETECT CYCLE IN UNDIRECTED GRAPH (USING BFS)
====================================================

💡 PROBLEM SUMMARY:
- Given an undirected graph
- Determine whether it contains a cycle

Cycle:
✔ A path where we return to a previously
  visited node (other than the parent).

====================================================
KEY IDEA: TRACK PARENT DURING BFS ⭐
----------------------------------------------------
In an undirected graph:

When visiting neighbours:
✔ If neighbour is NOT visited → continue BFS
✔ If neighbour is visited AND
   neighbour ≠ parent → cycle exists

Reason:
Because someone else must have visited it.

====================================================
WHY DO WE NEED PARENT?
----------------------------------------------------
Example edge:
    A ---- B

When exploring:
A → B
B → A

A is already visited but it is B's parent,
so it is NOT a cycle.

Hence we ignore parent node.

====================================================
APPROACH: BFS TRAVERSAL
----------------------------------------------------
Queue stores:
    (node, parent)

This allows us to track
where the node was discovered from.

----------------------------------------------------
STEPS:
----------------------------------------------------

1️⃣ Maintain visited array

2️⃣ Traverse all vertices
   (to handle disconnected graphs)

3️⃣ For each unvisited node:
   start BFS

4️⃣ During BFS:
   - Pop node from queue
   - Traverse all adjacent nodes

   If neighbour not visited:
        mark visited
        push (neighbour, current node)

   Else if neighbour ≠ parent:
        cycle detected → return true

5️⃣ If BFS completes without conflict
   → no cycle in that component

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + 2E)
(each vertex and edge visited)

SPACE COMPLEXITY:
➡ O(V)
(visited array + queue)

====================================================
KEY INTUITION
----------------------------------------------------
A visited neighbour that is NOT the parent
means another path reached the same node,
which forms a cycle.

====================================================
*/
class Solution{
    private:
        bool detect(int src, vector<int> adj[], int vis[]){
            vis[src] = 1;
            queue<pair<int,int>> q;
            q.push({src, -1});

            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto adjacentNode: adj[node]){
                    if(!vis[adjacentNode]){
                        vis[adjacentNode] = 1;
                        q.push({adjacentNode, node});
                    }
                    else if(parent != adjacentNode){
                        return true;
                    }
                }
            }

            return false;
        }

    public:
        bool isCycle(int V, vector<int> adj[]){
            int vis[V] = {0};
            for(int i = 0; i<V; i++){
                if(!vis[i]){
                    if(detect(i, adj, vis)) return true;
                }
            }

            return false;
        }
};

int main(){
    
    return 0;
}
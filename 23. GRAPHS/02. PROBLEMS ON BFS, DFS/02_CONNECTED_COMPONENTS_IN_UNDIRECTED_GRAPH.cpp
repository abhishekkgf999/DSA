/*
#CONNECTED COMPONENTS IN UNDIRECTED GRAPH

LINK:- https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
*/

#include<bits/stdc++.h>
using namespace std;


/*
💡 PROBLEM SUMMARY:
- Given:
    ✔ V vertices
    ✔ list of undirected edges
- Find all connected components in the graph

Connected Component:
✔ A group of nodes where every node is reachable
  from every other node in that group.

====================================================
KEY IDEA: GRAPH TRAVERSAL ⭐
----------------------------------------------------
We traverse the graph using BFS (or DFS).

Whenever we find an UNVISITED node:
✔ It means a new connected component starts.
✔ Traverse all nodes reachable from it.
✔ Store them in a temporary vector.

====================================================
APPROACH: BFS
----------------------------------------------------

STEP 1: BUILD ADJACENCY LIST
----------------------------------------------------
For each edge (u, v):
    adj[u].push_back(v)
    adj[v].push_back(u)

Because graph is UNDIRECTED.

----------------------------------------------------

STEP 2: VISITED ARRAY
----------------------------------------------------
Keeps track of nodes already explored
to avoid revisiting nodes.

----------------------------------------------------

STEP 3: TRAVERSE ALL VERTICES
----------------------------------------------------
For every node i:

If not visited:
    ✔ Start BFS
    ✔ Create temp vector
    ✔ Push node into queue
    ✔ Explore its neighbors
    ✔ Mark visited nodes
    ✔ Store nodes of this component

----------------------------------------------------

STEP 4: STORE COMPONENT
----------------------------------------------------
After BFS finishes:
    temp contains one connected component.

Push temp into answer.

====================================================
WHY THIS WORKS?
----------------------------------------------------
✔ BFS explores all reachable nodes
✔ Each BFS traversal covers one component
✔ Visited array prevents duplication

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)
(each node and edge visited once)

SPACE COMPLEXITY:
➡ O(V + E)
(adjacency list + visited + queue)

====================================================
ALTERNATIVE METHOD
----------------------------------------------------
✔ DFS traversal can also be used
✔ Same time complexity

====================================================
*/
class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int>> ans;
        vector<int> visited(V, 0);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                vector<int> temp;
                visited[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    temp.push_back(node);
                    for(auto it : adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                }
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}
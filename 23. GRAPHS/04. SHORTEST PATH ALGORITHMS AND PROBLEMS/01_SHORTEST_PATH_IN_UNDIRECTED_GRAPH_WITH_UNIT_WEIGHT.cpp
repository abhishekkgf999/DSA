/*
#SHORTEST PATH IN UNDIRECTED GRAPH WITH UNIT WEIGHT

LINK:- https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
*/

#include<bits/stdc++.h>
using namespace std;

/*
We use simple BFS traversal technique with just comparing the distance of current node with distance form prev. node to curr, and storing
in a distance vector.

Time complexity :- O(V + E)
Auxiliary Space :- O(V)
*/
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> dist(V, 1e9);
        queue<int> q;
        dist[src] =  0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i = 0; i<V; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
        
    }
};


int main(){
    
    return 0;
}
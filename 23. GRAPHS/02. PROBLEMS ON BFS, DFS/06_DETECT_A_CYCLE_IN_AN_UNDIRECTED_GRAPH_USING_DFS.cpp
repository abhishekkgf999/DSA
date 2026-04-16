/*
#DETECT A CYCLE IN AN UNDIRECTED GRAPH USING DFS
*/

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY :- O(N+2E) + O(N)
//SPACE COMPLEXITY :- O(N)
class Solution{
    private:
        bool dfs(int node, int parent, int vis[], vector<int> adj[]){
            vis[node] = 1;
            for(auto adjacentNode : adj[node]){
                if(!vis[adjacentNode]){
                    if(dfs(adjacentNode, node, vis, adj) == true) return true;
                }
                else if(adjacentNode != parent) return true;
            }

            return false;
        }

    public:
        bool isCycle(int V, vector<int> adj[]){
            int vis[V] = {0};
            for(int i = 0; i<V; i++){
                if(!vis[i]){
                    if(dfs(i, -1, vis, adj) == true) return true;
                }
            }

            return false;
        }      
};

int main(){
    
    return 0;
}
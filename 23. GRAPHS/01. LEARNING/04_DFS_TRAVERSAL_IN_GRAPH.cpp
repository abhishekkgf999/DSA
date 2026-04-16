/*
#DFS TRAVERSAL IN GRAPH
*/

#include<bits/stdc++.h>
using namespace std;

//space complexity :- O(N)
//time complexity :- O(N) + O(2*E) where E = number of edges
class Solution{
    private:
        void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
            vis[node] = 1;  //mark the node visited
            ls.push_back(node); //store in answer array
            

            //traverse neighbour nodes depth wise via recursion
            for(auto it: adj[node]){
                if(!vis[it]){   //if the node is not visited, only then call dfs function for that
                    dfs(it, adj, vis, ls);
                }
            }
        }
    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            int vis[V] = {0};   //creating visited array of size V (number of vertices)
            int start = 0;  //start node will be 0 because it is give as 0-based indexing
            vector<int> ls; //answer list to store dfs traversal
            dfs(start, adj, vis, ls);   //calling dfs function for dfs traversal
            return ls;  
        }
};

int main(){
    vector<int> adj[8] = {{1,2}, {0,4,5}, {0,3,6}, {2,7}, {1}, {1}, {2,7}, {3,6}};
    int node = 8;
    Solution obj;
    vector<int> dfs = obj.dfsOfGraph(node, adj);
    for(auto i : dfs) cout<<i<<" ";
    return 0;
}
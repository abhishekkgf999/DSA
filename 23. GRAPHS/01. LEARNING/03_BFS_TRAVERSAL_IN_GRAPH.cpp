/*
#BFS TRAVERSAL IN GRAPH
*/

#include<bits/stdc++.h>
using namespace std;

//space complexity :- O(N)
//time complexity :- O(N) + O(2*E)  //sum of all degrees in a graph = 2*E where E = number of edges
vector<int> bfsOfGraph(int V, vector<int> adj[]){
    int vis[V] = {0};   //visited array - 0 based indexing, initially all set to unvisited(0)
    vis[0] = 1; //mark first vertex as visited

    queue<int> q;
    q.push(0);  //insert firt vertex
    vector<int> bfs; //bfs traversal in this vector

    while(!q.empty()){  //This part is running for Number of vertices
        int node = q.front();   // take the front node
        q.pop();
        bfs.push_back(node);    // push in bfs traversal

        //check for neighbour of node, put only when not visited
        for(auto it : adj[node]){   //This for loop is taking time complexity of degree of node, which will become total at last = 2*E
            if(!vis[it]){   //if not visited
                vis[it] = 1;    //mark visited
                q.push(it);     //push into queue
            }
        }
    }
    
    return bfs;
}

int main(){
    
    return 0;
}
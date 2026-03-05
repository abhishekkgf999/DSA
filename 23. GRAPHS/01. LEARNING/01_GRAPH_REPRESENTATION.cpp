#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;   //n -> number of nodes, m -> number of edges
    cin>>n>>m;

    //Method 1: Adjacency Matrix
    //space complexity:- O(N^2)
    int adj[n+1][n+1];  //adjacency matrix to store the graph
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    

    //Method 2: Adjacency List
    //space complexity:- O(2E) where E = edges
    /*
    adj[0] → vector
    adj[1] → vector
    adj[2] → vector
    ...
    adj[n] → vector

    So structure becomes:

    [
        vector<int>,
        vector<int>,
        vector<int>,
        ...
    ]
    */
    vector<int> adj2[n+1];  //creating array of vectors, and it will store only 2*E numbers
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    //FOR DIRECTED GRAPH, WE ONLY STORE ONE DIRECTION NOT VISE-VERSA
    //AND SPACE COMPLEXITY WILL BE O(E)  because its not undirected so only one edge correspond to other edge, not both wasy
    vector<int> adj3[n+1];  //creating array of vectors, and it will store only 2*E numbers
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        //u ----> v
        adj3[u].push_back(v);
        // adj3[v].push_back(u);
    }

    //FOR STORING ADJACENCY MATRIX WITH WEIGHT, WE SIMPLY PUT WEIGHT VALUE RAHTER THAN 1
    int adj4[n+1][n+1];  //adjacency matrix to store the graph
    for(int i = 0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        adj4[u][v] = wt;
        adj4[v][u] = wt;
    }
    
    //FOR STORING ADJACENCY LIST WITH WEIGHT, WE SIMPLY STORE ARRAY OF VECTORS AND VECTORS OF PAIRS(node, weight)
    vector<pair<int,int>> adj5[n+1];  //creating array of vectors, and it will store only 2*E numbers
    for(int i = 0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        adj5[u].push_back({v, wt});
        adj5[v].push_back({u, wt});
    }

    return 0;
}
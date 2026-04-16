/*
#NUMBER OF PROVINCES

LINK:- https://leetcode.com/problems/number-of-provinces/#:~:text=A%20province%20is%20a%20group,the%20total%20number%20of%20provinces.
*/


#include<bits/stdc++.h>
using namespace std;

/*
Simple solution with any traversal can be used here, we used bfs traversal here, and simply keep a counter connected, whenever we make a new component
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        vector<int> visited(V, 0);
        

        //converting given matrix into adjacency list
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(i!=j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        int connected = 0;

        //bfs traversal
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                connected++;
                visited[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                }
            }
        }

        return connected;

    }
};

//clean solution
class Solution2 {
 private:
    void dfs(vector<int>& vis,vector<vector<int>>& isConnected,int i){
           vis[i] =1;
           for(int j=0;j<isConnected.size();j++){
              if(!vis[j] && isConnected[i][j] ==1){
                dfs(vis,isConnected,j);
              }
           }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

           vector<int>vis(n,0);
           int cnt =0;
         
         for( int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(vis,isConnected,i);
            }
         }
         return cnt;
    }
};

int main(){
    
    return 0;
}
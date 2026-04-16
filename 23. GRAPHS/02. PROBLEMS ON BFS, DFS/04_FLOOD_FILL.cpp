/*
#FLOOD FILL

LINK:- https://leetcode.com/problems/flood-fill/description/
*/

#include<bits/stdc++.h>
using namespace std;

//time complexity:- O(N*M)
//Space complexity:- O(N*M)

class Solution1 {
public:
    void bfs(vector<vector<int>>& image, queue<pair<int,int>> &q, int prev, int color){
        int row = image.size();
        int col = image[0].size();
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<int,int> temp = q.front();
                q.pop();

                int i = temp.first;
                int j = temp.second;

                if(i-1 > 0 && image[i-1][j] == prev){
                    q.push({i-1, j});
                    image[i-1][j] = color;
                }

                if(i+1 < row && image[i+1][j] == prev){
                    q.push({i+1, j});
                    image[i+1][j] = color;
                }

                if(j-1 > 0 && image[i][j-1] == prev){
                    q.push({i, j-1});
                    image[i][j-1] = color;
                }

                if(j+1 < col && image[i][j+1] == prev){
                    q.push({i, j+1});
                    image[i][j+1] = color;
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        int prev = image[sr][sc];
        image[sr][sc] = color;

        bfs(image, q, prev, color);

        return image;
    }
};

//short and concise solution of this question, using dfs traversal
class Solution2 {
public:
    void dfs(vector<vector<int>>& image,int r,int c,int oc,int color){
        int n=image.size();
        int m=image[0].size();

        if(r<0 || c<0 || r>=n || c>=m || image[r][c]!=oc)
            return;

        image[r][c]=color;

        dfs(image,r+1,c,oc,color);
        dfs(image,r-1,c,oc,color);
        dfs(image,r,c+1,oc,color);
        dfs(image,r,c-1,oc,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc=image[sr][sc];

        if(oc==color) return image;

        dfs(image,sr,sc,oc,color);

        return image;
    }
};

int main(){
    
    return 0;
}
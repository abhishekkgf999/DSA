#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> i_know(row, 0);
        vector<int> know_me(row, 0);
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mat[i][j] == 1) {   // ✅ only count when i knows j
                    i_know[i]++;
                    know_me[j]++;
                }
            }
        }
        
        for(int i = 0; i < row; i++) {
            // ✅ celebrity knows no one and everyone knows them
            if(i_know[i] == 0 && know_me[i] == row - 1)
                return i;
        }
        
        return -1;
    }
};


int main(){
    Solution obj;
    vector<vector<int>> mat = {{0, 1, 1, 0},
                               {0, 0, 0, 0},
                               {0, 1, 0, 0},
                               {1, 1, 0, 0}};

    cout<<obj.celebrity(mat);
    return 0;
}
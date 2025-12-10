/*
#RAT IN A MAZE PROBLEM

LINK :- https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

/*
1. **Analyze the Function Calls**:
   - The `solve` function uses recursion, and for every cell `(x, y)` in the maze, it checks up to **4 possible directions** (`DOWN`, `LEFT`, `RIGHT`, `UP`).
   - If each direction leads to another valid cell, the function makes a recursive call for that cell.
   - Therefore, for each cell, there can be up to **4 recursive calls**.

2. **Count the Number of Cells**:
   - The maze has `N x M` cells, where `N` is the number of rows and `M` is the number of columns. In the worst case, all cells are accessible (i.e., there are no blocked cells), so the algorithm may need to explore every cell.

3. **Consider Worst-Case Recursion**:
   - In the worst-case scenario, the algorithm explores all possible paths starting from the top-left cell to the bottom-right cell.
   - Each cell has up to **4 choices**, leading to a branching factor of **4** at each step. Since there are `N x M` cells, the total number of recursive calls is approximately **`O(4^(N*M))`**.

4. **Combine Observations**:
   - The number of recursive calls grows exponentially because of the 4 possible directions at each step.
   - Thus, the time complexity is **`O(4^(N*M))`**, where `N` is the number of rows and `M` is the number of columns.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int row, int col, vector<vector<int>> &visited, vector<vector<int>> &mat){
    /*
    #3 ESSENTIAL CONDITION TO GET VALID MOVE
        I. Within range: x and y are between 0 and maze dimensions (row and col).
        II. Not visited: The cell must not have been visited (visited[x][y] == 0).
        III. Not blocked: The cell must be open (mat[x][y] == 1).
    */
        if((x>=0 && x<row) && (y>=0 && y<col) && visited[x][y] == 0 && mat[x][y] == 1){
            return true;
        }
        return false;
    }
    
void solve(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &visited, int x, int y, vector<string> &ans, string path){
    //BASE CASE :- WHEN WE REACH LAST COORDINATE
    if(x == row-1 && y == col-1){
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    
    //4 CHOICES :- DOWN LEFT RIGHT UP
    
    //MOVING DOWN
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, row, col, visited, mat)){
        path.push_back('D');
        solve(mat, row, col, visited, newx, newy, ans, path);
        path.pop_back();
    }
    
    //MOVING LEFT
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, row, col, visited, mat)){
        path.push_back('L');
        solve(mat, row, col, visited, newx, newy, ans, path);
        path.pop_back();
    }
    
    //MOVING RIGHT
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, row, col, visited, mat)){
        path.push_back('R');
        solve(mat, row, col, visited, newx, newy, ans, path);
        path.pop_back();
    }
    
    //MOVING UP
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, row, col, visited, mat)){
        path.push_back('U');
        solve(mat, row, col, visited, newx, newy, ans, path);

        //WHILE BACKTRACKING, WE MUST ENSURE THAT, WE HAVE TO POP THAT CHARACTER FROM PATH STRING
        path.pop_back();
    }
    
    //Unmarks the position visited[x][y] = 0 before returning to allow other paths to use it during recursion.
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    int row = mat.size(), col = mat[0].size();
    
    //WHEN DESINATION IS NOT REACHABLE
    if(mat[0][0] == 0 || mat[row-1][col-1] == 0) return ans;
    
    //TRACKING VISITED PATH
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int srcx = 0, srcy = 0;
    string path = "";
    
    solve(mat, row, col, visited, srcx, srcy, ans, path);
    
    return ans;
}

int main(){
    
    return 0;
}
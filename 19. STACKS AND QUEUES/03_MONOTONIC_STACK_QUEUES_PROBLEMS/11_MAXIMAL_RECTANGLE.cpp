/*
#MAXIMAL RECTANGLE

LINK:- https://leetcode.com/problems/maximal-rectangle/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int max_area = 0;

        vector<vector<int>> heights(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0 ? 1 : heights[i - 1][j] + 1);
                }
            }
        }

        vector<vector<int>> nse(row, vector<int>(col));
        vector<vector<int>> pse(row, vector<int>(col));

        for (int i = 0; i < row; i++) {
            stack<int> st;
            for (int j = col - 1; j >= 0; j--) {
                while (!st.empty() && heights[i][j] <= heights[i][st.top()]) {
                    st.pop();
                }

                nse[i][j] = st.empty() ? col : st.top();

                st.push(j);
            }
        }

        for (int i = 0; i < row; i++) {
            stack<int> st;
            for (int j = 0; j < col; j++) {
                while (!st.empty() && heights[i][j] < heights[i][st.top()]) {
                    st.pop();
                }

                pse[i][j] = st.empty() ? -1 : st.top();

                st.push(j);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int width = nse[i][j] - pse[i][j] - 1;
                int height = heights[i][j];

                max_area = max(max_area, width * height);
            }
        }

        return max_area;
    }
};

int main(){
    Solution obj;
vector<vector<char>> matrix = {{'1','0','1','0','0'},
                               {'1','0','1','1','1'},
                               {'1','1','1','1','1'},
                               {'1','0','0','1','0'}};
                                
    cout<<obj.maximalRectangle(matrix);
    return 0;
}
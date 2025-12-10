/*

#PASCALS TRIANGLE

LINK:- https://leetcode.com/problems/pascals-triangle/description/


Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

*/


/*
#Intuition:
The problem of generating Pascal's triangle can be approached in various ways.
Here are some approaches and their intuition to solve the problem:

Approach 1: Using Recursion
 => Intuition: In Pascal's triangle, each element is the sum of the two elements directly above it. 
    We can use a recursive approach to generate the triangle. The base case is when numRows is 1, 
    in which case we return [[1]]. Otherwise, we recursively generate the triangle for numRows - 1 
    and then calculate the current row by summing the adjacent elements from the previous row.

Approach 2: Using Combinatorial Formula
 => Intuition: Pascal's triangle can also be generated using combinatorial 
    formula C(n, k) = C(n-1, k-1) + C(n-1, k), where C(n, k) represents the binomial coefficient. 
    We can calculate each element of the triangle using this formula. This approach avoids the need 
    for storing the entire triangle in memory, making it memory-efficient.

Approach 3: Using Dynamic Programming with 1D Array
 => Intuition: We can use a dynamic programming approach with a 1D array to generate Pascal's 
    triangle row by row. Instead of maintaining a 2D array, we can use a single array to store 
    the current row and update it as we iterate through the rows. This approach reduces space complexity.

Here's a brief outline of each approach:

1. Recursion Approach:

    => Base case: If numRows is 1, return [[1]].
    => Recursively generate the triangle for numRows - 1.
    => Calculate the current row by summing adjacent elements from the previous row.

2. Combinatorial Formula Approach:

    => Use the binomial coefficient formula C(n, k) to calculate each element.
    => Build the triangle row by row using the formula.

3. Dynamic Programming with 1D Array:

    => Initialize a 1D array to store the current row.
    => Iterate through numRows and update the array for each row.

#Complexity:
    In terms of time complexity, all three methods have the same overall time complexity of O(numRows^2) 
    because we need to generate all the elements of Pascal's triangle. However, in terms of space complexity, 
    Method 3 is the most efficient as it uses only O(numRows) space, while the other two methods use 
    O(numRows^2) space due to storing the entire triangle or previous rows in recursion.

*/

#include<bits/stdc++.h>
using namespace std;

//Best and optimal solution (using DP) TC:- O(numRows^2) and SC:- O(numRows)
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 0; i<numRows; i++){
            vector<int> temp(i+1 , 0);
            for(int j = 0; j<=i; j++){
                if(j == 0 || j == i){
                    temp[j] = 1;          
                }
                else{
                    temp[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            ans.push_back(temp);
        }

        return ans;
}

int main(){
    
    int numRows = 5;

    vector<vector<int>> ans = generate(numRows);
    
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }cout<<endl;
    }
    return 0;
}
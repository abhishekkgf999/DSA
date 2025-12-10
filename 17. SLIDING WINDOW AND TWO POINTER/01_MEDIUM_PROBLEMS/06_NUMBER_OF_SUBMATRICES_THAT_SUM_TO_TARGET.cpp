/*
#NUMBER OF SUBMATRICES THAT SUM TO TARGET

LINK:- https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
*/


#include<bits/stdc++.h>
using namespace std;

//CREATE ALL POSSIBLE SUBMATRCES AND CALCULATE THEIR SUM
class Solution_BRUTE_FORCE {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        for (int sr = 0; sr < m; sr++) {
            for (int sc = 0; sc < n; sc++) {
                for (int er = sr; er < m; er++) {
                    for (int ec = sc; ec < n; ec++) {
                        int sum = 0;
                        for (int start = sr; start <= er; start++) {
                            for (int end = sc; end <= ec; end++) {
                                sum += matrix[start][end];
                            }
                        }
                        if (sum == target)count++;
                    }
                }
            }
        }

        return count;
    }
};

int main() {

    return 0;
}
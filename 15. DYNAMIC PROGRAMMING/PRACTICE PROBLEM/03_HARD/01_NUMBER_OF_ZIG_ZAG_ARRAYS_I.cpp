/*
#NUMBER OF ZIG-ZAG ARRAYS I

link:- https://leetcode.com/problems/number-of-zigzag-arrays-i/?envType=daily-question&envId=2026-06-23
*/

#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION -> GIVING TLE
#define MOD 1000000007
#define ll long long 
class Solution {
    int N, M;
    int dp[2001][2001][2];
    int solve(int ind, int prev, bool increasing){  //TIME COMPLEXITY -> O(N*M)
        if(ind == N) return 1;

        if(dp[ind][prev][increasing] != -1) return dp[ind][prev][increasing];

        ll result = 0;

        if(increasing){
            for(int nextVal = prev+1; nextVal <= M; nextVal++){
                result += solve(ind+1, nextVal, false)%MOD;
            }
        }else{
            for(int nextVal = 1; nextVal < prev; nextVal++){
                result += solve(ind+1, nextVal, true)%MOD;
            }
        }

        return dp[ind][prev][increasing] = result;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r-l+1;
        ll result = 0;
        memset(dp, -1, sizeof(dp));

        for(int startVal = 1; startVal<=M; startVal++){     //TIME COMPLEXITY :- O(N*M*M*2)
            result += solve(1, startVal, true)%MOD;  //increasing
            result += solve(1, startVal, false)%MOD; //decreasing
        }

        return result;
    }
};

//TABULATION OF ABOVE MEMOIZATION, STILL TC:- O(N*M*M) GIVES TLE
class Solution2 {
    int N, M;
    ll dp[2001][2001][2];
public:
    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r-l+1;
        ll result = 0;
        memset(dp, 0, sizeof(dp));

        for(int val = 1; val<=M; val++){
            dp[n][val][1] = 1;
            dp[n][val][0] = 1;
        }

        for(int i = N-1; i>=0; i--){
            for(int prevVal = 1; prevVal <= M; prevVal++){
                for(int nextVal = prevVal+1; nextVal <= M; nextVal++){
                    dp[i][prevVal][1] = (dp[i][prevVal][1] + dp[i+1][nextVal][0]) % MOD;
                }
                for(int nextVal = 1; nextVal < prevVal; nextVal++){
                    dp[i][prevVal][0] = (dp[i][prevVal][0] + dp[i+1][nextVal][1]) % MOD;
                }
            }
        }

        for(int startVal = 1; startVal <= M; startVal++){
            result += dp[1][startVal][1]%MOD;
            result += dp[1][startVal][0]%MOD;
        }

        return result;
    }
};


/*
This one is optimized version of above, we used prefix sum to accumulate all the previous value, we take two separate prefix sum for increasing and decreasing

TC:- O(N*M)
*/

class Solution3 {
    int N, M;
    vector<vector<array<ll, 2>>> dp;

public:
    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r - l + 1;
        ll result = 0;

        ll dp[2001][2001][2];

        for (int val = 1; val <= M; val++) {
            dp[N][val][1] = 1;
            dp[N][val][0] = 1;
        }

        for (int i = N - 1; i >= 1; i--) {
            vector<ll> cumSum1(M + 2, 0);
            vector<ll> cumSum0(M + 2, 0);

            for (int val = 1; val <= M; val++) {
                cumSum0[val] = (cumSum0[val - 1] + dp[i + 1][val][0]) % MOD;
                cumSum1[val] = (cumSum1[val - 1] + dp[i + 1][val][1]) % MOD; 
            }

            for (int prevVal = 1; prevVal <= M; prevVal++) {

                dp[i][prevVal][1] = (cumSum0[M] - cumSum0[prevVal] + MOD) % MOD;
 
                dp[i][prevVal][0] = cumSum1[prevVal - 1];
            }
        }

        for (int startVal = 1; startVal <= M; startVal++) {
            result = (result + dp[1][startVal][1]) % MOD; 
            result = (result + dp[1][startVal][0]) % MOD;
        }

        return (int)result;
    }
};

int main(){
    
    return 0;
}
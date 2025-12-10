/*
#TRAPPING RAIN WATER

LINK:- https://leetcode.com/problems/trapping-rain-water/description/
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE TC:- O(N^2), SC:- O(1)
/*
=> FOR EACH BLOCK WE WILL FIND ITS RIGHT GREATEST AND LEFT GREATEST
=> WE ITERATE FOR EACH BUILDING BLOCK
*/
class Solution_BruteForce {
    // Note: The implementation here is actually the O(N) time, O(N) space prefix/suffix approach.
    // The true O(N^2) brute force would compute max_left and max_right for *each* index inside the main loop.
    int trapPrefixSuffix(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += min(leftMax[i], rightMax[i]) - height[i];

        return ans;
    }
public: // Making it public to call it from main
    int trap(vector<int>& height) {
        return trapPrefixSuffix(height);
    }
};

//BETTER SOLUTION TC:- O(N), SC:- O(N)
/*
=> IN THIS APPROACH, WE WILL INITIALLY 
*/
class Solution_prefix_suffix_approach {
public: // Making it public to call it from main
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n);
        vector<int> rmax(n);

        lmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], height[i]);
        }

        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(lmax[i], rmax[i]) - height[i];
        }

        return ans;
    }
};

//OPTIMAL SOLUTION (TWO POINTER APPROACH) TC:- O(N), SC:- O(1)
class Solution_two_pointer {
public: // Making it public to call it from main
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= lmax) {
                    lmax = height[l];
                }
                else {
                    ans += lmax - height[l];
                }
                l++;
            }
            else {
                if (height[r] >= rmax) {
                    rmax = height[r];
                }
                else {
                    ans += rmax - height[r];
                }
                r--;
            }
        }

        return ans;
    }
};

int main() {
    // Example test case from LeetCode: [0,1,0,2,1,0,1,3,2,1,2,1] -> Result: 6
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Instantiate and test the prefix/suffix approach (labeled as BruteForce)
    Solution_BruteForce sol_bf;
    int res_bf = sol_bf.trap(height);
    cout << "Prefix/Suffix (O(N) time, O(N) space) Result: " << res_bf << endl;

    // Instantiate and test the prefix/suffix approach (labeled as Better)
    Solution_prefix_suffix_approach sol_ps;
    int res_ps = sol_ps.trap(height);
    cout << "Better (O(N) time, O(N) space) Result: " << res_ps << endl;

    // Instantiate and test the Two-Pointer approach (labeled as Optimal)
    Solution_two_pointer sol_tp;
    int res_tp = sol_tp.trap(height);
    cout << "Optimal (O(N) time, O(1) space) Result: " << res_tp << endl;

    // You could add more test cases here to ensure correctness
    vector<int> height2 = {4, 2, 0, 3, 2, 5}; // Result: 9
    cout << "\nTest Case 2: {4, 2, 0, 3, 2, 5}" << endl;
    cout << "Optimal Result: " << sol_tp.trap(height2) << endl;

    return 0;
}
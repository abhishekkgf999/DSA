/*
#LARGEST RECTANGLE IN HISTOGRAM

LINK:- https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int> &heights){
        stack<int> st;
        vector<int> result(heights.size());
        for(int i = heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }

            result[i] = (st.empty()) ? heights.size() : st.top(); 

            st.push(i);
        }

        return result;
    }
    vector<int> prevSmaller(vector<int> &heights){
        stack<int> st;
        vector<int> result(heights.size());
        for(int i = 0; i<heights.size(); i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }

            result[i] = (st.empty()) ? -1 : st.top(); 

            st.push(i);
        }

        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmaller(heights);
        vector<int> pse = prevSmaller(heights);
        int ans = 0;

        for(int i = 0; i<heights.size(); i++){
            int width = (nse[i]-i)+(i-pse[i])-1;
            int height = heights[i];
            ans = max(ans, width*height);
        }

        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    cout<<obj.largestRectangleArea(heights);
    return 0;
}
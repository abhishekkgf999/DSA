/*

#LONGEST COMMON PREFIX

LINK:- https://leetcode.com/problems/longest-common-prefix/

*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION :- (TC:- O(n^2) & SC:- O(len))
string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];

        string ans = strs[0];

        for(int i = 1; i<strs.size(); i++){
            string temp = strs[i];
            int n1 = temp.size();
            int n2 = ans.size();
            if(n1 == 0 || n2 == 0) return "";
            else{
                 for(int i = 0; i<n2; i++){
                    if(ans[i] != temp[i] || i>n1){
                        ans.erase(i, n2-i+1);
                        break;
                    }
                 }
            }
        }

        return ans;
    }


//OPTIMAL SOLUTION (TC:- O(nlogn) and SC:- O(len))
string longestCommonPrefix_optimalSolution(vector<string> &strs){
    string ans = "";
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string first = strs[0], last = strs[n-1];
    for(int i = 0; i<min(first.size(), last.size()); i++){
        if(first[i] != last[i]){
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

int main(){
    // vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"flower", "flow", "_"};
    string ans = longestCommonPrefix(strs);
    cout<<ans<<endl;
    sort(strs.begin(), strs.end());
    for(auto i : strs)cout<<i<<" ";
    return 0;
}
/*
#COUNT NUMBER OF SUBSTRING  (Review this question)

LINK:- https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION(IN WORST CASE :- O(N^2), TC:- O(1))
int countSubstr(string& s, int k) {
        int count = 0;
        for(int i = 0; i<s.size(); i++){
            vector<int> freq(26, 0);
            int sum = 0;
            for(int j = i; j<s.size(); j++){
                if(freq[s[j]-'a'] == 0){
                    freq[s[j]-'a']++;
                    sum +=1;
                    if(sum > k) break;
                }
                if(sum == k) count++;
            }
        }
        return count;
    }

//OPTIMAL SOLUTION (TC:- O(N) & SC:- O(1))
/*
The idea in this is to use the sliding window approach as finding the number of substrings with exactly K distinct 
elements seems a tough task with sliding window. 

But, we can easily find the number of substrings with at most K distinct characters using sliding window. 
We can find the substring with exactly k distinct characters as ( Number of substrings with 
exactly K distinct characters = number of substrings with at most K distinct characters - number of substrings with at most K-1 distinct characters).


Ex:- s = "aba" & k = 2

We will find all substring with at most k distinct characters = 6

Then we find all substring with at most k-1 distinct characters = 3

now we subtract them, 6-3 = 3(which is the required ans)

3 is the exact number of substring with having k distinct characters
*/
int upto(string &s, int k ){
    int l = 0, r = 0, cnt = 0;
    int ans = 0;
    vector<int> mpp(26, 0);

    while(r<s.length()){
        mpp[s[r]-'a']++;
        if(mpp[s[r]-'a'] == 1) cnt++;
        while(cnt>k){
            mpp[s[l]-'a']--;    
            if(mpp[s[l]-'a'] <= 0){
                cnt--;
                l++;
            }
        }
        ans += r-l+1;
        r++;
    }

    return ans;
}
int countSubstr2(string& s, int k) {
        return upto(s, k)-upto(s, k-1);
    }


int main(){
    string s = "abaaca";
    int k = 1;
    cout<<countSubstr(s,k);
    return 0;
}
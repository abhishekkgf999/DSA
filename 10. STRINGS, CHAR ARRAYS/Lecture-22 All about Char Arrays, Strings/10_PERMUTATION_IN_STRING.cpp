/*
#PERMUTATION IN STRING (Mark for revision)

LINK:- https://leetcode.com/problems/permutation-in-string/description/
*/

#include<bits/stdc++.h>
using namespace std;

bool  checkequal (vector<int> &a, vector<int> &b) {
      for(int i=0; i<26; i++){
          if(a[i] != b[i]) return false;
          }
      return true;
}

bool checkInclusion(string s1, string s2) {
        if(s1.size() >s2.size()) return false;
        
        vector<int> freq1(26, 0);
        for(char c: s1) freq1[c-'a']++;
        
        vector<int> freq2(26, 0);
        int i=0, j=0;
        while(j<s2.size()) {
            freq2[s2[j]-'a']++;
            
            if(j-i+1 == s1.size()) {
                if(checkequal(freq1, freq2)) return true;
                }
            
            if(j-i+1 < s1.size()) j++;
             else{

                freq2[s2[i]-'a']--;

                i++;

                j++;

            }      
            
            
            }
      return false;
    }


int main(){
    string s1;
    cout<<"enter your string"<<endl;
    getline(cin, s1);

    string s2;
    cout<<"Enter 2nd string "<<endl;
    getline(cin, s2);
    cout<<checkInclusion(s1, s2)<<endl;
    return 0;
}
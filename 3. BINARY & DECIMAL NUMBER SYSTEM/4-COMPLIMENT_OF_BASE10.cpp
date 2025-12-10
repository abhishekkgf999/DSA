/*
****LEETCODE PROBLEM NUMBER - 1009****

link:- https://leetcode.com/problems/complement-of-base-10-integer/description/

==> The complement of an integer is the integer you get when you flip all the 0's to 1's 
    and all the 1's to 0's in its binary representation.

==> For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
    Given an integer n, return its complement.



*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        int mask = 0;
        //edge case
        if(n==0){
            cout<<"1";
        }
        while(m!=0){
            mask = (mask<<1) | 1;
            m = m>>1;
        }
        int ans = (~n) & mask;
        cout<< ans;
    }
};

int main(){
    Solution ob;
    int n;
    cin>>n;
    ob.bitwiseComplement(n);
}
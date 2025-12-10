/*
Q:- Number of 1 bits

link:-  https://leetcode.com/problems/number-of-1-bits/description/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(n&1) count++;
            n = n>>1;
        }
        return count;
    }
};

int main(){
    Solution obj;
    int n;
    cout<<"Enter a number:- "<<endl;
    cin>>n;
    cout<<"Number of 1 bits are:- "<<obj.hammingWeight(n);
    return 0;
}
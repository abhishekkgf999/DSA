/*
#COUNT GOOD NUMBERS

LINK:- https://leetcode.com/problems/count-good-numbers/description/

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int M = 1e9+7;

//  METHOD - 1 
    ll power(ll base, ll power){
        ll result = 1;
        base = base%M;
        if(base == 0)return 0;

        while(power > 0){
            if(power&1) result = (result*base)%M;
            power = power/2;
            base = (base*base)%M;
        }
        return result;
    }

    int countGoodNumbers(ll n) {
        ll count_4 = n/2;
        ll count_5 = n-count_4;
        ll ans = ((power(4LL, count_4)%M * power(5LL, count_5)%M)%M);
        return (int)ans;
    }

//  METHOD - 2 (USING RECURSION)
    ll power2(ll b, ll e, ll ans) {
        //BASE CASE
        if(e == 0) return ans;
        if(e & 1) return power2(b, e - 1, (ans * b) % M);
        else return power2((b * b) % M, e / 2, ans);
    }

    int countGoodNumbers2(ll n) {
        ll temp = power2(20, n/2, 1);
        return (n & 1) ? (temp * 5) % M : temp;
    }

int main(){
    cout<<countGoodNumbers(50)<<endl;
    cout<<countGoodNumbers2(50)<<endl;
    return 0;
}
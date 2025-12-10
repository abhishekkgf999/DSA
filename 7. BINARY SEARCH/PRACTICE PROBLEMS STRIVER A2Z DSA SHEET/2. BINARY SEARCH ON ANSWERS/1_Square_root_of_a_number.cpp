/*

#SQUARE ROOT OF A NUMBER IN log(n)

LINK:- https://www.geeksforgeeks.org/problems/square-root/0
*/

#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int n) {
        long long int ans = -1; 
        long long int l = 1, r = n;
        while(l<=r){
            long long int mid = l + (r-l)/2;
            long long int value = mid*mid;
            if(value == n) return mid;
            else if(value >n) r = mid-1;
            else{
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }

int main(){
    long long int n = 5;
    cout<<floorSqrt(n);
    return 0;
}
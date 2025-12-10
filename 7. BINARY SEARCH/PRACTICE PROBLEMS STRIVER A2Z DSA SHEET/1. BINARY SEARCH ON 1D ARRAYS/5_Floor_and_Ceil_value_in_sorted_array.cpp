/*
#FLOOR/CEIL VALUE IN SORTED ARRAY

LINK:- https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=SUBMISSION

*/


#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &v, int x) {
        int n = v.size();
        int ans= -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] == x) return v[mid];
            else if(v[mid] < x){
                ans = v[mid];
                l = mid+1;
            } 
            else r = mid-1;
        }
      
      return ans;
    }

int findCeil(vector<int> &v, int x) {
        int n = v.size();
        int ans= -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid] == x) return v[mid];
            else if(v[mid] > x){
                ans = v[mid];
                r = mid-1;
            } 
            else l = mid+1;
        }
      
      return ans;
    }


pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int,int> p;
	p.first = findFloor(a,x);
	p.second = findCeil(a, x);
	return p;
}

int main(){
    vector<int> arr = {36, 82, 88, 56, 21, 17, 73, 86};
    int x = 17;

    pair<int, int> ans = getFloorAndCeil(arr, arr.size(), x);
    cout<<ans.first;
    cout<<ans.second;
    return 0;
}
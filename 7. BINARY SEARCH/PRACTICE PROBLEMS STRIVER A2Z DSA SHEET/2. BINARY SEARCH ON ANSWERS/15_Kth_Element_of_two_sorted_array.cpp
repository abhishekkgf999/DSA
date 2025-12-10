/*

#Kth Element of two Sorted Arrays

Link:- https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

*/


#include<bits/stdc++.h>
using namespace std;

int kthElement_Bruteforce(int k, vector<int>& arr1, vector<int>& arr2) {
        vector<int> temp;
        int n1 = arr1.size(), n2 = arr2.size();
        int l = 0, r = 0;
        while(l<n1 && r <n2){
            if(arr1[l] <= arr2[r]){
                temp.push_back(arr1[l]);
                l++;
            }
            else{
                temp.push_back(arr2[r]);
                r++;
            }
        }

        while(l<n1){
            temp.push_back(arr1[l]);
            l++;
        }

        while(r < n2){
            temp.push_back(arr2[r]);
            r++;
        }

        return temp[k-1];
    }

int kthElement_BetterSolution(int k, vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        int l = 0, r = 0;

        int count = 0;

        while(l<n1 && r <n2){
            if(arr1[l] <= arr2[r]){
                count++;
                if(count == k) return arr1[l];
                l++;
            }
            else{
                count++;
                if(count == k) return arr2[r];
                r++;
            }
        }

        while(l<n1){
            count++;
            if(count == k) return arr1[l];
            l++;
        }

        while(r < n2){
            count++;
            if(count == k) return arr2[r];
            r++;
        }

        return 0;
    }

//OPTIMAL SOLUTION
/*
#EDGE CASE

->  The maximum possible value of x: We want to build the left subarray of size k. So, the maximum possible value should be k. 
    But if we are considering arr1[] of size n1 and n1 < k, in that case, the maximum possible value will be n1. 
    So, after generalization, the maximum value will be min(k, n1), where n1 = the size of the smaller array. Here n1 = min(m, n).

->  The minimum possible value of x: Let’s understand this using an example, given arr1[] size i.e. m = 6, and arr2[] size i.e. 
    n = 5 and k = 7. Now, the lowest value of x(i.e. The no. of elements we should take from arr1[]) should be 2. If we have to build an 
    array of size, 7, and the maximum element we can take from arr2[] is 5, so, we have to take a minimum of 2 elements from arr1[].

->  So, the minimum possible value should be k-n2, where n2 = the size of the not-considered array i.e. the bigger array.

->  But if k < n2, the k-n2, will be negative. So, to handle this case, we will consider the minimum value as max(0, k-n2), 
    where n2 = the size of the bigger array, and here, n2 = max(m, n).
    
*/
int kthElement_OptimalSolution(int k, vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        if(n1 > n2) return kthElement_OptimalSolution(k, arr2, arr1);
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        //EDGE CASE
        int left = max(0, k - n2), right = min(k, n1);

        while(left<=right){
            int mid1 = (left+right)>>1;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < n1) r1 = arr1[mid1];
            if(mid2 < n2) r2 = arr2[mid2];

            if(mid1-1 >= 0) l1 = arr1[mid1-1];
            if(mid2-1 >= 0) l2 = arr2[mid2-1];

            if(l1<=r2 && l2<=r1){
                return max(l1, l2);
            }
            else if(l1 > r2){
                right = mid1-1;
            }
            else{
                left = mid1+1;
            }
        }
        return 0;
    }

int main(){
    // vector<int> arr1 = {2,3,6,7,9};
    // vector<int> arr2 = {1,4,8,10};
    vector<int> arr1 = {5,5,8,8,8,9,11,11,11,11,11};
    vector<int> arr2 = {4,4,4,4,6,8,9,9,9,11,13};

    // cout<<kthElement_Bruteforce(5, arr1, arr2);
    // cout<<kthElement_BetterSolution(5, arr1, arr2);
    cout<<kthElement_OptimalSolution(4, arr1, arr2);

    return 0;
}
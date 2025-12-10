/*

#MEDIAN OF TWO SORTED ARRAY (MARK FOR REVISION)

LINK:- https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
double findMedianSortedArrays_Bruteforce(vector<int> &nums1, vector<int> &nums2){
    vector<int> temp;
    double ans = 0;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()){
        if (nums1[i] < nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        }
        else{
            temp.push_back(nums2[j]);
            j++;
        }
    }

    while (i < nums1.size()){
        temp.push_back(nums1[i]);
        i++;
    }

    while (j < nums2.size()){
        temp.push_back(nums2[j]);
        j++;
    }

    int n = temp.size();

    if (n & 1){
        int ind = n / 2;
        ans = double(temp[ind]);
    }
    else{
        int ind1 = n / 2;
        int ind2 = ind1 - 1;
        ans = double(temp[ind1] + temp[ind2]) / 2;
    }

    return ans;
}

// BETTER SOLUTION
double findMedianSortedArrays_BetterSolution(vector<int> &nums1, vector<int> &nums2){
    // size of two given arrays:
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2; 
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2){
        if (nums1[i] < nums2[j]){
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            cnt++;
            i++;
        }
        else{
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    while (i < n1){
        if (cnt == ind1) ind1el = nums1[i];
        if (cnt == ind2) ind2el = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2){
        if (cnt == ind1) ind1el = nums2[j];
        if (cnt == ind2) ind2el = nums2[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1){
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

//OPTIMAL SOLUTION (TC:- O(log(n1 + n2)))
/*
->  Median creates a partition on the final merged array: Upon closer observation, 
    we can easily show that the median divides the final merged array into two halves. 

    Example:- arr1[] = {1,3,4,7,10,12}
              arr2[] = {2,3,6,15}

              merged array = [1,2,3,3,4,6,7,10,12,15]

              Left half -> 1,2,3,3,4  |  6,7,10,12,15 <- Right half
                                      v
                                  Partition (Exptected Median 5)  


->  n = n1 + n2

->  Each half contains (n+1/2) elements. => This will be valid for both even and odd case

->  Each half also contains x elements from the first array i.e. arr1[] and (n+1/2)-x elements from the second array i.e. arr2[]. 
    The value of x might be different for the two halves. For example, in the above array, the left half contains 3 elements from arr1[] 
    and 2 elements from arr2[].

    arr1[] = 1  3  4-(l1)  |  (r1)-7  10  12
                           |
    arr2[] = 2  3-(l2)     |  (r2)-6  15

->  There's no need to construct both halves. Once we have the correct left half, the right half is automatically determined, 
    consisting of the remaining elements not yet considered. Therefore, our focus will solely be on creating the unique left half.

->  How to form all configurations of the left half: We know that the left half will surely contain x elements from arr1[] and (n+1/2)-x elements from arr2[]. 
    Here the only variable is x. The minimum possible value of x is 0 and the maximum possible value is n1(i.e. The length of the considered array).

->  For all the values,[0, n1] of x, we will try to form the left half and then we will check if that half’s configuration is valid.

->  How to eliminate the halves based on the values of x: Binary search works by eliminating the halves in each step. 
    Upon closer observation, we can eliminate the halves based on the following conditions:

    =>  If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. So, we have to take less elements from arr1[] and more from arr2[]. 
        In such a scenario, we should try smaller values of x. To achieve this, we will eliminate the right half (high = mid-1).

    =>  If l2 > r1: This implies that we have considered more elements from arr2[] than necessary. So, we have to take less elements from arr2[] and more from arr1[]. 
        In such a scenario, we should try bigger values of x. To achieve this, we will eliminate the left half (low = mid+1).
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;

        int left = (n1 + n2 + 1)/2;

        int n = n1 + n2;

        while(low <= high){
            
            int mid1 = (low + high)>>1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];

            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 1) return max(l1, l2);
                return ((double)(max(l1,l2) + min(r1, r2)))/2.0;
            }
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }

        return 0;
    }

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double ans = findMedianSortedArrays(nums1, nums2);
    cout << ans;

    return 0;
}
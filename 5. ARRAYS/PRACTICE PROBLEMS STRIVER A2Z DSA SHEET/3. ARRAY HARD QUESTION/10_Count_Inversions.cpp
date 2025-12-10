/*

#COUNT INVERSIONS  (CONSIDER THIS SOLUTION :- https://www.youtube.com/watch?v=AseUmwVNaoY) => using merge sort

LINK:- https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1


Given an array of integers. Find the Inversion Count in the array.  
Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

#Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 

                  If the array is already sorted then the inversion count is 0.

                  If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:
Input: n = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: n = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: n = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.


Expected Time Complexity: O(nLogn).
Expected Auxiliary Space: O(n).
*/


#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:- O(N^2) & SC:- O(1))
long long int inversionCount(vector<long long> arr, int n) {

    long long int ans = 0;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]) ans++;
        }
    }

    return ans;
}

//OPTIMAL SOLUTION (TC:- O(nLogn) -> because we are using merge sort & SC:- O(N))
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}


int main(){

    vector<long long> arr = {2, 4, 1, 3, 5};

    int n = arr.size();

    long long int ans = inversionCount(arr, n);

    cout<<ans;

    return 0;
}
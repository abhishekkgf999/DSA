/*
GIVEN THAT GIVEN ARRAY IS SORTED, WE HAVE TO MERGE SUCH THAT 
RESULTANT ARRAY IS ALSO SORTED

LINK:- https://leetcode.com/problems/merge-sorted-array/
*/


#include<bits/stdc++.h>
using namespace std;

void mergesorted(vector<int> &arr1, int n, vector<int> &arr2, int m, vector<int> &arr3 ){
        int i=0, j=0;
        while(i<n && j<m){
            if(arr1[i] < arr2[j]){
                arr3.push_back(arr1[i++]);
            }
            else{
                arr3.push_back(arr2[j++]);
            }
        }
        
        //Filling rest of the elements remaining in array1 (if present)
        while(i<n){
            arr3.push_back(arr1[i++]);
        }
        //Filling rest of the elements remaining in array2 (if present)
        while(j<m){
            arr3.push_back(arr2[j++]);
        }
}

//OPTIMNAL APPROACH ()
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }

int main(){
    vector<int> arr1;
    vector<int> arr3;
    int n;
    cout<<"Enter the size of arr1 ";
    cin>>n;
    cout<<"enter the elements of arr1 "<<endl;
    for(int i=0; i<n; i++){
        int element;
        cin >> element;
        arr1.push_back(element);
    }    

    vector<int> arr2;
    int m;
    cout<<"Enter the size of arr2 "<<endl;
    cin>>m;

    cout<<"Enter the element of arr2 "<<endl;
    for(int i = 0; i<m; i++){
       int element;
        cin >> element;
        arr2.push_back(element);
    }cout<<endl;

    mergesorted(arr1, n, arr2,  m, arr3 );

    for(int i : arr3){
        cout<<i<<" ";
    }cout<<endl;
    

    return 0;
}
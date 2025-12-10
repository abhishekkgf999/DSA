/*
#Merge 2 sorted array

Link:-  https://www.codingninjas.com/studio/problems/sorted-array_6613259

#TEST CASE:
Input:- n = "4" m = "3"
a = [1,2,3,3]
b = [2,2,4]

output:- [1,2,3,4]  => ONLY UNIQUE ELEMENTS
*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION
//Time complexity: O(N + M) where N is the size of vector a and M is the size of vector b.
//Space complexity: O(N + M) where N is the size of vector a and M is the size of vector b.
vector < int > sortedArray1(vector < int > a, vector < int > b) {
    vector<int> ans;
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]< b[j]){
            ans.push_back(a[i]);
            i++;            
        }
        else if(a[i] > b[j]){
            ans.push_back(b[j]);
            j++;           
        }
        else{
            ans.push_back(a[i]);
            i++; 
            j++;
        }
    }

    while(i<a.size()){
        ans.push_back(a[i++]);
    }

    while(j<b.size()){
        ans.push_back(b[j++]);
    }

    vector<int> final_ans;
    final_ans.push_back(ans[0]);
   
        for(int j = 1; j<ans.size(); j++){
            if(ans[j-1] != ans[j]){
                final_ans.push_back(ans[j]);
            }
        }

    return final_ans;
}


/*
    USING SET(WHICH STORES ONLY DISTINCT VALUES)
    Time Complexity: O((m + n) * log n)
    Space Complexity: O(m + n)
*/
vector < int > sortedArray2(vector < int > a, vector < int > b) {
    set<int> s;
    for(auto i : a){
        s.insert(i);        //INSERTING AN ELEMENT IN SET TAKES O(logN) TIME, WHERE 'N' IS THE NUMBER OF ELEMENTS IN THE SET 
    }

    for(auto i : b){
        s.insert(i);
    }

    vector<int> ans(s.begin(), s.end());  // copying elements from the set to the vector, which takes O(n) time, where n is the number of elements in the set.

    return ans;
}

/*
    Time Complexity: O(N + M)
    Space Complexity: O(N + M)

    N and M are the sizes of array 'A' and 'B' respectively.
*/
vector < int > sortedArray3(vector < int > a, vector < int > b) {

    int n = a.size(), m = b.size();
    // Dynamic Array to store the union of 'a' and 'b'
    vector < int > unionArray;

    int i = 0, j = 0;
    // Iterating over both arrays
    while (i < n && j < m) {

        // Current element in a is smaller or 
        // equal to the current element in b
        if (a[i] <= b[j]) {

            // Checking whether same element 
            // exists in the 'unionArray' or not.
            if (unionArray.size() == 0 || unionArray.back() != a[i]) {
                unionArray.push_back(a[i]);
            }

            // Incrementing i
            ++i;
        } else {
            // A[i] > B[j]
            if (unionArray.size() == 0 || unionArray.back() != b[j]) {
                unionArray.push_back(b[j]);
            }

            // Incrementing j
            ++j;
        }
    }

    // Traversing over 'a' to insert 
    // elements which are left
    while (i < n) {
        if (unionArray.back() != a[i]) {
            unionArray.push_back(a[i]);
        }

        // Incrementing i
        ++i;
    }

    // Traverse over 'b' to insert 
    // elements which are left
    while (j < m) {
        if (unionArray.back() != b[j]) {
            unionArray.push_back(b[j]);
        }

        // Incrementing j
        ++j;
    }

    return unionArray;

}

int main(){
    vector<int> a = {1,2,3,3};
    vector<int> b = {2,2,4};
    vector<int> ans = sortedArray3(a,b);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}
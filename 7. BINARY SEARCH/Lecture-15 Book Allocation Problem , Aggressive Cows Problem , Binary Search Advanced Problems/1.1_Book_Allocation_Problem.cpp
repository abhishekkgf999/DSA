/*
#BOOK ALLOCATION PROBLEM (LINK:- https://www.codingninjas.com/studio/problems/allocate-books_1090540?leftPanelTab=0)

USING LINEAR SEARCH
*/




#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
    return low;
}

int main(){
    vector<int> arr;
    int n;
    int m;
    cout<<"enter the number of books "<<endl;
    cin>>n;
    cout<<"Enter the number of students :- "<<endl;
    cin>>m;
    cout<<"Enter the pages of each book:- "<<endl;
    int element;
    for(int i=0; i<n; i++){
        cin>>element;
        arr.push_back(element);
    }

    cout<<"minimum number of pages assigned to a student is:- "<<findPages(arr, n, m)<<endl;
    return 0;
}

/*
#SUM OF TWO ARRAYS

LINK:- https://www.codingninjas.com/studio/problems/sum-of-two-arrays_893186?leftPanelTab=0
*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION(BRUTE FORCE)
vector<int> findArraySum1(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	int size1 = n-1;
	int size2 = m-1;
	int n1=0, n2=0;
	for(int i=0; i<n; i++){
		n1 = (a[i]*pow(10, size1)) + n1;
		size1--;
	}
	for(int i=0; i<m; i++){
		n2 = (b[i]*pow(10, size2)) + n2;
		size2--;
	}

	int sum = n1+n2;
	while (sum > 0) {
        int var = sum % 10;
        ans.push_back(var);
        sum /= 10;
    }
	reverse(ans.begin(), ans.end());
	return ans;
}


//OPTIMAL SOLUTION
vector<int> findArraySum2(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
    int carry = 0;

    int i = n - 1;
    int j = m - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i];
            i--;
        }
        if (j >= 0) {
            sum += b[j];
            j--;
        }

        ans.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main(){
    vector<int> a;
    int n;
    cout<<"Enter the size of a array:- "<<endl;
    cin>>n;
    cout<<"Enter the elements of a array:- "<<endl;
    for(int i = 0; i<n; i++){
        int element;
        cin>>element;
        a.push_back(element);
    }

    vector<int> b;
    int m;
    cout<<"Enter the size of b array:- "<<endl;
    cin>>m;
    cout<<"Enter the elements of b array:- "<<endl;
    for(int i = 0; i<m; i++){
        int element;
        cin>>element;
        b.push_back(element);
    }

    vector<int> ans = findArraySum2(a,  n, b,  m);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}
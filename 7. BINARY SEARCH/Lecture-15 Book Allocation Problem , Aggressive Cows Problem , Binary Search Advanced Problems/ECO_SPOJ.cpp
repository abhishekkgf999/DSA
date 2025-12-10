// LINK OF QUESTION:- https://www.spoj.com/problems/EKO/


#include<bits/stdc++.h>
using namespace std;

int find_height(vector<long long int> &arr, long long int n, long long int m, long long int height ){
        long long int temp = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]>=height){
                temp += arr[i]-height;
            }
        }
        if(temp == m )return true;

        else return false;

}

int main(){
    vector<long long int> ans;
    long long int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        long long int element; 
        cin>>element;
        ans.push_back(element);
    }

    sort(ans.begin(), ans.end());

    long long int mini = *min_element(ans.begin(), ans.end());
    long long int maxi = *max_element(ans.begin(), ans.end());

    long long int  answer;

    for(long long int height = mini; height<=maxi; height++){
        if(find_height(ans, n, m, height) == true){
            answer = height;
        }

    }

    cout<<answer;
    
    return 0;
}
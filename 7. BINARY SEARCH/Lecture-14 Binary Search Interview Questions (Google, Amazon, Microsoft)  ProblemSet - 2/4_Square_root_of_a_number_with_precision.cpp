#include<iostream>
using namespace std;

long long int SqrtInteger(int n)
{
    
    long long int ans=-1;

    long long int left = 0, right = n;
    long long int mid = left + (right-left)/2;
    while(left<=right){
        if((mid*mid)==n){return mid;}
        if((mid*mid)>n){
            right = mid-1;
        }
        else if((mid*mid)<n){
            ans = mid;
            left = mid+1;
        }
        mid = left + (right-left)/2;
    }
    return ans;
}

double setPrecision(int n, int pre, int ans){
    double factor = 1;
    double temp = ans;
    for(int i=0; i<pre; i++){
        factor = factor/10;
        for(double j=temp; (j*j)<n; j = j + factor){
             temp = j;
        }
    }
    return temp;
}

int main(){
    int n;
    cout<<"Enter the number:- "<<endl;
    cin>>n;
    int temp = SqrtInteger(n);
    cout<<"Answer is "<<setPrecision(n, 3, temp)<<endl;
    return 0;
}
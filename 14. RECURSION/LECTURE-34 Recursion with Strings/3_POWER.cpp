#include<iostream>
#include<string>
using namespace std;

int power(int num, int p){
    if(p == 0){
        return 1;
    }

    if(p == 1){
        return num;
    }

    int ans = power(num, p/2);

    if(p%2 == 0){
        return ans*ans;
    }
    else{
        return num * ans * ans;
    }

}

int main(){
   int num, p;
   cout<<"Enter your number:- "<<endl;
   cin>>num;
   cout<<"Enter power:- "<<endl;
   cin>>p;

   cout<<"Ans:- "<<power(num, p);
}
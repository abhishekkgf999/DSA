#include<iostream>
#include<math.h>
using namespace std;

int getMin(int num[], int size){
    int mini = num[0];
    for(int i=1; i<size; i++){
        mini = min(mini, num[i]);
        // if(num[i]<min){
        //     min = num[i];
        // }
    }
    return mini;
}

int getMax(int num[], int size){
    int maxi = num[0];
    for(int i=1; i<size; i++){
        maxi = max(maxi, num[i]);
        // if(num[i]>max){
        //     max = num[i];
        // }
    }
    return maxi;
}
int main(){
    int size;
    cout<<"Enter size of an array"<<endl;
    cin>>size;

    int num[100];
    cout<<"Enter the elements of an array"<<endl;
    for(int i=0; i<size; i++){
        cin>>num[i];
    }

    cout<<"MAXIMUM VALUE OF GIVEN ARRAY IS:- "<<getMax(num, size)<<endl;
    cout<<"MINIMUM VALUE OF GIVEN ARRAY IS:- "<<getMin(num, size)<<endl;

    return 0;
}
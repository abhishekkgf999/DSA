/*
QUESTION:-

YOU ARE GIVEN A AMOUNT OF RUPEE (LETS SAY 1330)

YOU HAVE TO TELL THAT HOW MANY NOTES REQUIRED OF
 
1. 100 Rs (IN GIVEN EXAMPLE 13 NOTES)  ==> 1330 % 100 = 10  then 1330-1300(100*13) = 30 new amount to check
2. 50 Rs  (IN GIVEN EXAMPLE 0 NOTE)    ==>  30 % 50 = 0 no changes
3. 20 Rs  (IN GIVEN EXAMPLE 1 NOTE)    ==>  30 % 20 = 1 then 30 - 20(20*1) = 10 new amount to check
4. 1 Rs  (IN GIVEN EXAMPLE 10 NOTE)    ==>  10 % 1 = 10 now stops here;

*/




#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the amount of rupees:- "<<endl;
    cin>>n;

    int Rs100, Rs50, Rs20, Rs1;
    switch(100){
        case 100:
                Rs100 = n/100;
                cout<<"Amount of 100 Rs note required is "<<Rs100<<endl;
                n = n - (100*Rs100);
        case 50:
                Rs50 = n/50;
                cout<<"Amount of 50 Rs note required is "<<Rs50<<endl;
                n = n - (50*Rs50);
        case 20:
                Rs20 = n/20;
                cout<<"Amount of 20 Rs note required is "<<Rs20<<endl;
                n = n - (20*Rs20);
        case 1:
                Rs1 = n/1;
                cout<<"Amount of 1 Rs coin required is "<<Rs1<<endl;
                break;
    }
    
    return 0;
}
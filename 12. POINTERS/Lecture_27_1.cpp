//DOUBLE POINTERS

#include<bits/stdc++.h>
using namespace std;

void update(int **p2){
    // p2 = p2 + 1;
    //Kuch change hoga - NO

    // *p2 = *p2 + 1;
    //Kuch change hoga - YES

    **p2 = **p2 + 1;
    //Kuch change hoga - YES
}

int main(){
    
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout<<endl<<endl<<"SAB SAHI CHAL RHA HAI"<<endl<<endl;

    cout<<"Printing p:- "<<p<<endl;
    cout<<"Address of p:- "<<&p<<endl;
    cout<<"Value at address stored in p2 is:- "<<*p2<<endl<<endl;

    cout<<i<<endl;
    cout<<"value at pointer p stored address is:- "<<*p<<endl;
    cout<<"value at pointer p2 sotored address address is:- "<<**p2<<endl<<endl;

    cout<<"Address of variable i is:- "<<&i<<endl;
    cout<<"Adress of variable i is 2nd method:- "<<p<<endl;
    cout<<"Address of variable i is 3rd method:- "<<*p2<<endl<<endl;

    cout<<"Address of pointer p is:- "<<&p<<endl;
    cout<<"Address of pointer p is 2nd method:- "<<p2<<endl;

    cout<<endl<<endl;
    cout<<"Before:- "<<i<<endl;
    cout<<"Before:- "<<p<<endl;
    cout<<"Before:- "<<p2<<endl;
    update(p2);
    cout<<"After:- "<<i<<endl;
    cout<<"After:- "<<p<<endl;
    cout<<"After:- "<<p2<<endl;


    return 0;
}
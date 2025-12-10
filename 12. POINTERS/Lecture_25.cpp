#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 5;

    cout<<num<<endl;

    //ADDRESS OF OPERATOR - &
    cout<<"Address of num is "<<&num<<endl;

    int *ptr = &num;

    cout<<"Address is:- "<<ptr<<endl;
    // "*" DEREFERENCE OPERATOR
    cout<<"Value is:- "<<*ptr<<endl;

    double d = 4.3;
    double *p2 = &d;

    cout<<"Address of double variable is:- "<<p2<<endl;
    cout<<"Value of double variable is:- "<<*p2<<endl;

    //POINTER SIZE ALWAYS REMAIN SAME, BECAUSE IT STORES ONLY ADDRESS, IRRESPECTIVE OF DATA TYPE
    cout<<"Size of integer is:- "<<sizeof(num)<<endl;
    cout<<"Size of pointer is:- "<<sizeof(ptr)<<endl;
    cout<<"Size of double pointer:- "<<sizeof(p2)<<endl;


    //POINTER TO int IS CREATED, AND POINTING TO SOME GARBAGE ADDRESS
    //int *p;   -> THIS IS BAD PRACTICE, DOING THIS, THIS POINTER GONNA POINT TO ANY VALUE IN MEMORY, AND CHANGES TO THIS CAN LEAD TO UNCERTAINITY
    int *p = 0; //-> DO THIS, INSTEAD OF ABOVE
    // cout<<*p<<endl;


    //NULL POINTER AND VALUE ACCESS
    int i = 6;
    int *q = &i;
    cout<<q<<endl;
    cout<<*q<<endl;

    int *r = 0;
    r = &i;
    cout<<r<<endl;
    cout<<*r<<endl;
    
    //CHANGING VALUE THROUGH POINTER
    int *a = &num;
    cout<<"Before:- "<<num<<endl;
    (*a)++;
    cout<<"After:- "<<num<<endl;

    //COPYING A POINTER
    int *b = a;
    cout<<b<<" - "<<a<<endl;
    cout<<*b<<" - "<<*a<<endl;

    //POINTER ARITHMETIC - ADDITION
    int j = 3;
    int *t = &j;
    // cout<< *t++ <<endl;
    *t = *t + 1;
    cout<< *t <<endl;
    cout<<"Before t "<<t<<endl;
    t = t + 1;  //t = t + 1; increments the address stored in t by the size of an integer (usually 4 bytes). Now, t points to the next memory location after j.
    cout<<"After t "<<t<<endl;


    return 0;
}
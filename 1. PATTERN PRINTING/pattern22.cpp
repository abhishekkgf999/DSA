
/*
pattern-22 TYPE:-
         1 2 3 4 5 5 4 3 2 1
         1 2 3 4 * * 4 3 2 1
         1 2 3 * * * * 3 2 1
         1 2 * * * * * * 2 1
         1 * * * * * * * * 1

THIS PROBLEM IS DIVIDED INTO 4 TRIANGLES

TRIANGLE 1:- triangle 1 is of the form
             1 2 3 4 5
             1 2 3 4
             1 2 3
             1 2
             1

        ==>  this can be simply print by printing the number of column upto given number, 
             as you can see that number is increasing according to the given number

TRIANGLE 2:- triangle 2 is of the form
                    *
                  * *
                * * *
              * * * *

        ==>  this is simple pattern, these stars printing from 2nd row, (i-1)
             and filling the empty spaces between them


TRIANGLE 3:- triangle 3 is just similar to triangle 2, no rocket science

TRIANGLE 4:- triangle 4 is just continuing the is row, so these things must ensure to run before
             returning new line

             tringle 4 is just similar to triangle 1, but in reverse order
                   
    
*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=(n-i+1); j++){
            cout<<j<<" ";
        }
        int star_left = i-1;
        while(star_left){
            cout<<"*"<<" ";
            star_left--;
        }
        int star_right = i-1;
        while(star_right){
            cout<<"*"<<" ";
            star_right--;
        }
        for(int k=(n-i+1); k!=0; k--){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}
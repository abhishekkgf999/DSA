
/*
pattern-21 TYPE:-
              1
            1 2 1
          1 2 3 2 1
        1 2 3 4 3 2 1
      1 2 3 4 5 4 3 2 1       

THIS PROBLEM IS DIVIDED INTO 3 TRIANGLES:

TRIANGLE 1: - triangle 1 is made up of spaces, of the pattern (n-i)

TRIANGLE 2: - triangle 2 is 2st half triangle is of the form
                    1
                  1 2
                1 2 3
              1 2 3 4
            1 2 3 4 5

            for this we will use our normal approach as seen in previous pattern

TRIANGLE 3: - triangle 3 is the main triangle due to which our pyramind like structre arise

                1
                2 1
                3 2 1
                4 3 2 1

      ==>   we will set a variable which will start from 2nd row 
      ==>   int start = i-1;
      ==>   then run a condition which will print that number and decrease 
      ==>   while(start){
               cout<<start;
               start--;
            }    
*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        //print 1st triangle
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        //print 2st triangle
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        //print 3rd triangle
        int start = i-1;
        while (start)
        {
            cout<<start;
            start--;
        }
        
        cout<<endl;
    }
    return 0;
}
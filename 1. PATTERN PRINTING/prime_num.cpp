#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number:- "<<endl;
    cin>>n;

    int i = 2;
    while(i<n){ 
        if(n%i ==0){        //  divide hogaya, not prime
            cout<<"Not prime for "<<i<<endl;
        }
        else{
            cout<<"Prime for "<<i<<endl;
        }
        i++;
    }
    return 0;
}   

/*

===> MY CODE FOR PRIME NUMBER

===> & ITS WORKED, but too complex, better solution is there

#include <iostream>
using namespace std;
class pri
{
    public:
    void prime_num(int num1)
    {
        int i = 2;
        bool prime = false;
        while (i < num1)
        {
            if (num1 % i != 0)
            {
                 prime = true;
            }
            if (num1 == 2)
            {
                 prime = true;
            }
            if(num1 %i == 0)
            {
                 prime = false;
                 break;
            }

            i++;
        }
        if(prime == 1){
            cout<<"number is prime number"<<endl;
        }
        else{
            cout<<"number is not prime"<<endl;
        }
    }
};

int main()
{
   pri ob1;
   int n;
   cout<<"enter a number"<<endl;
   cin>>n;
   if(n>1){
   ob1.prime_num(n);
   }
   else{
    cout<<"invalid number, please enter a positive integer"<<endl;
   }

    return 0;
}


*/
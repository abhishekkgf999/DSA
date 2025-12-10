
/*
pattern-20 TYPE:-

    *****
     ****
      ***
       **
        *
*/

//#METHOD-1
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int space = i-1;
        while(space){
            cout<<" ";
            space--;
        }
        for(int j=1; j<=(n-i+1); j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}



/*
pattern-20.1 TYPE:-

    11111
     2222
      333
       44
        5
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int space = i-1;
        while(space){
            cout<<" ";
            space--;
        }
        for(int j=1; j<=(n-i+1); j++){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}

/*
pattern-20.2 TYPE:-

         1
        22
       333
      4444
     55555    
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        for(int j=1; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}

/*
pattern-20.3 TYPE:-

     12345
      2345
       345
        45
         5    
            
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int space = i-1;
        while(space){
            cout<<" ";
            space--;
        }
    for(int j=1; j<=(n-i+1); j++){
        cout<<i+j-1;
    }
    cout<<endl;
    }
    return 0;
}

/*
pattern-20.4 TYPE:-

           1
          23
         456
       78910       
            
*/

#include<iostream>
using namespace std;

int main(){
    int n, count= 1;
    cout<<"enter the number of n ";
    cin>>n;
    for(int i=1; i<=n; i++){
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
    for(int j=1; j<=i; j++){
        cout<<count;
        count++;
    }
    cout<<endl;
    }
    return 0;
}
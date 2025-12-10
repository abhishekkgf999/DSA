//WALKING EXAMPLE FOR RECURSION

#include<iostream>
using namespace std;

void reachHome(int src, int dest){

    //PRINTING WHAT IS HAPPENING BEHIND THE SCENES
    cout<<"Source:- "<<src<<" & Destination:- "<<dest<<endl;

    //BASE CASE
    if(src == dest){
        cout<<"Phauch gya!!"<<endl;
        return;
    }

    //PROCESSING
    src++;  //INCREASING THE STEP 

    //RECURSIVE CALL
    return reachHome(src, dest);
}

int main(){
    int src = 1, dest = 10;

    reachHome(src, dest);

    return 0;
}
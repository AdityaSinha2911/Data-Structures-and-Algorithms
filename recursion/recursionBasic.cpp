#include <iostream>
using namespace std;

int count =10;

void name5time(){
    cout<<count<<endl;
    count--;
    

    if(count==0){
        return;
    }
    name5time();
}

int sum(int n){
    if(n==0){
        return 0;
    }
    return n + sum(n-1);
}


int main(){
    int n=3;
    cout<<sum(n);
    return 0;
}
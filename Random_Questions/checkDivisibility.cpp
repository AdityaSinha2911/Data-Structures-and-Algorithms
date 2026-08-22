#include <iostream>
using namespace std;

bool checkDivisibility(int n) {
    int sum = 0;
    int product = 1;

    int y = n;

    while(n > 0) {
        int x = n % 10;
        n = n / 10;

        sum += x;
        product *= x;
    }

    int x = sum + product;

    return y % x == 0;
}

int main(){
    int n;
    cin>>n;

    if(checkDivisibility(n)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
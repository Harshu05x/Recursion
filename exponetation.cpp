#include <iostream>
using namespace std;

int expo(int n, int x){
    // Base case
    if(x == 0) return 1;
    return expo(n,x-1)*n;
}            

int main()
{
    int x = 4;
    int n = 3;
    cout<<expo(n,x)<<endl;
    return 0;
}
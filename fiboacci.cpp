#include <iostream>
using namespace std;

int fibo(int n){
    // Base Case
    if(n == 0 || n == 1)
       return n;

    return fibo(n-1)+fibo(n-2);  
}
int main()
{
    int n = 15;
    int i = 0;
    while(i <= n){
        cout<<fibo(i++)<<" ";
    }
    return 0;
}
#include <iostream>
using namespace std;

int facto(int n){
    // Base case
    if(n == 1) return 1;
    return n * facto(n-1);
}

int main()
{
    int n = 11;
    cout<<facto(n); 
    return 0;
}
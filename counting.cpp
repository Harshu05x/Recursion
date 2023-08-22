#include <iostream>
using namespace std;

// Reverse Counting
void reverse_count(int n){
    // Base case
    if(n == 1){
        cout<<1<<" ";
        return ;
    }
    cout<<n<<" ";
    reverse_count(n-1);
}
// Normal Counting
void normal_counting(int n){
    // Base case
    if(n == 1){
        cout<<1<<" ";
        return ;
    }
    normal_counting(n-1);
    cout<<n<<" ";
}

int main()
{
    int n = 25;
    normal_counting(n);
    cout<<endl;
    reverse_count(n);
    return 0;
}
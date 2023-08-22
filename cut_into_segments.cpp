#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int x, int y, int z){
    if(n == 0)
        return 0;
    
    if(n < 0)
        return INT32_MIN;

    int a = solve(n-x,x,y,z)+1;
    
    int b = solve(n-y,x,y,z)+1;
    
    int c = solve(n-z,x,y,z)+1;

    int ans = max(a,max(b,c));

    return ans;
}

int main()
{
    int n = 7;
    int x = 5, y = 2, z = 2;
    int ans = solve(n,x,y,z);

    if(ans < 0)
        ans = 0;
    cout<<ans<<endl;
    return 0;
}
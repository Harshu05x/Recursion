#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& arr, int target){
    if(target == 0)
        return 0;
    if(target < 0)
        return INT32_MAX;
    
    int mini = INT32_MAX;
    for(int i = 0; i < arr.size(); i++){
        int ans = solve(arr,target-arr[i]);
        if(ans != INT32_MAX)
            mini = min(ans+1,mini);
    }
    return mini;
}
int main()
{
    vector<int> arr = {1,2,5};
    int target = 8;
    cout<<solve(arr,target);
    return 0;
}
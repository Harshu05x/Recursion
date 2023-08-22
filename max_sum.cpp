// Include - Exclude pattern
// 198 - leetcode House Robber problem
#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(2^n)        S.C. = O(n)
void solve(vector<int>& arr, int i, int sum, int& maxi){
    if(i >= arr.size()){
        maxi = max(maxi,sum);
        return ;
    }
    // include case
    solve(arr,i+2,sum+arr[i],maxi);

    // exclude case
    solve(arr,i+1,sum,maxi);

}

int main()
{
    vector<int> arr{1,2,3,1,3,5,8,1,9};
    int i = 0, maxi = INT32_MIN, sum = 0;
    solve(arr,i,sum,maxi);
    cout<<maxi<<endl;
    return 0;
}
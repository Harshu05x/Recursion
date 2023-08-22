// 121 - leetcode
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Iterative Apporach T.C. = O(n)
    int maxProfit(vector<int>& arr) {
        int profit = 0;
        int buy = INT32_MAX;

        for(int i = 0; i < arr.size(); i++){
            buy = min(buy,arr[i]);
            profit = max(profit,arr[i]-buy);
        }
        return profit;

}

// Recursive apporach       T.C. = S.C. = O(n)
void find_profit(vector<int>& arr, int i, int& minPrice, int& maxprofit){
    if(i == arr.size())
        return;

    minPrice = min(minPrice,arr[i]);
    maxprofit = max(arr[i]-minPrice,maxprofit);
    find_profit(arr,i+1,minPrice,maxprofit);
}
int maxProfit_01(vector<int>& arr) {
    int minPrice = INT32_MAX;
    int maxprofit = INT32_MIN;
    find_profit(arr,0,minPrice,maxprofit);
    return maxprofit;
}

int main()
{
    vector<int> arr{7,1,5,3,6,4};
    cout<<maxProfit(arr)<<endl;
    cout<<maxProfit_01(arr)<<endl;
    return 0;
}
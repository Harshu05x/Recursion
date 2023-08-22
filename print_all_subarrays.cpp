#include <iostream>
#include <vector>
using namespace std;

void print_interval(vector<int>& arr, int i, int j){
    while(i <= j)
        cout<<arr[i++];
    cout<<endl;
}

// T.C. = O(n^2)  S.C. = O(n)
void print(vector<int>& arr, int i, int j){
    if(i >= arr.size())
        return ;
    if(j >= arr.size())
        return ;
    // int x = i;
    // while(x <= j)
    //     cout<<arr[x++];
    // cout<<endl;
    print_interval(arr,i,j);
    print(arr,i,j+1);
    if(i == j)
        print(arr,i+1,j+1);
}


int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,0,0);
    return 0;
}
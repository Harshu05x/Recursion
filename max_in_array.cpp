#include <iostream>
using namespace std;


int maximum(int arr[],int n){
    if(n == 1)
        return arr[0];
    return max(arr[n-1],maximum(arr,n-1));
}

int minimum(int arr[],int n){
    if(n == 1)
        return arr[0];
    return min(arr[n-1],minimum(arr,n-1));
}

int maximum(int arr[], int n,int& maxi){
    if(n == 0){
        return max(maxi,arr[0]);
    }
    maxi = max(maxi,arr[0]);
    return maximum(arr+1,n-1,maxi);
}

int minimum(int arr[],int n,int& mini){
    if(n == 0)
        return min(mini,arr[0]);
    
    mini = min(arr[0],mini);
    return minimum(arr+1,n-1,mini);
}
int main()
{
    int arr[] = {4,1,44,21,78,91,34,123,11,23,41,97,92,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxi = INT32_MIN, mini = INT32_MAX;
    cout<<"Max num: "<<maximum(arr,n);
    cout<<"\nMax num: "<<maximum(arr,n,maxi);
    cout<<"\nMin num: "<<minimum(arr,n);
    cout<<"\nMin num: "<<minimum(arr,n,mini);
    return 0;
}
#include <iostream>
using namespace std;

// without index passing
bool is_sorted(int arr[],int n){
    if(n == 1)
        return true;
    if(arr[1] < arr[0])
        return false;
    return is_sorted(arr+1,n-1);
}

bool is_sorted(int arr[], int& n, int i){
    if(i == n-1)
        return true;
    if(arr[i] > arr[i+1])
        return false;
    return is_sorted(arr,n,i+1);
}

int main()
{
    int arr[] = {10,20,30,40,50,22,60,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    is_sorted(arr,n) ? cout<<"Array is sorted"<<endl : cout<<"Array is not sorted"<<endl;
    is_sorted(arr,n,0) ? cout<<"Array is sorted"<<endl : cout<<"Array is not sorted"<<endl;
    return 0;
}
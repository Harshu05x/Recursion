#include <iostream>
using namespace std;

int binary_search(int arr[], int& key, int l, int h){
    if(l > h)
        return -1;
    int mid = (l+h)/2;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binary_search(arr,key,l,mid-1);
    else
        return binary_search(arr,key,mid+1,h);

}                   
int main()
{
    int arr[] = {10,20,30,40,50,60,90,111}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 50;

    int ans = binary_search(arr,key,0,n-1);

    ans == -1 ? cout<<"Key not found"<<endl : cout<<"Key found at "<<ans<<endl;
    return 0;
}
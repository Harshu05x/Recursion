#include <iostream>
using namespace std;


// Normal printing
void normal_print(int arr[],int n){
    if(n == 0){
        return ;
    } 
    normal_print(arr,n-1);
    cout<<arr[n-1]<<" ";
}
// Reverse printing
void rev_print(int arr[],int n){
    if(n == 0){
        return ;
    } 
    cout<<arr[n-1]<<" ";
    rev_print(arr,n-1);
}
// Another apporach
void print_01(int arr[],int n){
    if(n == 0)
        return;
    cout<<arr[0]<<" ";
    print_01(arr+1,n-1);
}
// Normal printing using index
void index_printing(int arr[], int n, int i){
    if(i >= n)
        return ;
    cout<<arr[i]<<" ";
    index_printing(arr,n,i+1);
}
// reverse printing using index
void index_printing_01(int arr[], int n, int i){
    if(i >= n)
        return ;
    index_printing_01(arr,n,i+1);
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    cout<<"Normal printing --> ";
    normal_print(arr,n); 
    cout<<endl;
    cout<<"Reverse printing --> ";
    rev_print(arr,n);
    cout<<endl;
    cout<<"Using arr addressing --> ";
    print_01(arr,n);
    cout<<endl;
    cout<<"Using index Normal printing --> ";
    index_printing(arr,n,i);
    cout<<endl;
    cout<<"Using index reverse printing --> ";
    index_printing_01(arr,n,i);
    return 0;
}
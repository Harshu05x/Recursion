#include <iostream>
#include <vector>
using namespace std;


void merge(int arr[], int& s, int& e, int& mid){
    // Dynamically allocate the memory 
    int* temp = new int[100];       // dynamic array

    int i = s, j = mid+1, k = s;
    while(i <= mid && j <= e){
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
        }
    }    
    while(i <= mid ) temp[k++] = arr[i++];
    while(j <= e ) temp[k++] = arr[j++];

    // copy all ele in arr from temp
    for(int i = s; i <= e; i++) {
        arr[i] = temp[i];
    }
    // delete the dynamically allocated memory
    delete []temp;
}

// T.C. = O(nlogn) 
void merge_sort(int arr[], int s, int e){
    // 1] base case
    if(s >= e)                                                      //T.C. = O(k)
        return ;
    // find mid and break it in 2 halves
    int mid = (s+e)/2;
    // 2] Left part sort krun ye        (RE will sort it)           // T.C. = O(n/2)
    merge_sort(arr,s,mid);
    // 3] Right part sort krun ye       (RE will sort it)           // T.C. = O(n/2)
    merge_sort(arr,mid+1,e);
    // 4] Left and Right merge krr     (merge func will merge it)   // T.C. = O(n*k)
    merge(arr,s,e,mid);
                                                              // total T.C. = O(1) + T(n/2) + T(n/2) + T(n*k)
                                                              //            = O(nlogn)
}
                   
int main()
{
    int arr[] = {100,2,5,8,16,3,6,7,10,2,1,2,2,2,2,1};
    int s = 0, e = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,s,e-1); 
    for(int i = 0; i < e; i++)
        cout<<arr[i]<<" ";

    return 0;
}
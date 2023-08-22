#include <iostream>
using namespace std;

// Quick Sort = partitioning logic + Recursion logic
// T.C. = O(nlogn) for best and avg cases & O(n^2) for worst case

// partitioning logic
int partition(int arr[], int s, int e){
    // 1] Choose pivot ele
    int pivot = s;
    int i = s+1;
    int j = e;

    // 2] Find a correct pos for pivot ele
    do {
        while(arr[i] <= arr[pivot]) i++;    // i++ untill you'll get ele greater than pivot ele
        while(arr[j] > arr[pivot]) j--;     // j-- untill you'll get ele less than or equal to pivot ele
        // left la sagle chote and right la sagle mote ele havet mhnun swap krych
        if(i < j) swap(arr[i],arr[j]);    // if i < j swap i'th ans j'th ele
    }while(i < j);
    // 3] put pivot at its right pos
    swap(arr[pivot],arr[j]);
    // 4] return j as a index of pivot which will acts as partitioning index
    //      becoz after swapping pivot ele will be palced at j so... 
    return j;
}

// Recursion logic
void quick_sort(int arr[], int s, int e){
    // 1] Base case
    if( s >= e)
        return;
    // 2] divide array in two halves
    int j = partition(arr,s,e);
    // 3] left RE call
    quick_sort(arr,s,j-1);
    // 4] Right RE call
    quick_sort(arr,j+1,e);
}

int main()
{
    int arr[] = {100,2,5,8,16,3,6,7,10,2,1,2,2,2,2,1};
    int s = 0, e = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,s,e-1); 
    for(int i = 0; i < e; i++)
        cout<<arr[i]<<" ";
    return 0;
}
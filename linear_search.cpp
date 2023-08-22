#include <iostream>
#include <vector>
using namespace std;


bool linear_search(int arr[],int key,int n){
    n--;
    if(n < 0) return false;
    if(arr[n] == key) return true;
    return linear_search(arr,key,n);
}
// return index
int linear_search_01(int arr[],int key,int n){
    n--;
    if(n < 0) return -1;
    if(arr[n] == key) return n;
    return linear_search(arr,key,n);
}

int linear_search_02(string& str,int& n, int i, char& key){
    if(i >= n) return -1;
    if(str[i] == key) return i;
    return linear_search_02(str,n,i+1,key);
}
void linear_search_03(string& str,int& n, int i, char& key){
    if(i >= n) return ;
    if(str[i] == key) cout<<"Found at "<<i<<endl;
    linear_search_03(str,n,i+1,key);
}
void linear_search_03(string& str,int& n, int i, char& key, vector<int>& ans){
    if(i >= n) return ;
    if(str[i] == key) ans.push_back(i);
    linear_search_03(str,n,i+1,key,ans);
}
int main()
{
    // int arr[] = {4,1,44,21,78,91,34,11,23,41,97,123,92,121};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int key = 111;
    // linear_search(arr,key,n) == true ? cout<<"Found\n" : cout<<"Not Found\n";
    // linear_search_01(arr,key,n) != -1 ? cout<<"Found at: "<<linear_search_01(arr,key,n): cout<<"Not found";

    string str = "Aishu and Harshu";
    char key = 'h';
    int n = str.length();
    cout<<linear_search_02(str,n,0,key)<<endl;
    linear_search_03(str,n,0,key);
    vector<int> ans;
    linear_search_03(str,n,0,key,ans);
    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}
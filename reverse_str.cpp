#include <iostream>
#include <string>
using namespace std;

void reverse(string& str, int n, string& output){
    if(n == 0)
        return;
    output.push_back(str[n-1]);
    // cout<<str[i];  we can print also
    reverse(str,n-1,output);
}

// using two pointer appoarch
void reverse(string& str, int i, int j){
    if(i >= j)
        return ;
    swap(str[i],str[j]);
    reverse(str,i+1,j-1);
}

int main()
{
    string str = "abcddefgde";
    string output = "";
    reverse(str,str.size(), output); 
    reverse(str,0,str.size()-1);
    cout<<output<<endl;
    cout<<str<<endl;
    return 0;
}
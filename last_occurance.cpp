#include <iostream>
#include <cstring>
using namespace std;

// Iterative apporach
int last_occur(string str, char ch){
    // Reverse traversing
    int i = str.length()-1;
    while(i >= 0){
        if(str[i] == ch)
            return i;
        i--;
    }
    return -1;

    // // Normal traversing
    // int i = 0;
    // int ans = -1;
    // while(i < str.length()){
    //     if(str[i] == ch)
    //         ans = i;
    //      i++;
    // }
    // return ans;
}

// Recursive apporach ( right to left traversal)
int last_occurr(string& str, int n, char& ch){
    if(n == 0)
        return -1;
    if(str[n-1] == ch)
        return n-1;
    return last_occurr(str,n-1,ch);
}

// Recursive apporach ( left to right traversal)
void last_occur01(string& str, int i, char& ch, int& ans){
    if(i >= str.size())
        return ;
    if(str[i] == ch)
        ans = i;
    last_occur01(str,i+1,ch,ans);
}

int main()
{
    string str = "abcddefgde";
    char ch = 'd';
    cout<<str.length()<<endl;
    cout<<last_occurr(str,str.length(),ch)<<endl; 
    int ans = -1;
    last_occur01(str,0,ch,ans);
    cout<<ans<<endl;
    return 0;
}
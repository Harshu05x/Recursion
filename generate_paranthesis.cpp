// 22 - leetcode
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Include exclude pattern
void solve(vector<string>& ans, int& n, int open, int close, string& output){
    // base case  (both open and close brackets are finished)
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }

    // include open bracket
    if(open > 0){
        output.push_back('(');
        // RE call
        solve(ans,n,open-1,close,output);
        // backtrack
        output.pop_back();
    }

    // include close brackets
    if(close > open){
        output.push_back(')');
        // RE call
        solve(ans,n,open,close-1,output);
        // backtrack
        output.pop_back();
    }

}
vector<string> generateParenthesis(int& n) {
    vector<string> ans;
    string output = "";
    int open = n;
    int close = n;
    solve(ans,n,open,close,output);
    return ans;       
}
                
int main()
{
    int n = 3;
    vector<string> ans;
    ans = generateParenthesis(n);
    cout<<"All possible valid paranthesis-->"<<endl;
    int i = 1;
    for(auto str : ans)
        cout<<i++<<": "<<str<<endl;
    return 0;
}
// 1 - 1
// 2 - 2
// 3 - 5
// 4 - 14
// 5 - 42
// 6 - 132
// 7 - 429
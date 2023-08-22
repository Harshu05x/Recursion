// 17 - leetcode
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map <int,string> mp = {   {2,"abc"}, {3,"def"}, {4,"ghi"},
                                    {5,"jkl"}, {6,"mno"}, {7,"pqrs"},
                                    {8,"tuv"}, {9,"wxyz"}
                                };

void solve(string& digits, int i, vector<string>& ans, string& output){
    // base case  (if index is out of bound)
    if(i >= digits.size()){
        ans.push_back(output);
        return ;
    }
    // find current  for map
    int index = digits[i] - '0';
    string str = mp[index];
    // traverse all char of string at index in map
    for(int x = 0; x < str.size(); x++){
        // add current char
        output.push_back(str[x]);
        // RE call
        solve(digits,i+1,ans,output);
        // backtrack
        output.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.size() == 0) return ans;
    int i = 0;
    string output = "";
    solve(digits,i,ans,output);
    return ans;
}
                   
int main()
{
    string str = "29";

    vector<string> ans = letterCombinations(str);
    for(auto x : ans) cout<<x<<endl;
    return 0;
}
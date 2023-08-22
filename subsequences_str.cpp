// Include - Exclude pattern
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subseq_str(string& str, int i, string out_Str){
    if(i == str.size()){
        cout<<out_Str<<endl;
        return ;
    }
    // exclude case
    subseq_str(str,i+1,out_Str);
    // include case
    out_Str.push_back(str[i]);
    subseq_str(str,i+1,out_Str);
}
                   
void subseq_str_01(string& str, int i, string out_Str){
    if(i == str.size()){
        cout<<out_Str<<endl;
        return ;
    }
    // include case
    out_Str.push_back(str[i]);
    subseq_str(str,i+1,out_Str);
    // exclude case
    out_Str.pop_back();
    subseq_str(str,i+1,out_Str);
}
                   
void subseq_str(string& str, int i, string out_Str, vector<string>& v){
    if(i == str.size()){
        // store
        v.push_back(out_Str);
        return ;
    }
    // exclude case
    subseq_str(str,i+1,out_Str,v);
    // include case
    out_Str.push_back(str[i]);
    subseq_str(str,i+1,out_Str,v);
}

int main()
{
    string str = "abcd";
    string out_Str = "";
    vector<string> ans;

    subseq_str(str,0,out_Str,ans);

    for(auto str : ans)
        cout<<str<<" ";
    cout<<"\nSize: "<<ans.size()<<endl;

    return 0;
}
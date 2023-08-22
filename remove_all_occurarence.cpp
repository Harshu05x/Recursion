// 1910 - leetcode
#include <iostream>
#include <string>
using namespace std;

// n = s.size() , m = part.size()
// total calls = O(n/m)
// T.C. = O(nm) for 1 call 
// hence for (n/m) calls -
// T.C. = will be O(n^2) and S.C. = 0(n/m)
void remove(string& s, string& part){
    int pos = s.find(part);             // find fun T.C. = O(nm)
                                
    if(pos != string::npos){
        string left = s.substr(0,pos);  // substr fun T.C. = O(n)
        string right = s.substr(pos+part.size(),s.size());
        s = left + right;               // T.C. = O(1)
        remove(s,part);
    }
    else
        return ;
}
                   
int main()
{
    string s = "daabcbaabcbc", part = "abc";
    remove(s,part);
    cout<<s<<endl;
    return 0;
}
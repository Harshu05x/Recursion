#include <iostream>
using namespace std;

// T.C. = O(n!) 
void printPermutations(string& str, int i,int& n){
    // 1] Base case
    if(i >= str.length()){
        n++;
        cout<<n<<": "<<str<<endl;
        return;
    }

    // 2] Swapping
    for(int j = i; j < str.length(); j++){
        // a] swap
        swap(str[i],str[j]);
        // b] Recursive call
        printPermutations(str,i+1,n);
        // c] backtracking by reswapping (it recreate orignal string)
        swap(str[i],str[j]);
    }
}

int main()
{
    string str = "abcd";
    int n = 0;
    printPermutations(str,0,n);
    return 0;
}
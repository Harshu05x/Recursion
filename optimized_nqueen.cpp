// 51 - leetcode
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
    
// create a unordered map for each direction
unordered_map<int,bool> rowcheck;       // for row
unordered_map<int,bool> upperLDcheck;   // for upper left diagonal
unordered_map<int,bool> bottomLDcheck;  // for botton left diagonal

void printSolution(vector<vector<string>>& str, int& n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<str[i][j]<<" ";
        }
        cout<<endl;
    }  
    cout<<endl;
}

// T.C. = O(n^2)
void storeSolution(vector<vector<char>>& board, int& n, vector<vector<string>>& ans){
    vector<string> temp;
    for(int i = 0; i < n; i++){
        string output = "";
        for(int j = 0; j < n; j++){
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp); 
}

// T.C = O(1)
bool isSafe(vector<vector<char>>& board,int row, int col, int& n){
    int i = row;
    int j = col;

    if( (rowcheck[row] == true) || 
        (upperLDcheck[col-row] == true) || 
        (bottomLDcheck[row+col] == true))
            return false;
    return true;
}

void solve(vector<vector<char>>& board, int col, int& n,vector<vector<string>>& ans){
    // Base case
    if(col >= n){
        storeSolution(board,n,ans);
        return;
    }
    
    // place queen in every row
    for(int row = 0; row < n; row++){
        // check the current possition is safe or not
        if(isSafe(board,row,col,n)){
            // if safe then mark current pos as placed
            board[row][col] = 'Q';
            // change map entries
            rowcheck[row] = true;
            upperLDcheck[col-row] = true;
            bottomLDcheck[row+col] = true;
            // RE call
            solve(board,col+1,n,ans);
            // Backtrack and mark current pos as not placed 
            board[row][col] = '.';
            // change map entries for backtracking purpose
            rowcheck[row] = false;
            upperLDcheck[col-row] = false;
            bottomLDcheck[row+col] = false;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>> arr(n,vector<char>(n,'.')); 
    vector<vector<string>> ans;
    solve(arr,0,n,ans);
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<string>> str = solveNQueens(n);
    printSolution(str,n);
    return 0;
}  
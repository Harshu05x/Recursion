#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n^2)
void printSolution(vector<vector<int>>& board, int& n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] == 1 ? cout<<"Q " : cout<<"- ";
        }
        cout<<endl;
    }  
    cout<<endl;
}

// T.C = O(n)
bool isSafe(vector<vector<int>>& board,int row, int col, int& n){
    int i = row;
    int j = col;

    // 1] check row
    while(j >= 0){
        if(board[i][j] == 1)
            return false;
        j--;
    }

    i = row; j = col;
    // 2] check upper left diagonal
    while(i >= 0 && j >= 0){
        if(board[i][j] == 1)
            return false;
        i--; j--;
    }

    i = row; j = col;
    // 3] check bottom left diagonal
    while(j >= 0 && i < n){
        if(board[i][j] == 1)
            return false;
        i++; j--;
    }

    return true;
}

void solve(vector<vector<int>>& board, int col, int& n){
    // Base case  ( you placed all queens in their proper places )
    if(col >= n){
        printSolution(board,n);
        return;
    }
    
    // place queen in every row
    for(int row = 0; row < n; row++){
        // check the current possition is safe or not
        if(isSafe(board,row,col,n)){
            // if safe then mark current pos as placed
            board[row][col] = 1;
            // RE call
            solve(board,col+1,n);
            // Backtrack and mark current pos as not placed 
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n = 6;
    vector<vector<int>> arr(n,vector<int>(n,0)); 
    solve(arr,0,n);
    return 0;
}
// n = no of solution exits
// 4 = 2
// 5 = 10
// 6 = 4
// 7 = 40
// 8 = 92
// 9 = 352
// 10 = 724
// 11 = 2680
// 12 = 14200
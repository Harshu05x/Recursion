#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int val, int board[][9], int i, int j){
    // row check
    for(int col = 0; col < 9; col++){
        if(board[i][col] == val)
            return false;
    }

    // col check
    for(int row = 0; row < 9; row++){
        if(board[row][j] == val)
            return false;
    }

    // 3x3 box check
    for(int x = 0; x < 9; x++){
        if(board[3*(i/3)+(x/3)][3*(j/3)+(x%3)] == val)
            return false;
    }
    // 3*(i/3) it gives us the starting roe of all boxes
    // (x/3) gives us movement for row
    // 3*(j/3) it gives us the starting col of all boxes
    // (x%3) gives us movement for col

    return true;

}

bool solve(int board[][9], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // check the current cell is empty or not
            if(board[i][j] == 0){
                // try to insert values from 1 to 9
                for(int val = 1; val <= 9; val++){
                    // check the current val is safe fpr current cell or not
                    if(isSafe(val,board,i,j)){
                        // insert val
                        board[i][j] = val;
                        // RE call
                        int next_sol = solve(board,n);
                        if(next_sol == true)
                            return true;
                        // backtrack
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;

}
                   
int main()
{
    int board[9][9] = { {4,5,0,0,0,0,0,0,0},
                        {0,0,2,0,7,0,6,3,0},
                        {0,0,0,0,0,0,0,2,8},
                        {0,0,0,9,5,0,0,0,0},
                        {0,8,6,0,0,0,2,0,0},
                        {0,2,0,6,0,0,7,5,0},
                        {0,0,0,0,0,0,4,7,6},
                        {0,7,0,0,4,5,0,0,0},
                        {0,0,8,0,0,9,0,0,0} }; 

    int n = 9;
    solve(board,n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
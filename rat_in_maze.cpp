#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char dir[] = {'D','L','R','U'};

bool isSafe(int i, int j, int row, int col, int arr[][3], vector<vector<bool>>& visited){
    if(((i >= 0 && i < row) && (j >= 0 && j < col)) &&  
        (arr[i][j] == 1) && 
            (visited[i][j] == false)){
            return true;
    }
    return false;
}

void solveMaze(int arr[][3], int& row, int& col, int i, int j,
                vector<vector<bool>>& visited, vector<string>& path, string output){

    // 1] Base case     ( you are reached at destination )
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return ;
    }

    for(int x = 0; x < 4; x++){
        int new_i = i + dx[x];
        int new_j = j + dy[x];
        char ch = dir[x]; 
        if(isSafe(new_i,new_j,row,col,arr,visited)){
            visited[i][j] = true;
            // RE call
            solveMaze(arr,row,col,new_i,new_j,visited,path,output+dir[x]);
            // Backtrack
            visited[new_i][new_j] = false;
        }
    }

    // // Down -> i+1 , j
    // if(isSafe(i+1,j,row,col,arr,visited)){
    //     visited[i+1][j] = true;
    //     // RE call
    //     solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
    //     // backtrack and mark false 
    //     visited[i+1][j] = false;
    // }
    // // Left -> i , j-1
    // if(isSafe(i,j-1,row,col,arr,visited)){
    //     visited[i][j-1] = true;
    //     // RE call
    //     solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
    //     // backtrack and mark false 
    //     visited[i][j-1] = false;
    // }
    // // Right -> i , j+1
    // if(isSafe(i,j+1,row,col,arr,visited)){
    //     visited[i][j+1] = true;
    //     // RE call
    //     solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
    //     // backtrack and mark false
    //     visited[i][j+1] = false;
    // }
    // // Up -> i-1 , j
    // if(isSafe(i-1,j,row,col,arr,visited)){
    //     visited[i-1][j] = true;
    //     // RE call
    //     solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
    //     // backtrack and mark false 
    //     visited[i-1][j] = false;
    // }

}                   
int main()
{

    int arr[3][3] = {{1,1,1},
                     {1,1,1},
                     {0,0,1}}; 


    vector<vector<int>> maze {{1, 1, 1, 1},
                                {0, 0, 0, 1}, 
                                {0, 0, 0, 1},
                                {1, 1, 1, 1}};


    // int arr[4][4] = { {1,0,0,0}, 
    //              {1,1,0, 1},
    //              {1,1,0,0},
    //              {0,1,1,1}};

    if(arr[0][0] == 0){
        cout<<"No path exits"<<endl;
        return 0;
    }

    int rows = 3, cols = 3;
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    // Make sure that source pos it true marked
    visited[0][0] = true;

    vector<string> path;
    string output = "";

    solveMaze(arr,rows,cols,0,0,visited,path,output);
    cout<<"Printing the result-->"<<endl;
    for(auto str : path)
        cout<<str<<endl;
    if(path.size() == 0)
        cout<<"No path exits"<<endl;
    return 0;
}

// Dscription -->
// i] visited array - its a 2D boolen array stores true if palce is visited 
//                      and stores false if palce is not visited
// ii] path aaray - its a string type array stores all possible paths

// Procedure -->
// 1] if you are reacheda at end then store the ans and return  - base case
// 2] make 4 RE calls in D L R U direction                      - use for loop 0 to 4
//     i] check pos next move is safe or not by isSafe func 
//         a] mark i,j of visited array as true
//         b] make RE call for current i,j                      - recursive calls 
//         c] mark i,j of visited array as false                - backtracking line

// * isSafe func - 
//     if (i and j are in bound) and 
//             (i,j of maze is valid means == 1) and 
//                 (i,j of visited array is false) return true otherwise false;
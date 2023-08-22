// GFG - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};
char dir[] = {'D','L','R','U'};

bool isSafe(int i, int j, int row, int col, vector<vector<int>>& arr, vector<vector<bool>>& visited){
    if(((i >= 0 && i < row) && (j >= 0 && j < col)) &&  
        (arr[i][j] == 1) && 
            (visited[i][j] == false)){
            return true;
    }
    return false;
}

void solveMaze(vector<vector<int>>& arr, int& row, int& col, int i, int j,
                vector<vector<bool>>& visited, vector<string>& path, string output){

    // 1] Base case
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return ;
    }

    for(int x = 0; x < 4; x++){
        if(isSafe(i+dx[x],j+dy[x],row,col,arr,visited)){
            visited[i+dx[x]][j+dy[x]] = true;
            // RE call
            solveMaze(arr,row,col,i+dx[x],j+dy[x],visited,path,output+dir[x]);
            // Backtrack
            visited[i+dx[x]][j+dy[x]] = false;
        }
    }

}
vector<string> findPath(vector<vector<int>> &m, int n) {
    
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    visited[0][0] = true;
    vector<string> path;
    string output = "";
    solveMaze(m,n,n,0,0,visited,path,output);
    if(path.size() == 0) path.push_back("-1");
    return path;
}                
int main()
{
       vector<vector<int>> maze {{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    int cols = 4;
    vector<string> paths = findPath(maze,cols);
    for(auto str : paths)
            cout<<str<<" ";
    return 0;
}
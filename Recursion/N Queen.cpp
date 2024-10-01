#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& arr, int x, int y, int n){
    // for all rows till x
    for(int row = 0; row < x; row++){
        if(arr[row][y] == 1)
            return false;
    }
    
    int row = x;
    int col = y;
    
    // for left diagonal
    while(row >= 0 && col >= 0){
        if(arr[row][col] == 1)
            return false;
            
        row--;
        col--;
    }
    
    row = x;
    col = y;
    // for right diagonal
    while(row >= 0 && col < n){
        if(arr[row][col] == 1)
            return false;
            
        row--;
        col++;
    }
    return true;
}

bool nQueen(vector<vector<int>>& arr, int n, int x = 0){
    if(x >= n)
        return true;
        
    for(int col = 0; col < n; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col] = 1;
            
            if(nQueen(arr, n, x+1))
                return true;
            
            arr[x][col] = 0; // backtracking
        }
    }
    return false;
}

int main(){
    int n = 12;
    vector<vector<int>> arr(n, vector<int>(n));
    
    
    if(nQueen(arr, n)){
        for(int i = 0; i< n; i++){
            for(int j =0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}

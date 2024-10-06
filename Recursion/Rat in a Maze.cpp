bool isSafe(vector<vector<int>>&  mat, int x, int y, vector<vector<bool>>& visited){
        int n = mat.size();
        if(x >=0 && x < n && y>=0 && y < n && mat[x][y] == 1 && visited[x][y] == 0)
            return true;
            
        return false;
    }
  
    void solve(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited, vector<string>& res, string path){
        int n = mat.size();
        
        if(x == n-1 && y == n-1){
            res.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // Down
        if(isSafe(mat, x+1, y, visited))
            solve(x+1, y, mat, visited, res, path + 'D');
            
        // Right
        if(isSafe(mat, x, y+1, visited))
            solve(x, y+1, mat, visited, res, path + 'R');
        
        // Up
        if(isSafe(mat, x-1, y, visited))
            solve(x-1, y, mat, visited, res, path + 'U');
            
        // Left
        if(isSafe(mat, x, y-1, visited))
            solve(x, y-1, mat, visited, res, path + 'L');
            
        visited[x][y] = 0;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        
        vector<string> res;
        string path;
        
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0)
            return res;
            
        vector<vector<bool>> visited(n, vector<bool>(n));
        solve(0, 0, mat, visited, res, path);
        return res;
    }

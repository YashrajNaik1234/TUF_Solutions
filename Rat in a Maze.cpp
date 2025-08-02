class Solution{
    public:
    bool isSafe(int i, int j, int n, vector<vector<bool>> vis, vector<vector<int>>& maze){
        
        if((i >= 0 and  i < n) and (j >= 0 and j < n) and vis[i][j] == 0 and maze[i][j] == 1){
            return true;
        }
        
        return false;
    }
    
    void solve(vector<vector<int>>& maze,vector<string>& ans, int i, int j, int n,
            vector<vector<bool>> vis, string k){
        if(i == n - 1 and j == n - 1){
            ans.push_back(k); return;
        }
        
        vis[i][j] = 1;
        
        //down
        if(isSafe(i + 1, j, n, vis, maze)){
            k += "D";
            solve(maze, ans, i + 1, j, n, vis, k);
            k.pop_back();
        }
        
        //left
        if(isSafe(i, j - 1, n, vis, maze)){
            k += "L";
            solve(maze, ans, i, j - 1, n, vis, k);
            k.pop_back();
        }
        
        //right
        if(isSafe(i, j + 1, n, vis, maze)){
            k += "R";
            solve(maze, ans, i, j + 1, n, vis, k);
            k.pop_back();
        }
        
        //up
        if(isSafe(i - 1, j, n, vis, maze)){
            k += "U";
            solve(maze, ans, i - 1, j, n, vis, k);
            k.pop_back();
        }
        
        vis[i][j] = 0;
        
    }
    vector<string> findPath(vector<vector<int> > &maze) {
        //your code goes here
        vector<string> ans;
        
        if(maze[0][0] == 0) return ans;
        
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze.size(),false));
        solve(maze, ans, 0, 0, maze.size(), vis, "");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

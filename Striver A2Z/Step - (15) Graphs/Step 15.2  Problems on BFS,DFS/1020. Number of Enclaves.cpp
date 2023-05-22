// https://leetcode.com/problems/number-of-enclaves/

class Solution {
    void dfs(vector<vector<int>> & grid, int i, int j, vector<vector<bool>> & visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]){
            return;
        }
        visited[i][j] = true;
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));    
        // for column
        for(int i =0;i<n;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(grid, i, 0, visited);
            }
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(grid, i, m-1, visited);
            }
        }
        // for row
        for(int i =0;i<m;i++){
            if(grid[0][i]==1 && !visited[0][i]){
                dfs(grid, 0, i, visited);
            }
            if(grid[n-1][i]==1 && !visited[n-1][i]){
                dfs(grid, n-1, i, visited);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(vector<vector<char>> & grid , vector<vector<bool>>& visited , int row , int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0')
            return;
        visited[row][col] = true;
        for(int i = row-1;i<=row+1;i++){
            for(int j=col-1;j<=col+1;j++){
                dfs(grid,visited,i,j);
            }
        }
        // dfs(grid,visited,row+1,col);
        // dfs(grid,visited,row-1,col);
        // dfs(grid,visited,row+1,col+1);
        // dfs(grid,visited,row+1,col-1);
        // dfs(grid,visited,row-1,col+1);
        // dfs(grid,visited,row-1,col-1);
        // dfs(grid,visited,row,col+1);
        // dfs(grid,visited,row,col-1);
    }

    public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false)); 
        int count = 0;
        for(int row =0;row < grid.size();row++){
            for(int col = 0 ; col<grid[0].size();col++){
                if(grid[row][col]=='1' && !visited[row][col])
                    {
                        count++;
                        dfs(grid,visited,row,col);
                        // bfs(grid,visited,row,col);
                    }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
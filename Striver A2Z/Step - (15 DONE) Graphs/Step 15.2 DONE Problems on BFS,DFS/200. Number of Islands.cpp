// https://leetcode.com/problems/number-of-islands/

    class Solution {
public:
    void dfs(vector<vector<char>> & grid , vector<vector<bool>>& visited , int row , int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0')
            return;
        visited[row][col] = true;
        dfs(grid,visited,row+1,col);
        dfs(grid,visited,row-1,col);
        dfs(grid,visited,row,col+1);
        dfs(grid,visited,row,col-1);
    }
    void bfs(vector<vector<char>> & grid , vector<vector<bool>>& visited , int row , int col){
        visited[row][col]=true;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            pair<int,int> curIdx = q.front();
            q.pop();
            int row = curIdx.first;
            int col = curIdx.second;
            if(row+1 < grid.size() && !visited[row+1][col] && grid[row+1][col]=='1'){
                visited[row+1][col]=true;
                q.push({row+1,col});
            }
            if(row-1 >= 0 && !visited[row-1][col] && grid[row-1][col]=='1'){
                visited[row-1][col]=true;
                q.push({row-1,col});
            }
            if(col+1 < grid[0].size() && !visited[row][col+1] && grid[row][col+1]=='1'){
                visited[row][col+1]=true;
                q.push({row,col+1});
            }
            if(col-1 >= 0 && !visited[row][col-1] && grid[row][col-1]=='1'){
                visited[row][col-1]=true;
                q.push({row,col-1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false)); 
        int count = 0;
        for(int row =0;row < grid.size();row++){
            for(int col = 0 ; col<grid[0].size();col++){
                if(grid[row][col]=='1' && !visited[row][col])
                    {
                        count++;
                        // dfs(grid,visited,row,col);
                        bfs(grid,visited,row,col);
                    }
            }
        }
        return count;

    }
};

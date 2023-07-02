class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<vector<int>>> dp(2500,vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1)));
        return memoisation(grid[0][0], grid, visited, 0, 0, dp);
        return dfs(grid[0][0], grid, visited, 0, 0);
    }

private:
    // bruteforce getting tle
    int dfs(int curCost, vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y)
    {
        if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0)
            return INT_MAX;
        if (x == grid.size() - 1 && y == grid[0].size() - 1)
            return max(curCost, grid[x][y]);
        int dirX[] = {-1, 0, 1, 0};
        int dirY[] = {0, 1, 0, -1};
        int res = INT_MAX;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visited[newX][newY])
            {
                visited[newX][newY] = 1;
                res = min(res, dfs(max(curCost, grid[newX][newY]), grid, visited, newX, newY));
                visited[newX][newY] = 0;
            }
        }
        return res;
    }
    int memoisation(int curCost, vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, vector<vector<vector<int>>> &dp)
    {
        if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0)
            return INT_MAX;
        if (x == grid.size() - 1 && y == grid[0].size() - 1)
            return max(curCost, grid[x][y]);
        if (dp[curCost][x][y] != -1)
            return dp[curCost][x][y];
        int dirX[] = {-1, 0, 1, 0};
        int dirY[] = {0, 1, 0, -1};
        int res = INT_MAX;
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visited[newX][newY])
            {
                res = min(res, memoisation(max(curCost, grid[newX][newY]), grid, visited, newX, newY, dp));
            }
        }
        visited[x][y] = 0;
        return dp[curCost][x][y] = res;
    }
};
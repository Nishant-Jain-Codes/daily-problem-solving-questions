class Solution {
private:
    const int mod = INT_MAX;
    //time complexity : O(2^(n*m))
    //space complexity : O(n+m)
    int recursive(int x , int y , int n , int m , vector<vector<int>> & grid){
        if(x>=n || y>=m || grid[x][y] == 1)
            return 0;
        if(x==n-1 && y==m-1 && grid[x][y] == 0)
            return 1;
        return recursive(x+1,y,n,m,grid) + recursive(x,y+1,n,m,grid);
    }
    //time complexity : O(n*m)
    //space complexity : O(n*m) + O(n+m)
    int memoisation(int x , int y , int n , int m , vector<vector<int>> & grid, vector<vector<int>> & dp){
        if(x>=n || y>=m || grid[x][y] == 1)
            return 0;
        if(x==n-1 && y==m-1 && grid[x][y] == 0)
            return 1;
        if(dp[x][y] != -1)
            return dp[x][y];
        return dp[x][y] = recursive(x+1,y,n,m,grid) + recursive(x,y+1,n,m,grid);
    }
    //time complexity : O(n*m)
    //space complexity : O(n*m)
    int tabulation(int n , int m , vector<vector<int>> & grid){
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1)
                break;
            dp[0][i] = 1;   
        }
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1)
                break;
            dp[i][0] =1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j] == 1)
                    continue;
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
        return dp[n-1][m-1];
    }
    //time complexity : O(n*m)
    //space complexity : O(m)
    int optimised(int n , int m , vector<vector<int>> & grid){
        vector<int> dp(m,0);
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1)
                break;
            dp[i] = 1;   
        }
        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            if(grid[i][0] != 1)
                temp[0] = 1;
            bool didRan = false;
            for(int j=1;j<m;j++){
                didRan = true;
                if(grid[i][j] == 1)
                    continue;
                temp[j] = (temp[j-1] + dp[j]);
            }
            
            if(didRan)
                dp = temp;

        }
        return dp[m-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        //return optimised(n,m,obstacleGrid);
        return tabulation(n,m,obstacleGrid);
        vector<vector<int>> dp(n , vector<int>(m, -1));
        return memoisation(0,0,n,m,obstacleGrid,dp);
        return recursive(0,0,n,m,obstacleGrid);
    }
};
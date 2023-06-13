class Solution {
private: 
    // Time Complexity => O(n*m)
    // Space Complexity => O(n+m)
    int recursive(int x , int y , int n , int m , vector<vector<int>> & grid){
        if(x>=n || y>=m) return INT_MAX;
        if(x==n-1 && y==m-1) return grid[x][y];
        return grid[x][y] + min(recursive(x+1,y,n,m,grid),recursive(x,y+1,n,m,grid));
    }
    //time complexity => O(n*m)
    //space complexity => O(n*m) + O(n+m)
    int memoisation(int x , int y , int n , int m , vector<vector<int>> & grid, vector<vector<int>> & dp){
        if(x>=n || y>=m) return INT_MAX;
        if(x==n-1 && y==m-1) return grid[x][y];
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y] = grid[x][y] + min(recursive(x+1,y,n,m,grid),recursive(x,y+1,n,m,grid));
    }
    //time complexity => O(n*m)
    //space complexity => O(n*m)
    int tabulation(int n , int m , vector<vector<int>> & grid){
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i =1;i<m;i++){
            dp[0][i]+=grid[0][i] + dp[0][i-1];
        }
        for(int i =1;i<n;i++){
            dp[i][0]+=grid[i][0] + dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
    //time complexity => O(n*m)
    //space complexity => O(m)
    int optimised(int n , int m , vector<vector<int>> & grid){
        vector<int> dp(m,0);
        dp[0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i] = dp[i-1] + grid[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            temp[0] = dp[0] + grid[i][0];
            for(int j = 1; j<m;j++){
                temp[j] = grid[i][j] + min(temp[j-1],dp[j]);
            }
            dp = temp;
        }
        return dp[m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return optimised(n,m,grid);
        return tabulation(n,m,grid);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memoisation(0,0,n,m,grid,dp);
        return recursive(0,0,n,m,grid);
    }
};
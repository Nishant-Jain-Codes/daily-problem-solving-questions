class Solution {
private:
    int recursive(int x,int y , int m , int n){
        if(x>=m || y>=n)
            return 0;
        if(x==m-1 && y==n-1)
            return 1;
        return recursive(x+1,y,m,n) + recursive(x,y+1,m,n);
    }
    int memoisation(int x,int y , int m , int n , vector<vector<int>> & dp){
        if(x>=m || y>=n)
            return 0;
        if(x==m-1 && y==n-1)
            return 1;
        if(dp[x][y] != 0)
            return dp[x][y];
        return dp[x][y] = memoisation(x+1,y,m,n,dp) + memoisation(x,y+1,m,n,dp);
    }
    int tabulation(int m , int n){
        vector<vector<int>> dp(m , vector<int>(n, 0));
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            dp[0][i] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
            }
        }
        return dp[m-1][n-1];
    }
public:
    int uniquePaths(int m, int n) {
        return tabulation(m,n);
        vector<vector<int>> dp(m , vector<int>(n, 0));
        return memoisation(0,0,m,n,dp);
        return recursive(0,0,m,n);
    }
};
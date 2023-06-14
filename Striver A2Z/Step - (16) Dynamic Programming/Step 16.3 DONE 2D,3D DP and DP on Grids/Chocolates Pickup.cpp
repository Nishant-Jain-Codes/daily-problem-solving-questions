//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private: 
    //time complexity=> O(3^m * 3^m) 
    // space complexity=> O(m)
    int recursive(int curRow , int aliceIdx, int bobIdx , int n , int m , vector<vector<int>> & grid){
        if(curRow>=n)
            return 0;
        if(aliceIdx>=m || aliceIdx<0 || bobIdx>=m || bobIdx<0)
            return -1e9;
        if(curRow==n-1){
            if(aliceIdx!=bobIdx)
                return grid[curRow][aliceIdx]+grid[curRow][bobIdx];
            else
                return grid[curRow][aliceIdx];
        }
        int ans = INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ans = max(ans, recursive(curRow+1, aliceIdx+i, bobIdx+j, n, m, grid));
            }
        }
        if(aliceIdx==bobIdx)
            ans+=grid[curRow][aliceIdx];
        else
            ans+=grid[curRow][aliceIdx]+grid[curRow][bobIdx];
        return ans;
    }
    //time complexity =>O(9*n*m*m)
    //space complexity => O(n*m*m) + O(n)
    int memoization(int curRow , int aliceIdx, int bobIdx , int n , int m , vector<vector<int>> & grid,vector<vector<vector<int>>> &dp){
        if(curRow>=n)
            return 0;
        if(aliceIdx>=m || aliceIdx<0 || bobIdx>=m || bobIdx<0)
            return -1e9;
        if(curRow==n-1){
            if(aliceIdx!=bobIdx)
                return grid[curRow][aliceIdx]+grid[curRow][bobIdx];
            else
                return grid[curRow][aliceIdx];
        }
        if(dp[curRow][aliceIdx][bobIdx]!=-1)
            return dp[curRow][aliceIdx][bobIdx];
        int ans = INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ans = max(ans, recursive(curRow+1, aliceIdx+i, bobIdx+j, n, m, grid));
            }
        }
        if(aliceIdx==bobIdx)
            ans+=grid[curRow][aliceIdx];
        else
            ans+=grid[curRow][aliceIdx]+grid[curRow][bobIdx];
        return dp[curRow][aliceIdx][bobIdx] = ans;
    }
    //time complexity O(9 * n*m*m)
    //space complexity O(n*m*m)
    int tabulation(int n , int m , vector<vector<int>> & grid){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        for(int i =0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)
                    dp[n-1][i][j] = grid[n-1][i];
                else 
                    dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
        for(int curRow = n-2;curRow>=0;curRow--){
            for(int aliceIdx = 0;aliceIdx<m;aliceIdx++){
                for(int bobIdx = 0 ; bobIdx<m;bobIdx++){
                    int ans = -1e8;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if((aliceIdx+i)>=0 && (bobIdx+j) >= 0 && (aliceIdx+i) <m && (bobIdx+j)<m)
                                ans = max(ans, dp[curRow+1][aliceIdx+i][bobIdx+j]);
                        }
                    }
                    if(aliceIdx==bobIdx)
                        ans+=grid[curRow][aliceIdx];
                    else
                        ans+=grid[curRow][aliceIdx]+grid[curRow][bobIdx];
                        
                    dp[curRow][aliceIdx][bobIdx] = ans;
                }
            }
        }
        return dp[0][0][m-1];
    }
    //time complexity O(9 * n*m*m)
    //space complexity O(m*m)
    int optimised(int n , int m , vector<vector<int>> & grid){
        vector<vector<int>> dp(m,vector<int>(m, 0));
        for(int i =0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)
                    dp[i][j] = grid[n-1][i];
                else 
                    dp[i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
        for(int curRow = n-2;curRow>=0;curRow--){
            vector<vector<int>> temp(m,vector<int>(m, 0));
            for(int aliceIdx = 0;aliceIdx<m;aliceIdx++){
                for(int bobIdx = 0 ; bobIdx<m;bobIdx++){
                    int ans = -1e8;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if((aliceIdx+i)>=0 && (bobIdx+j) >= 0 && (aliceIdx+i) <m && (bobIdx+j)<m)
                                ans = max(ans, dp[aliceIdx+i][bobIdx+j]);
                        }
                    }
                    if(aliceIdx==bobIdx)
                        ans+=grid[curRow][aliceIdx];
                    else
                        ans+=grid[curRow][aliceIdx]+grid[curRow][bobIdx];
                        
                    temp[aliceIdx][bobIdx] = ans;
                }
            }
            dp = temp;
        }
        return dp[0][m-1];
    }
public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        return optimised(n,m,grid);
        return tabulation(n,m,grid);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return memoization(0, 0, m-1, n, m, grid, dp);
        return recursive(0, 0,m-1, n, m, grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
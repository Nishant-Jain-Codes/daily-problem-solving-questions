//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
       vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<vector<int>>> dp(2500,vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1)));
        return memoisation(grid[0][0], grid, visited, 0, 0, dp);
    }
    private:
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
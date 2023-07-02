// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(vector<vector<int>>& grid , int curRow,int curCol,int baseRow,int baseCol,vector<pair<int,int>>& island,vector<vector<bool>>& visited){
        if(curRow<0 || curCol<0 || curRow>=grid.size() || curCol>=grid[0].size() || grid[curRow][curCol]==0 || visited[curRow][curCol]){
            return;
        }
        visited[curRow][curCol]=true;
        island.push_back({curRow-baseRow,curCol-baseCol});
        dfs(grid,curRow+1,curCol,baseRow,baseCol,island,visited);
        dfs(grid,curRow-1,curCol,baseRow,baseCol,island,visited);
        dfs(grid,curRow,curCol+1,baseRow,baseCol,island,visited);
        dfs(grid,curRow,curCol-1,baseRow,baseCol,island,visited);
    }
    void bfs(vector<vector<int>>& grid , int startRow,int startCol,int baseRow,int baseCol,vector<pair<int,int>>& island,vector<vector<bool>>& visited){
        queue<pair<int,int>> q;
        q.push({startRow,startCol});
        visited[startRow][startCol]=true;
        int deltaRow []= {-1, 0 , 1, 0};
        int deltaCol []= {0, 1, 0, -1};
        while(!q.empty()){
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            island.push_back({curRow-baseRow,curCol-baseCol});
            for(int i=0;i<4;i++){
                int newRow = curRow + deltaRow[i];
                int newCol = curCol + deltaCol[i];
                if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size() && grid[newRow][newCol]==1 && !visited[newRow][newCol]){
                    visited[newRow][newCol]=true;
                    q.push({newRow,newCol});
                }
            }
        }
    }
    public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited (n,vector<bool>(m,false));
        set<vector<pair<int,int>>> uniqueIslands;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    vector<pair<int,int>> island;
                    // dfs(grid,i,j,i,j,island,visited);
                    bfs(grid,i,j,i,j,island,visited);
                    uniqueIslands.insert(island);
                }
            }
        }
        return uniqueIslands.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
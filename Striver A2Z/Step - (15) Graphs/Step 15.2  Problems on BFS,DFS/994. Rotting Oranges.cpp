// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int,int> curIdx = q.front();
                q.pop();
                for(int j = 0;j<4;j++){
                    int newRow = curIdx.first + deltaRow[j];
                    int newCol = curIdx.second + deltaCol[j];
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow,newCol});
                    }
                }
            }
            if(!q.empty())
                time++;
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
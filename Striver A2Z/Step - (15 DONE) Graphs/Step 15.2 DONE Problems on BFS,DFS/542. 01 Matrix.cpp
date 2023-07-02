// https://leetcode.com/problems/01-matrix/

class Solution {
public:
//coloses distance to ZERO (0)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> minDistance(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<pair<int,int>, int>> q;//{{i, j}, distance}
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    minDistance[i][j] = 0;
                    visited[i][j] = true;
                    q.push({{i, j},0});
                }
            }
        }
        int deltaRow []= {-1,0,1,0};
        int deltaCol []= {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curX = q.front().first.first;
                int curY = q.front().first.second;
                int curDist = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int newX = curX + deltaRow[j];
                    int newY = curY + deltaCol[j];
                    if(newX<0 || newX>=n || newY<0 || newY>=m || mat[newX][newY] == 0||visited[newX][newY] == true]){
                        continue;
                    }
                    else{
                        visited[newX][newY] = true;
                        minDistance[newX][newY] = min(minDistance[newX][newY], curDist+1);
                        q.push({{newX, newY}, curDist+1});
                    }
                }
                
            }
        }
        return minDistance;
    }
};
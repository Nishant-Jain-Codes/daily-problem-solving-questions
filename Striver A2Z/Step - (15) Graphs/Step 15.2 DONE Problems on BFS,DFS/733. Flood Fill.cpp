// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(vector<vector<int>>& newImage,vector<vector<bool>>&visited , int sr,int sc , int oldColor , int newColor){
        int n = newImage.size();
        int m = newImage[0].size();
        if(sr<0 || sr>=n || sc<0 || sc>=m || visited[sr][sc]|| newImage[sr][sc]!=oldColor)
            return;
        visited[sr][sc] = true;
        newImage[sr][sc] = newColor;
        dfs(newImage,visited,sr+1,sc,oldColor,newColor);
        dfs(newImage,visited,sr-1,sc,oldColor,newColor);
        dfs(newImage,visited,sr,sc+1,oldColor,newColor);
        dfs(newImage,visited,sr,sc-1,oldColor,newColor);
    }
    void bfs(vector<vector<int>>& newImage,vector<vector<bool>>&visited , int sr,int sc , int oldColor , int newColor){
        int n = newImage.size();
        int m = newImage[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = true;
        while(!q.empty()){
            pair<int,int> curIdx = q.front();
            q.pop();
            int x = curIdx.first;
            int y = curIdx.second;
            newImage[x][y] = newColor;
            if(x+1<n && !visited[x+1][y] && newImage[x+1][y]==oldColor){
                q.push({x+1,y});
                visited[x+1][y] = true;
            }
            if(x-1>=0 && !visited[x-1][y] && newImage[x-1][y]==oldColor){
                q.push({x-1,y});
                visited[x-1][y] = true;
            }
            if(y+1<m && !visited[x][y+1] && newImage[x][y+1]==oldColor){
                q.push({x,y+1});
                visited[x][y+1] = true;
            }
            if(y-1>=0 && !visited[x][y-1] && newImage[x][y-1]==oldColor){
                q.push({x,y-1});
                visited[x][y-1] = true;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> newImage(image) ;
        // dfs(newImage, visited, sr, sc, oldColor, newColor);
        bfs(newImage, visited, sr, sc, oldColor, newColor);
        return newImage;
    }
};
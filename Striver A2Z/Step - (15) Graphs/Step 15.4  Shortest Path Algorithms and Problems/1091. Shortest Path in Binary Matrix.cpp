// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int reachable = 0;
        pair<int, int> source ={0,0};
        pair<int, int> destination ={n-1,m-1};
        if(grid[source.first][source.second]!=reachable || grid[destination.first][destination.first]!=reachable){
            return -1;
        }
        vector<vector<int>> minDist(n,vector<int>(m,-1));
        set<pair<int,pair<int,int>>> st; // {dist,{x,y}}
        st.insert({1,{source.first,source.second}});
        minDist[source.first][source.second] = 1;
        while(!st.empty()){
            pair<int,int> curCord = st.begin()->second;
            int curDist = st.begin()->first;
            st.erase(st.begin());
            int x = curCord.first;
            int y = curCord.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;
                    int newX = x + i;
                    int newY = y + j;
                    if(newX>=0 && newX<n&& newY>=0 && newY<m && grid[newX][newY]==reachable){
                        if(minDist[newX][newY]==-1 || minDist[newX][newY]>curDist+1){
                            if(minDist[newX][newY]!=-1){
                                st.erase(st.find({minDist[newX][newY],{newX,newY}}));
                            }
                            minDist[newX][newY] = curDist+1;
                            st.insert({minDist[newX][newY],{newX,newY}});
                        }
                    }
                }
            }
        }
        return minDist[destination.first][destination.second];
    }
};
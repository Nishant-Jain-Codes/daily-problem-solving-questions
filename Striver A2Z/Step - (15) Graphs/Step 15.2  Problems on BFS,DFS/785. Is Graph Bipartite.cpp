// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
private:    
    bool bfs(vector<vector<int>>& graph , int startVertex, int startColor,vector<int>&color){
        queue<pair<int,int>> q;
        q.push({startVertex,startColor});
        while(!q.empty()){
            int curVertex = q.front().first;
            int curColor = q.front().second;
            q.pop();
            for(auto it : graph[curVertex]){
                if(color[it]==-1){
                    color[it]=!curColor;
                    q.push({it,color[it]});
                }
                else if(color[it]==curColor){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph , int startVertex, int startColor,vector<int>&color){
        color[startVertex]=startColor;
        for(auto it: graph[startVertex]){
            if(color[it]==-1){
                bool ans = dfs(graph,it,!startColor,color);
                if(!ans){
                    return false;
                }
            }
            else if(color[it]==startColor){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                bool ans = dfs(graph,i,1,color);
                if(!ans){
                    return false;
                }
            }
        }
        return true;
    }
};
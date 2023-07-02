// https://leetcode.com/problems/course-schedule/

class Solution {
    private:
    bool dfsCycleCheck(int curV , vector<unordered_set<int>>& adj,vector<bool>&visited,vector<bool>&pathVisited){
        visited[curV]=true;
        pathVisited[curV]=true;
        for(auto it : adj[curV]){
            if(!visited[it]){
                if(dfsCycleCheck(it,adj,visited,pathVisited)){
                        return true;
                    }
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[curV]=false;
        return false;
    }
    bool isCycleDfs(vector<unordered_set<int>>& adj){
        vector<bool> visited(adj.size(),false);
        vector<bool> pathVisited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                if(dfsCycleCheck(i,adj,visited,pathVisited)){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].insert(it[0]);
        }
        return isCycleDfs(adj);
    }
};
class Solution {
    private:
    bool dfsCycleCheck(int curV , vector<vector<int>>& graph,vector<bool>&visited,vector<bool>&pathVisited,vector<bool>&safeState){
        visited[curV]=true;
        pathVisited[curV]=true;
        safeState[curV]=false;
        for(auto it : graph[curV]){
            if(!visited[it]){
                if(dfsCycleCheck(it,graph,visited,pathVisited,safeState)){
                        return true;
                    }
            }
            else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[curV]=false;
        safeState[curV]=true;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> safeState(V,false);
        vector<bool> visited(V,false);
        vector<bool> pathVisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool dfsSol = dfsCycleCheck(i,graph,visited,pathVisited,safeState);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(safeState[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
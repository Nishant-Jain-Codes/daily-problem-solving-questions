// https://leetcode.com/problems/critical-connections-in-a-network/description/
class Solution {
private:
    int timer = 1;
private:
    void dfs(int node , int parent , vector<bool> & visited , vector<vector<int>>& adj, vector<int> &arrivalTime , vector<int> &lowTime,vector<vector<int>>& bridges)
    {
        visited[node]=true;
        arrivalTime[node]=lowTime[node]=timer++;
        for(auto adjNode : adj[node]){
            if(adjNode == parent)
                continue;
            if(!visited[adjNode]){
                dfs(adjNode , node , visited , adj , arrivalTime , lowTime,bridges);
                lowTime[node] = min(lowTime[node] , lowTime[adjNode]);
                if(lowTime[adjNode] > arrivalTime[node])
                    bridges.push_back({node , adjNode});
            }else{
                lowTime[node] = min(lowTime[node] , arrivalTime[adjNode]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<int> arrivalTime(n);
        vector<int> lowTime(n);
        vector<vector<int>> adj(n);
        vector<vector<int>> bridges;
        for(auto &edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0 , -1 , visited , adj , arrivalTime , lowTime,bridges);
        return bridges;
    }
};
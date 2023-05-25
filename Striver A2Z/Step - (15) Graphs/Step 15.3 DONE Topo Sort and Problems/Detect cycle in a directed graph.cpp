// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfsSolution(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int curNode = q.front();
            count++;
            visited[curNode]=true;
            q.pop();
            for(auto it:adj[curNode]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return count!=V;
    }
    private:
    bool dfs(int curVertex,vector<int> adj[],vector<bool>&visited,vector<bool>&pathVisited){
        visited[curVertex] = true;
        pathVisited[curVertex] = true;
        for(auto it : adj[curVertex]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[it]){
                return true;
            }
        }    
        pathVisited[curVertex] = false;
        return false;    
    }
    bool dfsSolution(int V,vector<int> adj[]){
        vector<bool> visited(V,false);
        vector<bool> pathVisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathVisited)){
                    return true;
                }
            }
        }
        return false;
    }
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        return bfsSolution(V,adj);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
   private:
    bool dfsCycleCheck(int curV , vector<int> adj[],vector<bool>&visited,vector<bool>&pathVisited,vector<bool>&safeState){
        visited[curV]=true;
        pathVisited[curV]=true;
        safeState[curV]=false;
        for(auto it : adj[curV]){
            if(!visited[it]){
                if(dfsCycleCheck(it,adj,visited,pathVisited,safeState)){
                        safeState[curV]=false;
                        return true;
                    }
            }
            else if(pathVisited[it]){
                safeState[curV]=false;
                return true;
            }
        }
        pathVisited[curV]=false;
        safeState[curV]=true;
        return false;
    }
    vector<int> dfsSolution(int V, vector<int> adj[]){
        vector<bool> safeState(V,false);
        vector<bool> visited(V,false);
        vector<bool> pathVisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool dfsSol = dfsCycleCheck(i,adj,visited,pathVisited,safeState);
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
    private:
    vector<int> bfsSolution(int V ,vector<int> adj[]){
        vector<int> adjRev[V];
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }       
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> answer;
        while(!q.empty()){
            int curV = q.front();
            answer.push_back(curV);
            q.pop();
            for(auto it : adjRev[curV]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // return dfsSolution(V,adj);
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

//{ Driver Code Starts
// Initial Template for C++

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
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
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
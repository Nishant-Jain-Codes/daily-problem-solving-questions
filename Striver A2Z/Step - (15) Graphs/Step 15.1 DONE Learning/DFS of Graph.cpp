// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    // Function to return a list containing the DFS traversal of the graph.
    void recursiveDFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dfs) {
        visited[node] = true;
        dfs.push_back(node);
        for (auto it : adj[node]) {
            if (!visited[it]) {
                recursiveDFS(it, adj, visited, dfs);
            }
        }
    }
    void iterativeDFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dfs){
    stack<int> st;
    st.push(node);
    visited[node] = true;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        dfs.push_back(curr);
        for(int i = adj[curr].size()-1; i >= 0; i--){
            int it = adj[curr][i];
            if(!visited[it]){
                st.push(it);
                visited[it] = true;
            }
        }
    }
}


    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> dfs;
        // recursiveDFS(0, adj, visited, dfs);
        // dfs.clear();
        iterativeDFS(0, adj, visited, dfs);
        return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
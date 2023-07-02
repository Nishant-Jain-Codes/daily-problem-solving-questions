// https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> copyList(V) ;
        for(int i=0;i<V;i++){
                copyList[i].push_back(i);
            for(int j=0;j<adj[i].size();j++){
                copyList[i].push_back(adj[i][j]);
            }
        }
        return copyList;
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
        Solution obj;
        vector<vector<int>> ans = obj.printGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size() - 1; j++) {
                cout << ans[i][j] << "-> ";
            }
            cout << ans[i][ans[i].size() - 1];
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
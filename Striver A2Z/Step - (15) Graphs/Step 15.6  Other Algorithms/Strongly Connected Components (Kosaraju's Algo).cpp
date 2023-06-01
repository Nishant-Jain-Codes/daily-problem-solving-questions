// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, st);
            }
        }
        st.push(node);
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, st);
            }
        }
        visited.assign(V, false);
        int connectedComponents = 0;
        vector<vector<int>> swappedAdj(V);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                swappedAdj[it].push_back(i);
            }
        }
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                dfs(node, swappedAdj, visited, st);
                connectedComponents++;
            }
        }
        return connectedComponents;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;
    	vector<vector<int>> adj(V);
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}
    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
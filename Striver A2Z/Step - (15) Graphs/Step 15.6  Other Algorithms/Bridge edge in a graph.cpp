// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bridge-edge-in-graph

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    int timer=0;
    void dfs(int node,int parent,vector<int> &tin,vector<int> &low,vector<int> &vis,vector<int> adj[],int &ans,int c,int d){
        vis[node] =1;
        tin[node] =timer;
        low[node] =timer;
        timer++;
        for(auto child:adj[node]){
            if(child==parent){
                continue;
            }
            if(vis[child]==0){
                dfs(child,node,tin,low,vis,adj,ans,c,d);
                low[node]=min(low[node],low[child]);
                if(low[child]>tin[node]&&((child==c&&node==d)||(child==d&&node==c))){
                    ans=1;
                }
            }
            else{
                low[node]=min(low[node],low[child]);
            }
        }
    }
    public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        // Code here
        int n = v;
        vector<int> vis(n,0);
        vector<int> low(n,0);
        vector<int> tin(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
           if(vis[i]==0){    
           dfs(i,-1,tin,low,vis,adj,ans,c,d);
           }
        }
        return ans;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends
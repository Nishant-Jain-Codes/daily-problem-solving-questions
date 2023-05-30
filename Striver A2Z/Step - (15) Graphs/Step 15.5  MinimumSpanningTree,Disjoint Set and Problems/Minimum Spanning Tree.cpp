// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent;
    vector<int> size;
    int n;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        this->n = n;
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void unionBySize(int u,int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u == par_v)
            return;
        if(size[par_u] > size[par_v]){
            parent[par_v] = par_u;
            size[par_u]+=size[par_v];
        }
        else if(size[par_u]<size[par_v]){
            parent[par_u] = par_v;
            size[par_v]+=size[par_u];
        }
        else{
            parent[par_v] = par_u;
            size[par_u]+=size[par_v];
        }
    }
};
class Solution
{   
    int prims(int V, vector<vector<int>> adj[]){
        int sum=0;
        vector<bool> visited(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int curNode = pq.top().second;
            int curWeight = pq.top().first;
            pq.pop();
            if(visited[curNode]) continue;
            visited[curNode] = true;
            sum+=curWeight;
            for(auto it:adj[curNode]){
                if(!visited[it[0]]){
                    pq.push({it[1],it[0]});
                }
            }
        }
        return sum;
    }
    int kruskals(int V, vector<vector<int>> adj[]){
        DisjointSet ds(V);
        int sum=0;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int u = i;
                int v = it[0];
                int w = it[1];
                edges.push_back({w,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        for(auto it : edges){
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u,v);
                sum+=w;
            }
        }
        return sum;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // return prims(V,adj);
        return kruskals(V,adj);
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
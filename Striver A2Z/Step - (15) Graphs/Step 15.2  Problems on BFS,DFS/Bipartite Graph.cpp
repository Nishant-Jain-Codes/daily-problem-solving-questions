// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfs(vector<int>graph[] , int startVertex, int startColor,vector<int>&color){
        queue<pair<int,int>> q;
        q.push({startVertex,startColor});
        while(!q.empty()){
            int curVertex = q.front().first;
            int curColor = q.front().second;
            q.pop();
            for(auto it : graph[curVertex]){
                if(color[it]==-1){
                    color[it]=!curColor;
                    q.push({it,color[it]});
                }
                else if(color[it]==curColor){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<int>graph[] , int startVertex, int startColor,vector<int>&color){
        color[startVertex]=startColor;
        for(auto it: graph[startVertex]){
            if(color[it]==-1){
                bool ans = dfs(graph,it,!startColor,color);
                if(!ans){
                    return false;
                }
            }
            else if(color[it]==startColor){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>graph[]){
	    // Code here
	    int n = V;
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                bool ans = dfs(graph,i,1,color);
                if(!ans){
                    return false;
                }
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
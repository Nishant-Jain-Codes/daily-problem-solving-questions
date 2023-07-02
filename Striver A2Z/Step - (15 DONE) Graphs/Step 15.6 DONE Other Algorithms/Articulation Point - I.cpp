// https://practice.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    void dfs(int node , int parent , vector<bool> &visited , vector<int> & arrivalTime , vector<int> & lowTime , vector<bool>& isAp , vector<int> adj[]){
        visited[node] = true;
        arrivalTime[node] = lowTime[node] = timer++;
        int child = 0;

        for(auto adjNode : adj[node]){
            if(adjNode == parent) continue;
            if(!visited[adjNode]){
                dfs(adjNode, node, visited, arrivalTime, lowTime, isAp, adj);
                lowTime[node] = min(lowTime[node], lowTime[adjNode]);
                if(lowTime[adjNode] >= arrivalTime[node] && parent != -1){
                    isAp[node] = true;
                }
                child++;
            }else{
                lowTime[node] = min(lowTime[node], arrivalTime[adjNode]); 
            }
        }
        if(parent == -1 && child > 1){
            isAp[node] = true;
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<bool>  visited(V, false);
        vector<int> arrivalTime(V);
        vector<int> lowTime(V);
        vector<bool> isAP(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, -1, visited, arrivalTime, lowTime, isAP, adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(isAP[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
        }
        return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
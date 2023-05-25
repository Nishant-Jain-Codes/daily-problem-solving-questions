// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   private:
    //kahn's algorithm
    vector<int> bfsSolution(int V , vector<int> adj[]){
        vector<int> indegree(V,0);
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int v=0;v<V;v++){
            if(indegree[v]==0)
                q.push(v);
        }
        vector<int> output;
        while(!q.empty()){
            int curNode = q.front();
            output.push_back(curNode);
            visited[curNode]=true;
            q.pop();
            for(auto it:adj[curNode]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return output;
    }
    private:
    void dfs(int node,vector<int> adj[],vector<bool> &visited,stack<int> &stk){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,stk);
            }
        }
        stk.push(node);
    }
    vector<int> dfsSolution(int V , vector<int> adj[]){
        vector<int> output;
        vector<bool> visited(V,false);
        stack<int> stk;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,stk);
            }
        }
        while(!stk.empty()){
                    output.push_back(stk.top());
                    stk.pop();
        }
        return output;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        // return dfsSolution(V,adj);
        return bfsSolution(V,adj);
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
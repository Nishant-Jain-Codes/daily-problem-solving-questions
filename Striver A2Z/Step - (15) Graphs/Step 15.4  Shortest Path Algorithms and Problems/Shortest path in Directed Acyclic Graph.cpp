// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    //can also be solved using topo sort and then relax all edges from source
    //bfs solution 
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int start = 0;
        vector<int> minDist(N, INT_MAX);
        vector<bool> visited(N, false);
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; ++i){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        minDist[start] = 0;
        queue<int> q;
        queue.push(start);
        visited[start] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                int itIdx = it.first;
                int itDist = it.second;
                minDist[itIdx] = min(minDist[itIdx], minDist[node] + itDist);
                if(!visited[itIdx])
                    q.push(itIdx);
                visited[itIdx] = true;
            }
        }
        for(int i=0; i<N; ++i){
            if(minDist[i] == INT_MAX)
                minDist[i] = -1;
        }
        return minDist;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
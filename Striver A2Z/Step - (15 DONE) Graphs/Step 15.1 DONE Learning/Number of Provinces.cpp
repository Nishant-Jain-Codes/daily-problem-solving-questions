// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int curV , vector<vector<int>> adj, vector<bool> &visited){
        visited[curV] = true;
        for(int i =0;i<adj[curV].size();i++){
            if(adj[curV][i] && !visited[i]){
                dfs(i, adj, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V, false);
        int count = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
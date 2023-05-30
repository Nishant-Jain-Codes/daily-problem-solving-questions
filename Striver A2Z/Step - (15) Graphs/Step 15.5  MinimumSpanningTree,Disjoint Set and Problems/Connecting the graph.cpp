// https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> parent;
    vector<int> size;
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u , int v){
        int uPar = findParent(u);
        int vPar = findParent(v);
        if(uPar==vPar){
            return;
        }
        if(size[uPar] > size[vPar]){
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }else{
            parent[uPar] = vPar;
            size[vPar] += size[uPar];
        }
    }
};

class Solution {
public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto e : edge){
            if(ds.findParent(e[0]) == ds.findParent(e[1])){
                extraEdges++;
            }
            else {
                ds.unionBySize(e[0],e[1]);
            }
        }
        int connectedComponents = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)== i){
                connectedComponents++;
            }
        }
        int edgesRequired = connectedComponents-1;
        if(edgesRequired > extraEdges){
            return -1;
        }
        else 
            return edgesRequired;

    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
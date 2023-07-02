//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }   
    int findParent(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void unionBySize(int u , int v){
        int parU = findParent(u);
        int parV = findParent(v);
        if(parU == parV)
            return;
        if(size[parU] > size[parV]){
            parent[parV] = parU;
            size[parU]+=size[parV];
        }
        else{
            parent[parU] = parV;
            size[parV]+=size[parU];
        }
    }
};
class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int provinces = 0;
        for(int i =0;i<V;i++){
            if(ds.findParent(i) == i)
                provinces++;
        }
        return provinces;
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
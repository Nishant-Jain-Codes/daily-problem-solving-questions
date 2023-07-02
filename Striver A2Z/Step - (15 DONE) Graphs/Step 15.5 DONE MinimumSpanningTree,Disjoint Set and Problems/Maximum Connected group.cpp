https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int parentSize(int x){
        return size[findParent(x)];
    }
};
class Solution {
public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        int max_size = 0;
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int vertex = (i*m)+j;
                if(grid[i][j]==0)
                    continue;
                for(int k=0;k<4;k++){
                    int newX = i + deltaX[k];
                    int newY = j + deltaY[k];
                    int newVertex = (newX*m)+newY;
                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                        ds.unionBySize(vertex,newVertex);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int vertex = (i*m)+j;
                int size = 0;
                if(grid[i][j]==1)
                    {
                        size = ds.parentSize(vertex);
                    }
                else{
                    size = 1;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int newX = i + deltaX[k];
                        int newY = j + deltaY[k];
                        int newVertex = (newX*m)+newY;
                        if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                            int par = ds.findParent(newVertex);
                            if(st.find(par)==st.end()){
                                st.insert(par);
                                size+=ds.parentSize(par);
                            }
                        }
                    }
                }
                max_size = max(max_size,size);
            }
        }
        return max_size;
    }
};




//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends
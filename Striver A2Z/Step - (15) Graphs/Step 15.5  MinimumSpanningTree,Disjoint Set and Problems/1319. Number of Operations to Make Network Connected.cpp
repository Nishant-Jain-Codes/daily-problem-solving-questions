
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto e : connections){
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

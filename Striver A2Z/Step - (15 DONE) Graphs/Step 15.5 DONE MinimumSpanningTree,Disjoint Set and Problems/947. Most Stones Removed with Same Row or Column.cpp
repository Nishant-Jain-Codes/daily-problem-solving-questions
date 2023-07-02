// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int rows= 1e5;
        int cols = 1e5;
        DisjointSet ds(rows+cols);
        for(auto stone : stones){
            int curRow = stone[0];
            int curCol = stone[1];
            ds.unionBySize(curRow,rows+curCol);
        }
        unordered_set<int> uniqueParent;
        for(auto stone : stones){
            int curRow = stone[0];
            int curCol = stone[1];
            uniqueParent.insert(ds.findParent(curRow));
            uniqueParent.insert(ds.findParent(rows+curCol));
        }
        return stones.size() - uniqueParent.size();
    }
};
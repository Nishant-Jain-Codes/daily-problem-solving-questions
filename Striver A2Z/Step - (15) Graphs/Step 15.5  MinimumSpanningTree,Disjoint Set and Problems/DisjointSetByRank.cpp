class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    int n;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
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
    void unionByRank(int u,int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u == par_v)
            return;
        if(rank[par_u] > rank[par_v]){
            parent[par_v] = par_u;
        }
        else if(rank[par_u]<rank[par_v]){
            parent[par_u] = par_v;
        }
        else{
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};
class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    int n;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        this->n = n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]); 
    }

    void unionByRank(int u, int v) {
        int par_u = findParent(u);
        int par_v = findParent(v);
        if (par_u == par_v)
            return;

        if (rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        }
        else if (rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

int colorfulGraph(int n, int m, vector<vector<int>>& edges, int k, vector<int>& c) {
    unordered_map<int, int> colorMap;
    vector<vector<int>> colorArr(k);

    for (int i = 0; i < n; i++) {
        colorMap[i] = c[i];
        colorArr[c[i]].push_back(i);
    }

    DisjointSet ds(n);
    int remove = 0;

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        if (colorMap[u] == colorMap[v]) {
            ds.unionByRank(u, v);
        }
        else {
            remove++;
        }
    }

    int join = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < colorArr[i].size(); j++) {
            if (ds.findParent(colorArr[i][0]) != ds.findParent(colorArr[i][j])) {
                ds.unionByRank(colorArr[i][0], colorArr[i][j]);
                join++;
            }
        }
    }

    return remove + join;
}

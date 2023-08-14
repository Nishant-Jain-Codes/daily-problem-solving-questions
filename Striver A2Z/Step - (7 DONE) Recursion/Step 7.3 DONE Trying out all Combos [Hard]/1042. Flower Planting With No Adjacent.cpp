class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int m, vector<int>& colors, int curV) {
        if (curV == graph.size())
            return true;
        
        for (int color = 1; color <= m; color++) {
            bool canUse = true;
            for (int adj : graph[curV]) {
                if (colors[adj] == color) {
                    canUse = false;
                    break;
                }
            }
            
            if (canUse) {
                colors[curV] = color;
                if (dfs(graph, m, colors, curV + 1))
                    return true;
                else
                    colors[curV] = 0;
            }
        }
        
        return false;
    }
    
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& path) {
        int m = 4;
        
        vector<vector<int>> graph(n);
        for (const auto& p : path) {
            int u = p[0] - 1;
            int v = p[1] - 1;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> colors(n, 0);
        bool ans = dfs(graph, m, colors, 0);
        
        return colors;
    }
};
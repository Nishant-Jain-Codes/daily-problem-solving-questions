// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/958437046/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> Freq(n, 0); 
        vector<long long> minDist(n, -1); 
        vector<pair<int, int>> adj[n];

        
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];
            adj[u].emplace_back(v, d);
            adj[v].emplace_back(u, d);
        }

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        int start = 0;
        int end = n - 1;

        
        if (start == end)
            return 1;

        pq.push({ 0, start }); 
        minDist[start] = 0;
        Freq[start] = 1;

        while (!pq.empty()) {
            long long curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();

            if (curNode == end) {
                Freq[curNode] %= 1000000007;
                continue;
            }

            for (auto& it : adj[curNode]) {
                int nextNode = it.first;
                long long nextDist = curDist + it.second;

                
                if (minDist[nextNode] == -1 || minDist[nextNode] > nextDist) {
                    minDist[nextNode] = nextDist;
                    Freq[nextNode] = Freq[curNode];
                    pq.push({ nextDist, nextNode });
                }
                
                else if (minDist[nextNode] == nextDist) {
                    Freq[nextNode] += Freq[curNode];
                    Freq[nextNode] %= 1000000007;
                }
            }
        }

        return Freq[end];
    }
};
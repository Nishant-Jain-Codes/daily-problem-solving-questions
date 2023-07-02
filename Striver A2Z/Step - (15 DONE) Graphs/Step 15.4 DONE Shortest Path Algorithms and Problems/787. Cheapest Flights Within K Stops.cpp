// https://leetcode.com/problems/cheapest-flights-within-k-stops/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight : flights){
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            adj[from].push_back({to,cost});
        }
        vector<int> minCost(n,1e9);
        queue<pair<int,pair<int,int>>> q;//stops,src,cost
        q.push({0,{src,0}});
        minCost[src] = 0;
        while(!q.empty()){
            int curStops = q.front().first;
            int curNode = q.front().second.first;
            int curCost = q.front().second.second;
            q.pop();
            if(curStops>k) continue;
            for(auto it : adj[curNode]){
                int nextNode = it.first;
                int nextCost = it.second;
                if(curCost+nextCost < minCost[nextNode] && curStops<=k){
                    minCost[nextNode] = curCost+nextCost;
                    q.push({curStops+1,{nextNode,minCost[nextNode]}});
                }
            }
        }
        return minCost[dst]==1e9?-1:minCost[dst];
    }
};
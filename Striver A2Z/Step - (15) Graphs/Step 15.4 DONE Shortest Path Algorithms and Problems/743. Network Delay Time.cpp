// https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int start) {
        vector<int> minTime(n+1,-1);
        vector<pair<int,int>> adj[n+1];
        for(auto edge : times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        minTime[start] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            int curNode = pq.top().second;
            int curTime = pq.top().first;
            pq.pop();
            for(auto edge : adj[curNode]){
                if(minTime[edge.first]==-1||curTime + edge.second < minTime[edge.first]){
                    minTime[edge.first] = curTime + edge.second;
                    pq.push({minTime[edge.first],edge.first});
                }
            }
        }
        int maxTime = 0;
        for(int i=1;i<=n;i++){
            if(minTime[i] == -1){
                return -1;
            }
            maxTime = max(maxTime,minTime[i]);
        }
        return maxTime;
    }
};
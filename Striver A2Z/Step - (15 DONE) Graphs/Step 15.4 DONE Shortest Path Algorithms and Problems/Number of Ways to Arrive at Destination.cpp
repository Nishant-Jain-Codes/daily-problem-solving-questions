// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> Freq(n,0);//minDistance to n-1, freq
        vector<int> minDist(n,-1);
        vector<pair<int,int>> adj[n];
        for(auto road: roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int start = 0;
        int end = n-1;
        if(start==end)
            return 1;
        pq.push({0,start});
        minDist[start] = 0;
        Freq[start] = 1;
        while(!pq.empty()){
            int curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            if(curNode == end){
                Freq[curDist]++;
                continue;
            }
            for(auto it: adj[curNode]){
                int nextNode = it.first;
                int nextDist = curDist + it.second;
                if(minDist[nextNode]==-1 || minDist[nextNode]>nextDist){
                    minDist[nextNode] = nextDist;
                    Freq[nextNode]=1;
                    pq.push({nextDist, nextNode});
                }
                else if(minDist[nextNode]==nextDist){
                    Freq[nextNode]+=Freq[curNode];
                }
            }
        }
        return Freq[end];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
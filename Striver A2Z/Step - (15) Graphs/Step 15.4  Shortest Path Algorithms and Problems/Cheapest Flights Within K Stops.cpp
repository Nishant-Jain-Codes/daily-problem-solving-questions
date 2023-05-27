// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
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
            int curNode = q.front().second.first;
            int curStops = q.front().first;
            int curCost = q.front().second.second;
            q.pop();
            if(curStops>K) continue;
            for(auto it : adj[curNode]){
                int nextNode = it.first;
                int nextCost = it.second;
                if(curCost+nextCost < minCost[nextNode] && curStops<=K){
                    minCost[nextNode] = curCost+nextCost;
                    q.push({curStops+1,{nextNode,minCost[nextNode]}});
                }
            }
        }
        int ans = minCost[dst]==1e9?-1:minCost[dst];
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
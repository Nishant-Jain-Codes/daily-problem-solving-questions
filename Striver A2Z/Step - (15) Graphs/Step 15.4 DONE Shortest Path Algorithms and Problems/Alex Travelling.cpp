// https://practice.geeksforgeeks.org/problems/alex-travelling/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alex-travelling

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& times, int n, int start) {
        // code here
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


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends
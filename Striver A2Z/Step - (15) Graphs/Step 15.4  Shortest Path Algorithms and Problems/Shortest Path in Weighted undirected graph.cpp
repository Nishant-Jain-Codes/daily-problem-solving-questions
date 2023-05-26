// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

void recursivePath(int curIdx , int endIdx , vector<int> &parent , vector<int> & res){
    if(curIdx==endIdx){
        res.push_back(curIdx);
        return;
    }
    recursivePath(parent[curIdx],endIdx,parent,res);
    res.push_back(curIdx);
}
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> minDist(n+1,-1);
        vector<int> parent(n+1,-1);
        for(int i = 0;i<n;i++)  parent[i]=i;
        set<pair<int,int>> st;
        int start = 1;
        int end = n;
        st.insert({0,start});
        minDist[start]=0;
        while(!st.empty()){
            int curNode = st.begin()->second;
            int curDist = st.begin()->first;
            st.erase(st.begin());
            for(auto it : adj[curNode]){
                if(minDist[it.first]==-1){
                    minDist[it.first]=curDist + it.second;
                    parent[it.first]=curNode;
                    st.insert({minDist[it.first],it.first});
                }
                else if(minDist[it.first]> curDist + it.second){
                    st.erase({minDist[it.first],it.first});
                    minDist[it.first]=curDist + it.second;
                    parent[it.first]=curNode;
                    st.insert({minDist[it.first],it.first});
                }
            }
        }
        vector<int> res = {-1};
        if(minDist[n]!=-1){
            res.clear();
            recursivePath(end,start,parent,res);
        } 
        return res;
    }

};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
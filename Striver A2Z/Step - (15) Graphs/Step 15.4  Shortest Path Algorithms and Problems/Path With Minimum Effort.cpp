// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        //diff, x, y
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        pair<int, int> source ={0,0};
        pair<int, int> destination ={n-1,m-1};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {source.first, source.second}});
        int deltaX[]={-1,0,1,0};
        int deltaY[]={0,1,0,-1};
        while(!pq.empty()){
            int curDist = pq.top().first;
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;
            pq.pop();
            if(curX == destination.first && curY == destination.second){
                return curDist;
            }
            for(int i=0;i<4;i++){
                int newX = curX + deltaX[i];
                int newY = curY + deltaY[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m){
                    int newDist = max(curDist, abs(heights[curX][curY] - heights[newX][newY]));
                    if(newDist < dist[newX][newY]){
                        dist[newX][newY] = newDist;
                        pq.push({newDist, {newX, newY}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
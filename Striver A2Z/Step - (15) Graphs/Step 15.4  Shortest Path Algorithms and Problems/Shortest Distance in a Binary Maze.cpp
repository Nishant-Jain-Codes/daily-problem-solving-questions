// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> minDist(n,vector<int>(m,-1));
        set<pair<int,pair<int,int>>> st; // {dist,{x,y}}
        st.insert({0,{source.first,source.second}});
        minDist[source.first][source.second] = 0;
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,1,0,-1};
        while(!st.empty()){
            pair<int,int> curCord = st.begin()->second;
            int curDist = st.begin()->first;
            st.erase(st.begin());
            int x = curCord.first;
            int y = curCord.second;
            for(int i=0;i<4;i++){
                int newX = x + deltaX[i];
                int newY = y + deltaY[i];
                if(newX>=0 && newX<n&& newY>=0 && newY<m && grid[newX][newY]==1){
                    if(minDist[newX][newY]==-1 || minDist[newX][newY]>curDist+1){
                        if(minDist[newX][newY]!=-1){
                            st.erase(st.find({minDist[newX][newY],{newX,newY}}));
                        }
                        minDist[newX][newY] = curDist+1;
                        st.insert({minDist[newX][newY],{newX,newY}});
                    }
                }
            }
        }
        return minDist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
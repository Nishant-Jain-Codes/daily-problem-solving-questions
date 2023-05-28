// https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/0?category[]=Shortest+Path&category[]=Shortest+Path&page=1&query=category[]Shortest+Pathpage1category[]Shortest+Path&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges,
        int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(auto edge : edges){
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
        // applying floyd warshall algo 
        for(int k=0;k<n;k++){
            for(int i =0;i<n;i++ ){
                for(int j=0;j<n;j++){
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        int minCity = 0;
        int minNeighbour = n;
        for(int i=0;i<n;i++){
            int curNeighbour = 0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j] <= distanceThreshold){
                    curNeighbour++;
                }
            }
            if(curNeighbour <= minNeighbour){
                minNeighbour = curNeighbour;
                minCity = i;
            }
        }
        return minCity;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
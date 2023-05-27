// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall2042

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
        vector<vector<int>> dist = matrix;
        for(auto &i: dist)
            for(auto &j: i)
                if(j==-1)
                    j = 1e9;

        int V = matrix.size();
        //going through every vertex and checking if there is a shorter path
        for(int k=0;k<V;k++){
            //iteration for kth vertex
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
        for(auto &i: dist)
            for(auto &j: i)
                if(j==1e9)
                    j = -1;
        matrix = dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
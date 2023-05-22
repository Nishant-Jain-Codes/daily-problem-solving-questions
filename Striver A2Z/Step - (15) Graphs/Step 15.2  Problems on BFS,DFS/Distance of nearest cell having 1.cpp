// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
        vector<vector<int>> minDistance(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<pair<int,int>, int>> q;//{{i, j}, distance}
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    minDistance[i][j] = 0;
                    visited[i][j] = true;
                    q.push({{i, j},0});
                }
            }
        }
        int deltaRow []= {-1,0,1,0};
        int deltaCol []= {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curX = q.front().first.first;
                int curY = q.front().first.second;
                int curDist = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int newX = curX + deltaRow[j];
                    int newY = curY + deltaCol[j];
                    if(newX<0 || newX>=n || newY<0 || newY>=m || mat[newX][newY] == 1||visited[newX][newY] == true){
                        continue;
                    }
                    else{
                        visited[newX][newY] = true;
                        minDistance[newX][newY] = min(minDistance[newX][newY], curDist+1);
                        q.push({{newX, newY}, curDist+1});
                    }
                }
                
            }
        }
        return minDistance;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
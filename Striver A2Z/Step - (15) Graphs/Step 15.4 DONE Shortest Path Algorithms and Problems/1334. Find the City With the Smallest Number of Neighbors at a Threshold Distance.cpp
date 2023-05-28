// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
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
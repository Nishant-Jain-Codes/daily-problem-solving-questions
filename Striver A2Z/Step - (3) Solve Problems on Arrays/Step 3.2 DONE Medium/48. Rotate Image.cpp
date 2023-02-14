// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
   void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                swap(matrix[i][j],matrix[n-j-1][n-i-1]);
            }
        }
       
        for(int j=0;j<n;j++){
            for(int i=0;i<n/2;i++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    
    }
};
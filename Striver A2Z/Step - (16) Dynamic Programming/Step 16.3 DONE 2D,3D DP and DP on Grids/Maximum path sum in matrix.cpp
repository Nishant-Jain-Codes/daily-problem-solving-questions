//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int recursive(vector<vector<int>> & matrix,int curRow , int curCol){
        if(curRow >= matrix.size())
            return 0;
        if(curCol < 0 || curCol >= matrix[0].size())
            return -1e9;
        if(curRow == matrix.size()-1)
            return matrix[curRow][curCol];
        return max({matrix[curRow][curCol] + recursive(matrix,curRow+1,curCol-1),
                    matrix[curRow][curCol] + recursive(matrix,curRow+1,curCol),
                    matrix[curRow][curCol] + recursive(matrix,curRow+1,curCol+1)});        
    }
    int memoization(vector<vector<int>> & matrix,int curRow , int curCol,vector<vector<int>> & dp){
        if(curRow >= matrix.size())
            return 0;
        if(curCol < 0 || curCol >= matrix[0].size())
            return 1e9;
        if(curRow == matrix.size()-1)
            return matrix[curRow][curCol];
        if(dp[curRow][curCol] != -1)
            return dp[curRow][curCol];
        return dp[curRow][curCol] = max({matrix[curRow][curCol] + recursive(matrix,curRow+1,curCol-1),
                    matrix[curRow][curCol] + recursive(matrix,curRow+1,curCol),
                    matrix[curRow][curCol] + recursive(matrix,curRow+1,curCol+1)});  
    }
    int tabulation(vector<vector<int>>& matrix){
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix[0].size();i++){
            dp[matrix.size()-1][i] = matrix[matrix.size()-1][i];
        }
        for(int i=matrix.size()-2;i>=0;i--){
            for(int j=0;j<matrix[0].size();j++){
                if(j==0){
                    dp[i][j] = matrix[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
                }
                else if(j==matrix[0].size()-1){ 
                    dp[i][j]= matrix[i][j] + max(dp[i+1][j-1],dp[i+1][j]);
                }
                else{
                    dp[i][j] = matrix[i][j] + max({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                }
            }
        }
        int ans = INT_MIN;
        for(int i =0;i<dp[0].size();i++){
            ans = max(ans, dp[0][i]);
        }
        return ans;
    }
    int optimised(vector<vector<int>>& matrix){
        vector<int> dp(matrix[0].size(),0);
        for(int i=0;i<=matrix[0].size()-1;i++){
            dp[i] = matrix[matrix.size()-1][i];
        }
        for(int i=matrix.size()-2;i>=0;i--){
            vector<int> temp(matrix[0].size(),0);
            for(int j=0;j<matrix[0].size();j++){
                if(j==0){
                    temp[j] = matrix[i][j] + max(dp[j],dp[j+1]);
                }
                else if(j==dp.size()-1){ 
                    temp[j]= matrix[i][j] + max(dp[j-1],dp[j]);
                }
                else{
                    temp[j] = matrix[i][j] + max({dp[j-1],dp[j],dp[j+1]});
                }
            }
            dp = temp;
        }
        int ans = INT_MIN;
        for(int i =0;i<dp.size();i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }

public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        return optimised(matrix);
        return tabulation(matrix);
        //memoization solution
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            ans = max(ans,memoization(matrix,0,i,dp));
        }
        return ans;
        //recursive solution 
         ans = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            ans = max(ans,recursive(matrix,0,i));
        }   
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
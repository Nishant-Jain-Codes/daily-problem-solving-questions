class Solution {
private:
    int recursive(int curRow,int curIdx , vector<vector<int>> & triangle){
        if(curRow >= triangle.size()){
            return 0;
        }
        if(curIdx<0||curIdx >= triangle[curRow].size()){
            return 0;
        }
        int leftRecur = recursive(curRow+1,curIdx,triangle);
        int rightRecur = recursive(curRow+1,curIdx+1,triangle);
        return min(leftRecur,rightRecur) + triangle[curRow][curIdx];
        
    }
    int memoisation(int curRow,int curIdx , vector<vector<int>> & triangle,vector<vector<int>> & dp){
        if(curRow >= triangle.size()){
            return 0;
        }
        if(curIdx<0||curIdx >= triangle[curRow].size()){
            return 0;
        }
        if(dp[curRow][curIdx] != -1){
            return dp[curRow][curIdx];
        }
        int leftRecur = recursive(curRow+1,curIdx,triangle);
        int rightRecur = recursive(curRow+1,curIdx+1,triangle);
        return dp[curRow][curIdx] = min(leftRecur,rightRecur) + triangle[curRow][curIdx];
        
    }
    int tabulation(vector<vector<int>> & triangle){
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<triangle.size();i++){
            for(int j = 0;j<triangle[i].size();j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else if(j == triangle[i].size()-1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else{
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<triangle.size();i++){
            ans = min(ans,dp[triangle.size()-1][i]);
        }
        return ans;
    }
    int optimised(vector<vector<int>> & triangle){
        vector<int> dp(triangle.size(),-1);
        dp[0] = triangle[0][0];
        for(int i = 1;i<triangle.size();i++){
            for(int j = triangle[i].size()-1;j>=0;j--){
                if(j == 0){
                    dp[j] = dp[j] + triangle[i][j];
                }else if(j == triangle[i].size()-1){
                    dp[j] = dp[j-1] + triangle[i][j];
                }else{
                    dp[j] = min(dp[j-1],dp[j]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<triangle.size();i++){
            ans = min(ans,dp[i]);
        }
        return ans;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return optimised(triangle);
        return tabulation(triangle);
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return memoisation(0,0,triangle,dp);
        return recursive(0,0,triangle);
    }
};
int recursion(vector<int>& arr , int idx,int curSum,vector<vector<int>>&dp){
    if(idx<0)
        {
            int firstNo = curSum;
            int secondNo = 450-curSum;
            return abs(firstNo-secondNo);
        }
    if(dp[idx][curSum]!=-1)
        return dp[idx][curSum];
    int notTake = recursion(arr,idx-1,curSum,dp);
    int take = recursion(arr,idx-1,curSum+arr[idx],dp);
    return dp[idx][curSum] =  min(notTake,take);

}

int minDifference(int n, vector<int> a) {
    vector<vector<int>> dp(n,vector<int>(451,-1));
    return recursion(a,n-1,0,dp);
}


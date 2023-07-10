string tabulation(int x, int y, string s1, string s2){
        vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
        //filling up the dp table
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int lcs = dp[x][y];
        string ans = "";
		for(int i=0;i<lcs;i++)
			ans.push_back('#');
        int idx = lcs-1;
        int i=x, j=y;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans[idx] = s1[i-1];
                i--;
                j--;
				idx--;
            }
            else {
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else 
                    j--;
            }
        }
        if(lcs==0)
            return "";
        return ans;
}
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
    return tabulation(n, m, s1, s2);
    
}
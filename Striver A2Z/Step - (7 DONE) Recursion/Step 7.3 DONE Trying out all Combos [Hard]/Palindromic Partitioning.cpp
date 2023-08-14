//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
private:
    bool isPalindrome(const string & s , int start , int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void dfs(int curIdx , int curPartitions , int & ans , const string & s){
        if(curIdx == s.size()){
            ans = min(ans,curPartitions-1);
            return;
        }
        for(int i=curIdx;i<s.size();i++){
            if(isPalindrome(s,curIdx,i)){
                dfs(i+1,curPartitions+1,ans,s);
            }
        }
    }
    int memoisationSolution(int idx , int curPartitions , vector<vector<int>> & dp , const string & s){
        if(idx == s.size()){
            return curPartitions-1;
        }
        if(dp[idx][curPartitions] != -1){
            return dp[idx][curPartitions];
        }
        int ans = 1e9;
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                ans = min(ans,memoisationSolution(i+1,curPartitions+1,dp,s));
            }
        }
        return dp[idx][curPartitions] = ans;
    }
public:
    int palindromicPartition(string s)
    {
        // memoisation sol
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return memoisationSolution(0,0,dp,s);
        // recursiveSolution
        int ans = 1e9;
        dfs(0,0,ans,s);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
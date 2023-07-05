//{ Driver Code Starts
#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
    {
        return differentApproach(n,m,price,magical_price);
        return tabulation(price, magical_price, n, m);
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        int ans1 = memoisation(price, magical_price, n - 1, m, 0, 0, memo);
        return ans1 == 1e9 ? -1 : ans1;
        int ans =  recursion(price, magical_price,n-1,m,0,0) ;//idx , leftCost , accouried
        return ans == 1e9 ? -1 : ans;
    }
private:
    int recursion(vector<int> & price , vector<int> & magical_price , int idx , int money , int toys_gotten,int trident_used){

        if(idx<0){
            return toys_gotten == price.size() ? trident_used : 1e9;
        }
        if(money<0){
            return 1e9;
        }
        //use trident
        int use = 1e9;
        if(money>=magical_price[idx]){
            use = recursion(price,magical_price,idx-1,money-magical_price[idx],toys_gotten+1,trident_used+1);
        }
        
        //not useTrident
        int notUse = 1e9;
        if(money>=price[idx]){
            notUse = recursion(price,magical_price,idx-1,money-price[idx],toys_gotten+1,trident_used);
            
        }
        return min(use,notUse);

    }
    int memoisation(vector<int> &price, vector<int> &magical_price, int idx, int money, int toys_gotten, int trident_used, vector<vector<vector<int>>> &memo) {
        if (idx < 0) {
            return toys_gotten == price.size() ? trident_used : 1e9;
        }
        if (money < 0) {
            return 1e9;
        }
        if (memo[idx][money][toys_gotten] != -1) {
            return memo[idx][money][toys_gotten];
        }

        // Use trident
        int use = 1e9;
        if (money >= magical_price[idx]) {
            use = memoisation(price, magical_price, idx - 1, money - magical_price[idx], toys_gotten + 1, trident_used + 1, memo);
        }

        // Not use trident
        int notUse = 1e9;
        if (money >= price[idx]) {
            notUse = memoisation(price, magical_price, idx - 1, money - price[idx], toys_gotten + 1, trident_used, memo);
        }

        memo[idx][money][toys_gotten] = min(use, notUse);
        return memo[idx][money][toys_gotten];
    }
    int tabulation(vector<int> &price, vector<int> &magical_price,int n, int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //use trident
                if(j>=magical_price[i-1]){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-magical_price[i-1]]+1);
                }
                //not use trident
                if(j>=price[i-1]){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-price[i-1]]+1);
                }
            }
        }
        return dp[n][m];
    }
    //time (nlogn)
    //space (n)
    int differentApproach(int n, int m, vector<int> &price, vector<int> &magical_price){
        vector<int> sumDiff(n);
        for(int i=0;i<n;i++){
            sumDiff[i] = price[i] - magical_price[i];
        }
        sort(sumDiff.begin(),sumDiff.end(),greater<int>());
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum += price[i];
        }
        if(sum<=m){
            return 0;
        }
        int discountReq = sum-m;
        int ans = 0;
        while(discountReq>0 && ans<n){
            discountReq -= sumDiff[ans];
            ans++;
        }
        if(discountReq>0){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>price(n),magical_price(n);
        for(int i=0;i<n;i++)
            cin>>price[i];
        for(int i=0;i<n;i++)
            cin>>magical_price[i];
        Solution ob;
        int ans=ob.minimumMagic(n,m,price,magical_price);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<long long> after(2, 0);
        vector<long long> curr(2, 0);

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                long long ans;
                if (canBuy)
                {
                    long long didBuy = after[0] - prices[idx] - fee;
                    long long didNotBuy = after[1];
                    ans = max(didBuy, didNotBuy);
                }
                else
                {
                    long long didSell = after[1] + prices[idx];
                    long long didNotSell = after[0];
                    ans = max(didSell, didNotSell);
                }
                curr[canBuy] = ans;
            }
            after = curr;
        }
        return curr[1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
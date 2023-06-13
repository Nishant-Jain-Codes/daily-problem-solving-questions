//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    //time complexity : O(3^n)
    //space complexity : O(n)
    int recursive(vector<vector<int>> & points , int cur , int last , int n){
        if(cur == n){
            return 0;
        }
        int maxAns = 0;
        for(int i=0;i<3;i++){
            if(cur==last)
                continue;
            maxAns = max(maxAns , points[cur][i] + recursive(points , cur+1 , i , n));
        }
        return maxAns;
    }
    //time complexity : O(n)
    //space complexity : O(n*3) + O(n)
    int memoisation(vector<vector<int>> & points , int cur , int last , int n , vector<vector<int>> & dp){
        if(cur == n){
            return 0;
        }
        int maxAns = 0;
        if(last !=3 && dp[cur][last] != 0)
            return dp[cur][last];
        for(int i=0;i<3;i++){
            if(cur==last)
                continue;
            maxAns = max(maxAns , points[cur][i] + recursive(points , cur+1 , i , n));
        }
        if(last !=3 )
            dp[cur][last] = maxAns;
        return maxAns;
    }
    //time complexity : O(n)
    //space complexity : O(n*3)
    int tabulation(vector<vector<int>>& points , int n){
        vector<vector<int>> dp(n , vector<int>(3, 0));
        for(int i=0;i<3;i++){
            dp[0][i] = points[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                int maxAns = 0;
                for(int k=0;k<3;k++){
                    if(j==k)
                        continue;
                    maxAns = max(maxAns , points[i][j] + dp[i-1][k]);
                }
                dp[i][j] = maxAns;
            }
        }
        int ans = 0;
        for(int i =0;i<3 ;i++){
            ans = max(ans,dp[n-1][i]);
        }
        return ans;
    }
    //time complexity : O(n)
    //space complexity : O(3)
    int optimal(vector<vector<int>> points , int n){
        vector<int> dp(3, 0);
        for(int i=0;i<3;i++){
            dp[i] = points[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(3, 0);
            for(int j=0;j<3;j++){
                int maxAns = 0;
                for(int k=0;k<3;k++){
                    if(j==k)
                        continue;
                    maxAns = max(maxAns , points[i][j] + dp[k]);
                }
                temp[j] = maxAns;
            }
            dp = temp;
        }
        int ans = 0;
        for(int i =0;i<3 ;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        return optimal(points , n);
        return tabulation(points , n);
        vector<vector<int>> dp(n , vector<int>(3, 0));
        return memoisation(points , 0 , 3 , n , dp);
        return recursive(points , 0 , 3 , n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
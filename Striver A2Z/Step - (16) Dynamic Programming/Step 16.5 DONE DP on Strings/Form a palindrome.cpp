//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int countMin(string str)
    {
        // complete the function here
        //using lcs logic
        string rev = str;
        reverse(rev.begin(), rev.end());
        int lcs = LCS(str, rev);
        return str.length() - lcs;
        //using other logic
        vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
        return memoisation(str, 0, str.length() - 1, dp);
        return recursive(str, 0, str.length() - 1);
    }
private: 
    int LCS(string s1, string s2){
        int x = s1.length();
        int y = s2.length();
        vector<int> prev(max(x,y)+1, 0);
        vector<int> curr(max(x,y)+1, 0);
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j] = prev[j-1] + 1;
                else 
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return curr[y];
    }
private:
    // time complexity : O(n^2)
    int recursive(string &str, int start, int end)
    {
        if (start == end || start > end)
            return 0;
        if (str[start] == str[end])
            return recursive(str, start + 1, end - 1);
        int leftTake = recursive(str, start + 1, end);
        int rightTake = recursive(str, start, end - 1);
        return min(leftTake, rightTake) + 1;
    }
    // time complexity : O(n^2)
    // space complexity : O(n^2)
    int memoisation(string &str, int start, int end, vector<vector<int>> &dp)
    {
        if (start == end || start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (str[start] == str[end])
            return memoisation(str, start + 1, end - 1, dp);
        int leftTake = memoisation(str, start + 1, end, dp);
        int rightTake = memoisation(str, start, end - 1, dp);
        return dp[start][end] = min(leftTake, rightTake) + 1;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
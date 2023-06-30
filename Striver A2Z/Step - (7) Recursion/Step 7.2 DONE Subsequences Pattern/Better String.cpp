//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string betterString(string str1, string str2)
    {
        // code here
        if (countSub(str1) < countSub(str2))
            return str2;
        return str1;
    }
private:
    int countSub(string str)
    {
        unordered_map<char,int> lastOccur ;
        int n = str.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            char ch = str[i-1];
            dp[i] = 2*dp[i-1];
            if(lastOccur.find(ch)!=lastOccur.end()){
                dp[i] -= dp[lastOccur[ch]-1];
            }
            lastOccur[ch] = i;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
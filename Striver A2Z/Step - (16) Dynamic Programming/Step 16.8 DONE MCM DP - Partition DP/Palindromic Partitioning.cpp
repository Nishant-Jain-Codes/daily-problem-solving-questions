//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        // code here
        vector<int> dp(s.size() + 1, 0);
        for (int si = s.size() - 1; si >= 0; si--)
        {
            if (si == s.size())
                dp[si] = 0;
            else
            {
                int answer = INT_MAX;
                for (int cut = si; cut < s.size(); cut++)
                {
                    if (isPalindrome(s, si, cut))
                        answer = min(answer, dp[cut + 1] + 1);
                }
                dp[si] = answer;
            }
        }
        return dp[0] - 1;
    }
 bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
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
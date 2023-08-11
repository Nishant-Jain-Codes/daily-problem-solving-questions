//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        int ans = -1;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int unique = 0;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp[s[j]]==1){
                unique++;
            }
            if(unique<k)
                j++;
            else if(unique == k){
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                while(i<j && unique>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        unique--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code EndsF
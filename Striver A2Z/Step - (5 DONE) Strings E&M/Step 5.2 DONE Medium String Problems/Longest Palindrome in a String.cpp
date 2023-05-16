// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-palindrome-in-a-string

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int res = 0;
        string ans = "";
        for(int i=0;i<s.length();i++){
            // checking for odd length
            int l = i;
            int r = i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1 > res){
                    res = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            //checking for even length
            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1 > res){
                    res = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
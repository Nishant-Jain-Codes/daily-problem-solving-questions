// https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sum-of-beauty-of-all-substrings

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int beautySum(string s) {
        // Your code goes here
        int ans=0;
        for(int i=0;i<s.length();i++){
            int freq[26] = {0};
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                int maxFreq=0;
                int minFreq=s.length();
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        maxFreq=max(maxFreq,freq[k]);
                        minFreq=min(minFreq,freq[k]);
                    }
                }
                ans+=maxFreq-minFreq;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
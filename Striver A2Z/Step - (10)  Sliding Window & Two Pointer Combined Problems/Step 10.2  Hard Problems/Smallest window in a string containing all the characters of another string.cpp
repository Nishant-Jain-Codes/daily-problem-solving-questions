//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
   string smallestWindow(string s, string t)
    {
        // Your code here
        vector<int> hash1(256, 0);
        vector<int> hashReq(256, 0);
        for (auto c : t)
            hashReq[c-'a']++;
        int i = 0, j = 0, satisfyCount = 0, minLen = INT_MAX, minStart = -1;
        while (j < s.length())
        {
            hash1[s[j] - 'a']++;
            if (hash1[s[j] - 'a'] <= hashReq[s[j] - 'a'])
                satisfyCount++;
            while (satisfyCount == t.length())
            {
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    minStart = i;
                }
                hash1[s[i] - 'a']--;
                if (hash1[s[i] - 'a'] < hashReq[s[i] - 'a'])
                    satisfyCount--;
                i++;
            }
            j++;
        }
        if (minStart == -1)
            return "-1";
        else
            return s.substr(minStart, minLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
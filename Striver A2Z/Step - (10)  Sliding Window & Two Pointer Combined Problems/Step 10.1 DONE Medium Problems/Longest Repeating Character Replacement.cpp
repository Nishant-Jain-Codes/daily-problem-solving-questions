//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int characterReplacement(string S, int K)
    {
        // code here
        vector<int> hash(26, 0);
        int i =0,j=0,ans=0,maxFreq=0;
        while(j<S.length()){
            hash[S[j]-'A']++;
            maxFreq = max(maxFreq, hash[S[j]-'A']);
            int flipReq = j-i+1-maxFreq;
            if(flipReq<=K)
                ans = max(ans, j-i+1);
            else{
                hash[S[i]-'A']--;
                i++;
            }
            j++;
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends
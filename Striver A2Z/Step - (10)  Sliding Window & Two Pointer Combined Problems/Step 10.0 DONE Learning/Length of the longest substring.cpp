//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr2(string s) {
    int ans = 0;
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    int unique = 0;
    
    while (j < s.length()) {
        mp[s[j]]++;
        if (mp[s[j]] == 1) {
            unique++;
        }
        
        if (unique == j - i + 1) {
            ans = max(ans, j - i + 1);
            j++;
        } else {
            while (i < j && unique < j - i + 1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    unique--;
                }
                i++;
            }
            j++;
        }
    }
    
    return ans;
}

    //getting tle
    int longestUniqueSubsttr(string S){
        //code
        vector<int> m(256,0);
        int i=0,j=0;
        int repeating = 0;
        int ans = 0;
        while(j<S.length()){
            int curChar = S[j]-'a';
            m[curChar]++;
            if(m[curChar]>1){
                repeating++;
            }
            if(repeating == 0){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                while(i<j && repeating>0){
                    int curChar = S[i]-'a';
                    m[curChar]--;
                    if(m[curChar]==1){
                        repeating--;
                    }
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
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
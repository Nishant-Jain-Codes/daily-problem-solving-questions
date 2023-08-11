//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string word, string txt) {
	    // code here
        vector<int> reqHash(26,0);
        for(int i=0;i<word.length();i++)
            reqHash[word[i]-'a']++;
        vector<int> hash(26,0);
        int i =0;
        int j = 0;
        int k = word.length();
        int ans = 0;
        while(j<txt.length()){
            hash[txt[j]-'a']++;
            if(j-i+1<k)
                j++;
            else{
                for(int idx=0;idx<26;idx++){
                    if(hash[idx]!=reqHash[idx])
                        break;
                    if(idx==25)
                        ans++;
                }
                hash[txt[i]-'a']--;
                i++;
                j++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
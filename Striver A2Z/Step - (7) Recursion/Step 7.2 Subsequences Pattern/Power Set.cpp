// https://practice.geeksforgeeks.org/problems/power-set4302/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=power-set

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<string> ans;
    
   void generate(string str, int idx, string& s) {
        if (idx >= s.length()) {
            if (!str.empty()) {
                ans.push_back(str);
            }
            return;
        }

        generate(str, idx + 1, s); // not considering
        generate(str + s[idx], idx + 1, s); // considering
    }
    
    vector<string> AllPossibleStrings(string s) {
        string str = "";
        generate(str, 0, s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        set<string> answer;
        string output = "";
        recursion(s.length()-1, t.length()-1, s, t, output, answer);
        vector<string> sol = vector<string>(answer.begin(), answer.end());
        return sol;
    }

private:
// ! getting tle    
    void recursion(int idxS, int idxT, const string& s, const string& t, const string& output, set<string>& answer) {
        if (idxS < 0 || idxT < 0) {
            if (!output.empty()) {
                string longest = "";
                if (!answer.empty()) {
                    longest = *answer.begin();
                }
                int curMaxLen = longest.length() > 0 ? longest.length() : 0;
                if (output.length() > curMaxLen) {
                    answer.clear();
                    answer.insert(output);
                } else if (output.length() == curMaxLen) {
                    answer.insert(output);
                }
            }
            return;
        }
        
        if (s[idxS] == t[idxT]) {
            string newOutput = s[idxS] + output;
            recursion(idxS-1, idxT-1, s, t, newOutput, answer);
        }
        else {
            recursion(idxS-1, idxT, s, t, output, answer);
            recursion(idxS, idxT-1, s, t, output, answer);
        }
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends
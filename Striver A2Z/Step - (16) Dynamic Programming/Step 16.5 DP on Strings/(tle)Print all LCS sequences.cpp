//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        //for tabulation solution
        return tabulation(s, t);
        //for brute force recursive solution
        unordered_set<string> answer;
        string output = "";
        recursion(s.length()-1, t.length()-1, s, t, output, answer);
        vector<string> answerVec(answer.begin(), answer.end());
        return answerVec;
    }
    
private:
// ! getting tle    (30/40)
    void recursion(int idxS, int idxT, const string& s, const string& t, const string& output, unordered_set<string>& answer) {
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
// ! also getting tle (35/40)
    vector<string> tabulation( string s1, string s2){
        int x = s1.length();
        int y = s2.length();
        vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
        set<string> answer;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        queue<pair<pair<int,int>,string>> q;
        q.push({{x,y},""});
        
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            string temp = q.front().second;
            q.pop();
            while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                    temp = s1[i-1] + temp;
                    i--;
                    j--;
                }
                else {
                    if(dp[i-1][j]>dp[i][j-1])
                        i--;
                    else if(dp[i-1][j]<dp[i][j-1])
                        j--;
                    else {
                        q.push({{i-1,j},temp});
                        j--;
                    }
                }
            }
            answer.insert(temp);
        }
        vector<string> answerVec(answer.begin(),answer.end());
        
        return answerVec;
    }
};


// ! solution 

// https://www.geeksforgeeks.org/printing-longest-common-subsequence-set-2-printing/
// https://www.youtube.com/watch?v=gfxdpQIf2NI&ab_channel=GeeksforGeeksPractice



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
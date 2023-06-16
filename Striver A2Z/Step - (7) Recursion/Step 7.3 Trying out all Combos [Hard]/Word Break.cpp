//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
private: 
    bool dfs(int idx , string & s , unordered_set<string>&dict){
        if(idx == s.size()){
            return true;
        }
        for(int i=idx;i<s.size();i++){
            string temp = s.substr(idx, i-idx+1);
            if(dict.find(temp) != dict.end()){
                if(dfs(i+1, s, dict)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int wordBreak(string s, vector<string> &wordDict) {
        //code here
        unordered_set<string> dict;
        for(auto &word : wordDict){
            dict.insert(word);
        }
        return dfs(0, s, dict);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
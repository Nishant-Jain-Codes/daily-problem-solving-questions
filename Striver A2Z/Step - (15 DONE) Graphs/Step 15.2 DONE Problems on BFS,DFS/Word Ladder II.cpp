// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        while(!q.empty()){
            vector<string> curr = q.front();
            q.pop();
            //erase all words used in previous level
            if(curr.size()>level){
                level++;
                for(auto it : usedOnLevel){
                    dict.erase(it);
                }
                usedOnLevel.clear();
            }
            string lastWord = curr.back();
            if(lastWord == endWord){
                if(ans.size()==0){
                    ans.push_back(curr);
                }
                else{
                    if(ans[0].size()>curr.size()){
                        ans.clear();
                        ans.push_back(curr);
                    }
                    else if(ans[0].size()==curr.size()){
                        ans.push_back(curr);
                    }
                }
            }
            for(int i=0;i<lastWord.length();i++){
                string temp = lastWord;
                for(char c = 'a' ; c<='z' ; c++){
                    temp[i] = c;
                    if(dict.find(temp)!=dict.end()){
                        curr.push_back(temp);
                        q.push(curr);
                        usedOnLevel.push_back(temp);
                        curr.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
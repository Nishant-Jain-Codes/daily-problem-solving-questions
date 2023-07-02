// https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set <string> dict(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        dict.erase(startWord);
        while(!q.empty()){
            string curWord = q.front().first;
            int curDist = q.front().second;
            q.pop();
            for(int idx = 0;idx<curWord.length();idx++){
                string temp = curWord;
                for(char c = 'a';c<='z';c++){
                    temp[idx] = c;
                    if(dict.find(temp)!=dict.end()){
                        if(temp == targetWord){
                            return curDist+1;
                        }
                        q.push({temp,curDist+1});
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
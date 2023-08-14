//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
private: 
    bool dfs(vector<vector<char>>& board , string & word , int i , int j , int curIdx , vector<vector<bool>>& visited){
        if(curIdx == word.size())
            return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || visited[i][j] || board[i][j] != word[curIdx]){
            return false;
        }
        
        visited[i][j] = true;
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            if(dfs(board, word, i+deltaX[k], j+deltaY[k], curIdx+1, visited)){
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0] == board[i][j] && dfs(board, word, i, j, 0, visited)){
                    return true;
                }   
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
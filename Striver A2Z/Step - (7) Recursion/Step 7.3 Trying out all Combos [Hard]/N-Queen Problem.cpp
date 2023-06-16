//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isValid(int row,int col,int n,vector<int>& board ){
        if(row==0)
            return true;
        if(board[col]!=-1) return false; //column already filled
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(board[j] == i) return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[j] == i) return false;
        }
        return true;
    }
    void solve(int curRow, int n , vector<int> &board, vector<vector<int>> &ans){
        if(curRow == n){
            vector<int> curBoard;
            for (auto cell : board) {
                curBoard.push_back(cell + 1);
            }
            ans.push_back(curBoard);
            return;
        }
        for(int col = 0; col<n;col++){
            if(isValid(curRow,col,n,board)){
                board[col] = curRow;
                solve(curRow+1,n,board,ans);
                board[col] = -1;
            }
        }
        return ;
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> board(n, -1);
        solve(0, n, board, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
private:
    void dfs(int i , int j , int n , string & path ,
    vector<vector<int>> &matrix,vector<vector<bool>> &visited ,
    vector<string>& result){
        if(i==n-1 && j==n-1 && matrix[i][j]==1){
            result.push_back(path);
            return;
        }
        if(i<0 || j<0 || i>=n || j>=n || matrix[i][j]==0 || visited[i][j]){
            return;
        }
        visited[i][j] = true;
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,1,0,-1};
        char dir[] = {'U','R','D','L'};
        for(int k=0;k<4;k++){
            path.push_back(dir[k]);
            dfs(i+deltaX[k],j+deltaY[k],n,path,matrix,visited,result);
            path.pop_back();
        }
        visited[i][j] = false;
    }
public:
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // Your code goes here
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<string> result;
        string path = "";
        dfs(0,0,n,path,matrix,visited,result);
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
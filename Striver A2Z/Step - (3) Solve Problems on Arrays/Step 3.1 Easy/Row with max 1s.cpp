// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public: 
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code here
        int col=0;
        for(int i=0;i<n;i++){
            if(arr[i][col]==1)
            {
               return i;
            }
            if(i==n-1)
            {
                i=-1;
                col++;
                if(col>m-1)
                    return -1;
            }
           
        }
        return -1;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
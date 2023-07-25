//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &g, vector<int> &s) {
        // code here
        int happyhappyhappy = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childIdx = 0;
        int cookieIdx = 0;
        while(childIdx<N && cookieIdx<M){
            if(g[childIdx]<=s[cookieIdx]){
                happyhappyhappy++;
                childIdx++;
                cookieIdx++;
            }
            else{
                cookieIdx++;
            }
        }
        return happyhappyhappy;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends
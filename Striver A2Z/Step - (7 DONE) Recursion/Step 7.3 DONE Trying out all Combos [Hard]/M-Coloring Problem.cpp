//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
private: 
    bool dfs(bool graph[101][101] , int m , int n , vector<int> &colors , int curV){
        if(curV == n)
            return true;
        for(int color = 1; color<=m;color++){
            bool canUse = true;
            for(int i = 0;i<n;i++){
                if(graph[curV][i] && colors[i] == color)
                    {
                        canUse = false;
                        break;
                    }
            }
            if(canUse){
                colors[curV]=color;
            if(dfs(graph, m, n, colors, curV+1))
                return true;
            else 
                colors[curV] = 0;
            }
            
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n, 0);
        return dfs(graph, m, n, color,  0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
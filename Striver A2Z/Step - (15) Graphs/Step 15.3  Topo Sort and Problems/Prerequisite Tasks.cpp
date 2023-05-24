// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    //kahn's algorithm
    vector<int> bfsSolution(int V , vector<int> adj[]){
        vector<int> indegree(V,0);
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int v=0;v<V;v++){
            if(indegree[v]==0)
                q.push(v);
        }
        vector<int> output;
        while(!q.empty()){
            int curNode = q.front();
            output.push_back(curNode);
            visited[curNode]=true;
            q.pop();
            for(auto it:adj[curNode]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return output;
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
        vector<int> adj[N];
        for(auto i: prerequisites){
            adj[i.second].push_back(i.first);
        }
        vector<int> output = bfsSolution(N,adj);
        return output.size()==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
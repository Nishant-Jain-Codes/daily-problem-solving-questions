// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    private:
    vector <int> simpleQueueSol(int V, vector<vector<int>> adj[], int start)
    {
        vector<int> dist(V,-1);
        dist[start]=0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            for(auto it : adj[curNode]){
                if(dist[it[0]]==-1 || dist[it[0]]>dist[curNode]+it[1]){
                    dist[it[0]]=dist[curNode]+it[1];
                    q.push(it[0]);
                }
            }
        }
        return dist;
    }
    vector <int> priorityQueueSol(int V, vector<vector<int>> adj[], int start){
        vector<int> minDist(V,-1);
        minDist[start]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,start});//dist, node
        while(!pq.empty()){
            int curNode = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();
            for(auto it : adj[curNode]){
                if(minDist[it[0]]==-1 || minDist[it[0]]>curDist+it[1]){
                    minDist[it[0]]=curDist+it[1];
                    pq.push({minDist[it[0]],it[0]});
                }
            }
        }
        return minDist;
    }
    vector <int> setSol(int V, vector<vector<int>> adj[], int S){
        set<pair<int,int>> st;
        vector<int> minDist(V,-1);
        st.insert({0,S});
        minDist[S]=0;
        while(!st.empty()){
            int curNode = st.begin()->second;
            int curDist = st.begin()->first;
            st.erase(st.begin());
            for(auto it: adj[curNode]){
                if(minDist[it[0]]==-1){
                    minDist[it[0]]=curDist + it[1];
                    st.insert({minDist[it[0]],it[0]});
                }
                else if(minDist[it[0]]>curDist+it[1]){
                    st.erase(st.find({minDist[it[0]],it[0]}));
                    minDist[it[0]]=curDist + it[1];
                    st.insert({minDist[it[0]],it[0]});
                }
            }
        }
        return minDist;
    }
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        return setSol(V, adj, S);
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
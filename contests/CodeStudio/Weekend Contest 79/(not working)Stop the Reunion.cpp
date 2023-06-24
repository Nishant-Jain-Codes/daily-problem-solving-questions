void dfs(int curV , int curDist , int k ,vector<int> adj[], vector<int> & visited , vector<int> & answer,stack<int> & st){
    if(curDist%k==0 && answer[curV]==0)
        {
            answer[curV]=1;
            st.push(curV);
        }
    visited[curV]=1;
    for(auto adjV : adj[curV]){
        if(!visited[adjV]){
            dfs(adjV,curDist+1,k,adj,visited,answer,st);
        }
    }
    
}
vector<int> stopTheReunion(int n, vector<vector<int>> &edges, int k) {
    // Write your code here.
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int> answer(n,0);
    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int targNode = st.top();
        st.pop();
        vector<int> visited(n,0);
        dfs(targNode,0,k,adj,visited,answer,st);
    }
    return answer;
}

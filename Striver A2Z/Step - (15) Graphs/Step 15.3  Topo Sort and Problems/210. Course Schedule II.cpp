// https://leetcode.com/problems/course-schedule-ii/

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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> adj[N];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> output = bfsSolution(N,adj);
        if( output.size()==N)
            return output;
        else
            return {};
    }
};
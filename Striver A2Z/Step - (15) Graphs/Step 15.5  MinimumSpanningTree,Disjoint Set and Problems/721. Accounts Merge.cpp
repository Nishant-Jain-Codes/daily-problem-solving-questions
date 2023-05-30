// https://leetcode.com/problems/accounts-merge/description/

class DisjointSet{
    vector<int> parent;
    vector<int> size;
    int n;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        this->n = n;
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void unionBySize(int u,int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u == par_v)
            return;
        if(size[par_u] > size[par_v]){
            parent[par_v] = par_u;
            size[par_u]+=size[par_v];
        }
        else if(size[par_u]<size[par_v]){
            parent[par_u] = par_v;
            size[par_v]+=size[par_u];
        }
        else{
            parent[par_v] = par_u;
            size[par_u]+=size[par_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        unordered_map<string, int> emailToIndex; // Maps email to the corresponding index
        DisjointSet ds(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string email = details[i][j];
                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = i; // Store the index of the first occurrence of an email
                } else {
                    ds.unionBySize(i, emailToIndex[email]); // Merge the current index with the index of the first occurrence of the email
                }
            }
        }
        
        vector<vector<string>> mergedDetails(n);
        for (auto& entry : emailToIndex) {
            int parentIndex = ds.findParent(entry.second);
            mergedDetails[parentIndex].push_back(entry.first);
        }
        
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedDetails[i].empty())
                continue;
            
            sort(mergedDetails[i].begin(), mergedDetails[i].end());
            mergedDetails[i].insert(mergedDetails[i].begin(), details[i][0]);
            ans.push_back(mergedDetails[i]);
        }
        
        return ans;
    }
};
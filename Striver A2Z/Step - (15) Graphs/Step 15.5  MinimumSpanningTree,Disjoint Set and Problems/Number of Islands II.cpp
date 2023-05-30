// https://www.codingninjas.com/codestudio/problems/number-of-islands-ii_1266048
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

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.
    vector<bool> visited(n*m,false);
    vector<int> ans;
    DisjointSet ds(n*m);
    int count = 0;
    int deltaX[] = {-1,0,1,0};
    int deltaY[] = {0,1,0,-1};
    for(auto query : q){
        int x = query[0];
        int y = query[1];
        int index = x*m + y;
        count++;
        visited[index] = true;
        for(int i=0;i<4;i++){
            int newX = x + deltaX[i];
            int newY = y + deltaY[i];
            int newIndex = newX*m + newY;
            if(newX>=0 && newX<n && newY>=0 && newY<m && visited[newIndex]){
                int par1 = ds.findParent(index);
                int par2 = ds.findParent(newIndex);
                if(par1 != par2){
                    count--;
                    ds.unionBySize(par1,par2);
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}
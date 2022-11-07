/*

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 

*/

// solution 

#include <bits/stdc++.h>
using namespace std;
void getConnect(int **graph,bool *vis,vector<int>&path,int v,int si)
{	
    if(!vis[si])
    {
        path.push_back(si);
        vis[si]=true;
    }
    
    for(int i=0;i<v;i++)
    {
        if(graph[si][i]&&!vis[i])
        {
            path.push_back(i);
            vis[i]=true;
            getConnect(graph,vis,path,v,i);
        }
    }
}
int main() {
    // Write your code here
    int V,E;
    cin>>V>>E;
    int **graph=new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
        for( int j=0;j<V;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    bool *vis=new bool[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=false;
    }
    vector<vector<int>> ans;
    for(int i=0;i<V;i++)
    {
        vector<int> path;
        if(!vis[i])
        {
            getConnect(graph,vis,path,V,i);
            ans.push_back(path);
        }
    }
    cout<<ans.size()<<endl;
    delete []vis ;
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;

}

/*

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/

// solution

#include <bits/stdc++.h>
using namespace std;
bool getPath(int**graph,bool*vis,vector<int>&path,int v,int s,int e)
{
    if(s==e)
    {   
        path.push_back(e);
        return true;
    }
    
    vis[s]=true;
    for(int i=0;i<v;i++)
    {
        if(graph[s][i]&&!vis[i])
        {
            if(getPath(graph,vis,path,v,i,e))
            {
                path.push_back(s);
                return true;
            } 
            
        }

    }
    
    return false;
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
    int s,e;
    cin>>s>>e;
    bool *vis=new bool[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=false;
    }
    vector<int> path;
    bool ans=getPath(graph,vis,path,V,s,e);
    
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    delete []vis ;
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;

    
}

/*

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
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
Sample Output 2

*/

// solution 

#include <bits/stdc++.h>
using namespace std;


void getPathBFS(int **graph,vector<int>& path,int v,int s,int e)
{
    bool *vis=new bool[v];
    for(int i=0;i<v;i++)
        {
            vis[i]=false;
        }
    unordered_map<int,int> map;
    queue<int> q;
    q.push(s);
    map[s]=-1;
    bool br=false;
    while(!q.empty())
    {
        int f =q.front();
        q.pop();
        vis[f]=true;
        
        for(int i=0;i<v;i++)
        {
            if(graph[f][i]&&!vis[i])
            {
                q.push(i);
                map[i]=f;
                if(i==e)
                {
                    br=true;
                    break;  
                }

            }
        }
        if(br)
            break;

    }
    if(map.count(e)<=0)
        return;
    else 
    {
        int check=e;
        while(check!=-1)
        {
            path.push_back(check);
            check=map[check];
        }
        return ;
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
    int s,e;
    cin>>s>>e;
    bool *vis=new bool[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=false;
    }
    vector<int> path;
    getPathBFS(graph,path,V,s,e);
    for(auto x:path)
    {
        cout<<x<<" ";
    }
    delete []vis ;
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;

    
}

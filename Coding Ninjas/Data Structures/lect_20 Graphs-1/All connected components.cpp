/*

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2

*/

//solution 


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
    for(int i=0;i<V;i++)
    {
        vector<int> path;
        if(!vis[i])
        {
            getConnect(graph,vis,path,V,i);
            sort(path.begin(),path.end());
            for(int i=0;i<path.size();i++)
            {	
                cout<<path[i]<<" ";
            }
            path.clear();
            cout<<endl;
        }
    }
    delete []vis ;
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;

}

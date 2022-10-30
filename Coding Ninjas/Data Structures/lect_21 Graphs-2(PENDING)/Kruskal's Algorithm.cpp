/*

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5

*/

#include <bits/stdc++.h>
using namespace std;


class edge{
public:
    int v1;
    int v2;
    int w;
    edge(int v1,int v2, int w)
    {
        this ->v1=v1;
        this ->v2=v2;
        this ->w = w;
    }
};

bool comp(edge e1,edge e2)
{
    if(e1.w<e2.w)
        return true;
    return false;
}
int giveParent(int v,int *parent)
{
   if(parent[v]==v)
    return v;
    
    return giveParent(parent[v],parent);
}
bool isPossible(edge e1,int *parent)
{
    int p1 = giveParent(e1.v1,parent);
    int p2 = giveParent(e1.v2,parent);
    parent[p1]=p2;
    if(p1==p2)
        return false;
    else 
        return true;
}
void makeMST(vector<edge> graph,int *parent , int v)
{
    vector<edge> MST;
    int count=0;
    for(int i=0;i<graph.size();i++)
    {
        if(count>v-1)
            break;

        edge currEdge= graph[i];
        if(isPossible(currEdge,parent))
        {
            count++;
            MST.push_back(currEdge);
        }
    }
    for(int i=0;i<v-1;i++)
    {
        edge e = MST[i];
        int v1=e.v1;
        int v2=e.v2;
        int w=e.w;
        if(v1<v2)
            cout<<v1<<" "<<v2<<" "<<w<<endl;
        else 
            cout<<v2<<" "<<v1<<" "<<w<<endl; 
    }
}


int main()
{   
    int v,e;
    cin>>v>>e;
    vector<edge> graph;
    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        edge  e1(v1,v2,w);
        graph.push_back(e1);
    }
    int *parent = new int[v];
    for(int i=0;i<v;i++)
        {
            parent[i]=i;
        }
    sort(graph.begin(),graph.end(),comp);

    makeMST(graph,parent,v);
    return 0;
}
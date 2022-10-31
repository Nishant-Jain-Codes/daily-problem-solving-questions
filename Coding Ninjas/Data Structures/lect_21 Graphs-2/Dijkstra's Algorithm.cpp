/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
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
0 0
1 3
2 4
3 5
*/
//time complexity O(n^2) unoptimised
//possible complexity if optimised O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int findMinDistIndex(int *minDist,bool *visited,int V)
{
    int minDistIndex=-1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]&&(minDistIndex==-1||minDist[i]<minDist[minDistIndex]))
            minDistIndex=i;
    }
    return minDistIndex;
}

void Dijkstras(int **graph,int V)
{
    bool *visited = new bool[V];
    int *minDist = new int[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        minDist[i]=INT_MAX;
    }
    minDist[0]=0;

    for(int i=0;i<V-1;i++)
    {
        int minDistIndex=findMinDistIndex(minDist,visited,V);
        visited[minDistIndex]=true;
        for(int j=0;j<V;j++)
        {
            if(!visited[j]&&graph[minDistIndex][j]!=0)
            {
                int dist = minDist[minDistIndex]+graph[minDistIndex][j];
                if(dist<minDist[j])
                {
                    minDist[j]=dist;
                }                
            }
        }
    }
    // output

    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<minDist[i]<<endl;
    }
    //deallocation 

    delete []visited;
    delete []minDist;
}

int main()
{
    int V,E;
    cin>>V>>E;
    int **graph = new int * [V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y]=w;
        graph[y][x]=w;
    }

     Dijkstras(graph,V);
    
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;
    return 0;
}
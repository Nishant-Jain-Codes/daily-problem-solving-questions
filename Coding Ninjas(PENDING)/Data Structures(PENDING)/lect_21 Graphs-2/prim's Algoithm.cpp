/*

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
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
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5

*/

//time complexity O(N^2) - unOptimised 
//possible optimised timecomplexity O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int findMinWeightIndex(int *weight , bool * visited , int V)
{
    int minWeightIndex = -1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]&&(minWeightIndex==-1||weight[i]<weight[minWeightIndex]))
            minWeightIndex=i;
    }
    return minWeightIndex;
}
void giveMST(int **graph, int V)
{
    bool *visited = new bool [V];
    int *weight = new int [V];
    int *parent = new int [V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    //traversing all the vertices
 
    for(int i=0;i<V;i++)
    {
        //find minimum weight vertex;
        int minWeightIndex = findMinWeightIndex(weight,visited,V);
        //mark that index visited;
        visited[minWeightIndex]=true;
        //explore
        for(int j=0;j<V-1;j++)
        {
        //check its unvisited neighbours and then decide to update their parent and weights
            if(graph[minWeightIndex][j]!=0&&!visited[j])
            {
                if(graph[minWeightIndex][j]<weight[j])
                {
                    weight[j]=graph[minWeightIndex][j];
                    parent[j]=minWeightIndex;
                }
            }
        }

    }
    for(int i=1;i<V;i++)
    {
        cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
    }
    //print graph;
    // deallocating the arrays
    delete[]visited;
    delete[]weight;
    delete[]parent;
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
    giveMST(graph,V);
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;
    return 0;
}
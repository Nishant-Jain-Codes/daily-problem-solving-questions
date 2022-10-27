/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
*/

#include <iostream>
using namespace std;
int sol(int **graph,int V)
{
    int ans=0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j]==1)
            {
                for(int k=0;k<V;k++)
                {
                    if(k==i)
                        continue;
                    if(graph[j][k]==1)
                        
                        if(graph[i][k]==1)
                            ans++;
                }
            }
        }
    }
    return ans;
}
int main() {
    // Write your code here
    int V,E;
    cin>>V>>E;
    int **graph=new int * [V];
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
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }

    int ans=sol(graph,V)/6; 
 
    cout<<ans<<endl;
    for(int i=0;i<V;i++)
    {
        delete []graph[i];
    }
    delete []graph;
}
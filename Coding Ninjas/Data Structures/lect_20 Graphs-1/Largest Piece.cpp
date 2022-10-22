/*


It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3


*/

// solution 

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
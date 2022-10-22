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

#include<bits/stdc++.h>
using namespace std;
int sol(vector<vector<int>> &cake, int n,int r,int c,int **arr)
{
    if(r>=n||c>=n||c<0||r<0||cake[r][c]!=1)
        return 0;
    if(arr[r][c]!=-1)
        return arr[r][c];
    cake[r][c]=-1;//marking visited
    int a=sol(cake,n,r,c+1,arr);
    int b=sol(cake,n,r,c-1,arr);
    int C=sol(cake,n,r+1,c,arr);
    int d=sol(cake,n,r-1,c,arr);
    int ans=1 + a+b+C+d;
    arr[r][c]=ans;
    return ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    
    int ans=INT_MIN;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=-1;
        }
            
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]==1&&arr[i][j]==-1)
            {
                ans=max(ans,sol(cake,n,i,j,arr));
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
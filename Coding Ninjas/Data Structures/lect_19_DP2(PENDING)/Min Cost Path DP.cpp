/*

An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18

*/

// solution 

#include<bits/stdc++.h>
// dynamic programming solution 

int minCostPath(int **in, int m, int n)
{
    int **out=new int*[m];
    for(int i=0;i<m;i++)
    {
        out[i]=new int[n];
    }
    out[m-1][n-1]=in[m-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
		out[m-1][i]=out[m-1][i+1]+in[m-1][i];
    }
    
    for(int i=m-2;i>=0;i--)
    {
		out[i][n-1]=out[i+1][n-1]+in[i][n-1];
    }
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            out[i][j]=in[i][j]+min(out[i+1][j+1],min(out[i+1][j],out[i][j+1]));
        }
    }
    return out[0][0];
}

/*

// memoisation 

int memoSol(int **input,int m , int n , int r,int c,int **arr)
{
    if(r==m-1&&c==n-1)
        return input[r][c];
    if(r==m||c==n)
        return INT_MAX;
    if(arr[r][c]!=-1)
        return arr[r][c];
    int a1=memoSol(input,m,n,r+1,c+1,arr);
    int a2=memoSol(input,m,n,r+1,c,arr);
    int a3=memoSol(input,m,n,r,c+1,arr);
    int ans=min(a1,min(a2,a3))+input[r][c];
    arr[r][c]=ans;
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    int **arr=new int*[m];
    for(int i=0;i<m;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
			arr[i][j]=-1;
        }
    }
    
    return memoSol(input,m,n,0,0,arr);
}


//recursive - brute force
int Recurrsol(int **input , int Trow,int Tcol , int row, int col)
{
    if(row==Trow-1&&col==Tcol-1)
    {
        return input[row][col];
    }
    if(row==Trow||col==Tcol)
        return INT_MAX;
    
    int a1=Recurrsol(input , Trow,Tcol,row+1,col);
    int a2=Recurrsol(input , Trow,Tcol,row+1,col+1);
    int a3=Recurrsol(input , Trow,Tcol,row,col+1);
    
    return min(a1,min(a2,a3))+input[row][col];
}


int minCostPath(int **input, int m, int n)
{
    return Recurrsol(input , m , n , 0 , 0 );
}

*/

/*

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1

*/


#include <bits/stdc++.h>
using namespace std;
bool sol(vector<vector<char>> &board,bool** visited , int n , int m ,int r,int c,string cn)
{
    if(r>=n||c>=m||r<0||c<0||visited[r][c]||board[r][c]!=cn[0])
        return false;
    if(cn.size()==1)
    {
        if(board[r][c]=='A')
            return true;
        else 
            return false;
    }
    visited[r][c]=true;
    bool a1=sol(board,visited,n,m,r+1,c,cn.substr(1));
    bool a2=sol(board,visited,n,m,r,c+1,cn.substr(1));
    bool a3=sol(board,visited,n,m,r+1,c+1,cn.substr(1));
    bool a4=sol(board,visited,n,m,r-1,c,cn.substr(1));
    bool a5=sol(board,visited,n,m,r,c-1,cn.substr(1));
    bool a6=sol(board,visited,n,m,r-1,c-1,cn.substr(1));
    bool a7=sol(board,visited,n,m,r-1,c+1,cn.substr(1));
    bool a8=sol(board,visited,n,m,r+1,c-1,cn.substr(1));
    return a1||a2||a3||a4||a5||a6||a7||a8;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    bool ** visited=new bool* [n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool [m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='X')
            {
                visited[i][j]=true;
            }
            else 
            {
                visited[i][j]=false;
            }
        }
    }

    bool ans=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            string cn="CODINGNINJA";
            if(board[i][j]=='C'&&!visited[i][j])
            {
                ans=sol(board,visited,n,m,i,j,cn);
                if(ans)
                    return true;
            }

        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
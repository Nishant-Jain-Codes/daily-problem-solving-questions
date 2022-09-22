/*

Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true

*/

// solution 
#include<bits/stdc++.h>
using namespace std;
int sudoku[9][9];

void PrintSudoku()
{
   for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
            {
                cout<<sudoku[i][j]; 
                
            }
           cout<<endl;
       }
}
pair<bool,pair<int,int>> emptyPos()
{
     for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(sudoku[i][j]==0)
                {
                  return{true,{i,j}};
                }
            }
                
        }
        
    return {false,{-1,-1}};
    
}
bool isPossible(int row,int col,int check)
{
   for(int i=0;i<9;i++)//row
   {
       if(sudoku[row][i]==check)
        return false;
   }
   for(int i=0;i<9;i++)//column
   {
       if(sudoku[i][col]==check)
        return false;
   }
   int rowF=(row/3)*3;
   int colF=(col/3)*3;
   for(int i=0;i<3;i++)
   {
       for(int j=0;j<3;j++)
       {
           if(sudoku[rowF+i][colF+j]==check)
            return false;
       }
   }


    return true;
}
bool sudokuSolver()
{
    pair<bool,pair<int,int>> empty = emptyPos();
    int row=empty.second.first;
    int col=empty.second.second;
    if(empty.first==false)
    {
        return true;
    }
    for(int i=1;i<=9;i++)
    {
        if(isPossible(row,col,i))
        {
            sudoku[row][col]=i;
            if(sudokuSolver())
                return true;
            sudoku[row][col]=0;
        }
    }
    return false;
    
}
void sudokuSolverMain()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>sudoku[i][j];
    bool sol=sudokuSolver();
    if(sol)
        cout<<"true";
    else 
        cout<<"false";
}

int main()
{
    sudokuSolverMain();
    return 0;
}

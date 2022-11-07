/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0. Do it in place.
Note : You don't need to print the matrix. Just change in the given input.

Input format :

Line 1 : No. of rows & No. of columns (separated by space)

Line 2 : Row 1 elements (separated by space)

Line 3 : Row 2 elements (separated by space)

Line 4 : and so on

Sample Input 1 :
3 3
1 0 1
1 1 1 
1 1 1
Sample Output 1 :
0 0 0
1 0 1
1 0 1
*/

#include<bits/stdc++.h>
using namespace std;

void makeRowsCols0(int **input, int rows, int cols) {
    // Write your code here
    unordered_map<int,bool> map;
    for(int i=0;i<rows;i++)
    {
        bool have0=false;
        for(int j=0;j<cols;j++)
        {
            if(input[i][j]==0)
            {
                have0=true;
                map[j]=true;
            }
        }
        if(have0)
        {
            for(int k=0;k<cols;k++)
                input[i][k]=0;
        }
    }
    for(auto x:map)
    {
        int c = x.first;
        for(int i=0;i<rows;i++)
            input[i][c]=0;
    }
}



int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
        input[i] = new int[col];
        for(int j = 0; j < col; j++) {
            cin >> input[i][j];
        }
    }
    makeRowsCols0(input, row, col);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

// https://practice.geeksforgeeks.org/problems/make-zeroes4042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=make-zeroes

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int rowT = matrix.size();
        int colT = matrix[0].size();
        int M = 500;
        int P=1999;
        for(int i=0;i<rowT;i++)
        {
            for(int j=0;j<colT;j++){
                if(matrix[i][j]==0){
                int rep=0;
                if(i-1>=0){
                    if(matrix[i-1][j]<P)
                        rep+=matrix[i-1][j]%M;
                    if(matrix[i-1][j]!=0)
                        matrix[i-1][j]+=M;
                }
                if(i+1<rowT){
                    if(matrix[i+1][j]<P)
                        rep+=matrix[i+1][j]%M;
                    if(matrix[i+1][j]!=0)
                        matrix[i+1][j]+=M;
                }
                if(j-1>=0){
                    if(matrix[i][j-1]<P)
                        rep+=matrix[i][j-1]%M;
                    if(matrix[i][j-1]!=0)
                        matrix[i][j-1]+=M;
                }
                if(j+1<colT){
                    if(matrix[i][j+1]<P)
                        rep+=matrix[i][j+1]%M;
                    if(matrix[i][j+1]!=0)
                        matrix[i][j+1]+=M;
                }
                matrix[i][j]=P+rep;
            }
            }
        }
        for(int i=0;i<rowT;i++)
        {
            for(int j=0;j<colT;j++){
                matrix[i][j]%=P;
                if(matrix[i][j]>=M)
                matrix[i][j]=0;
                
                
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
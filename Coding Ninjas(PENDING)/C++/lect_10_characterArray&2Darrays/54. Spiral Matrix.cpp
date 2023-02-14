// https://leetcode.com/problems/spiral-matrix/submissions/897806442/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       
       int m=matrix.size();
        int n=matrix[0].size();
         vector<int>res(m*n);  
        int r=0,c=0,cnt=0; 
        while(r<m && c<n)
        {
            for(int i=c;i<n;i++)
                res[cnt++]=matrix[r][i];
            r++;
            for(int j=r;j<m;j++)
                res[cnt++]=matrix[j][n-1]; 
            n--; 
            if(r<m)
            {
                for(int i=n-1;i>=c;i--)
                    res[cnt++]=matrix[m-1][i];
                m--; 
            }
              if(c<n)
              {
                  for(int j=m-1;j>=r;j--)
                      res[cnt++]=matrix[j][c]; 
                  c++;
              }
        } 
        return res;
    }
};
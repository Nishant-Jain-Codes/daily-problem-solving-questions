//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
class Solution2
{
public:
    int maximalRectangle(vector<vector<int>> &matrix)
    {
        vector<int> heights(matrix[0].size(), 0);
        int ans = 0;
        for(int row=0;row<matrix.size();row++){
            for(int col = 0;col<matrix[0].size();col++){
                if(matrix[row][col] == 0){
                    heights[col] = 0;
                }else{
                    heights[col] += 1;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

private:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> smlToL(n);
        vector<int> smlToR(n);

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            smlToL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            smlToR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int width = smlToR[i] - smlToL[i] - 1;
            int height = heights[i];
            ans = max(ans, width * height);
        }
        return ans;
    }
};

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=M[i][j];
            }
        }
        Solution2 obj;
        return obj.maximalRectangle(matrix);
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
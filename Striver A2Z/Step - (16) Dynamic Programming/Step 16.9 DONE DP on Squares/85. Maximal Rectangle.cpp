class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> heights(matrix[0].size(), 0);
        int ans = 0;
        for(int row=0;row<matrix.size();row++){
            for(int col = 0;col<matrix[0].size();col++){
                if(matrix[row][col] == '0'){
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

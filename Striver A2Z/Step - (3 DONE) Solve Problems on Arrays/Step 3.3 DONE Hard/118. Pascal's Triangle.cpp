// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(1);
        ans.push_back(cur);
        for(int i=0;i<n-1;i++){
            cur.clear();
            for(int j=0;j<=i+1;j++){
                if(j==0||j==i+1)
                {
                    cur.push_back(1);
                }else{
                    cur.push_back(ans[i][j-1]+ans[i][j]);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
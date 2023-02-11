// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //using binary serach on 2d matrix
        int row = matrix.size();
        int column = matrix[0].size();
        int si=0;
        int ei= (row*column)-1;
        while(si<=ei){
            int mid = si+((ei-si)/2);
            int curRow = mid/column;
            int curCol = mid%column;
            if(matrix[curRow][curCol]>target){
                ei=mid-1;
            }else if(matrix[curRow][curCol]<target){
                si=mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};
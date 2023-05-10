// https://leetcode.com/problems/find-a-peak-element-ii/description/


class Solution {
public:
    int maxRowEleIdx(vector<int> &row ){
        int Idx = -1;
        int MaxEle = INT_MIN;
        for(int i=0;i<row.size();i++){
            if(row[i]>MaxEle)
            {
                MaxEle = row[i];
                Idx = i;
            }
        }
        return Idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rowS = 0;
        int rowE = mat.size()-1;
        while(rowS<=rowE){
            int midRow = rowS + ((rowE - rowS)/2);
            int rowMaxIdx = maxRowEleIdx(mat[midRow]);
            if(midRow == 0){
                if(mat[midRow][rowMaxIdx]>mat[midRow+1][rowMaxIdx])
                    return {midRow,rowMaxIdx};
            }
            if(midRow == mat.size()-1){
                if(mat[midRow][rowMaxIdx]>mat[midRow-1][rowMaxIdx])
                    return {midRow,rowMaxIdx};
            }
            if(mat[midRow][rowMaxIdx]>mat[midRow+1][rowMaxIdx] && mat[midRow][rowMaxIdx]>mat[midRow-1][rowMaxIdx])
                return {midRow,rowMaxIdx};
            
            if(mat[midRow][rowMaxIdx]<mat[midRow+1][rowMaxIdx])
                rowS = midRow + 1;
            else 
                rowE = midRow - 1;
        }
        return {-1,-1};
    }
};
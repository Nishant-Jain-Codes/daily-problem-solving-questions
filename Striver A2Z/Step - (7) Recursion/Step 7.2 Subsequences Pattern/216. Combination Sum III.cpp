class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> output;
        int curSum = 0;
        int startNum = 1;
        helper(startNum,curSum,k,n,output,answer);
        return answer;
    }
private:
    void helper(int startNum , int curSum , int k , int target , vector<int> & output , vector<vector<int>> & answer){
        if(k==0){
            if(curSum == target){
                answer.push_back(output);
            }
            return;
        }
        if(curSum == target || startNum>9 || curSum + startNum > target){
            return;
        }
        for(int i=startNum ; i<=9;i++){
            output.push_back(i);
            helper(i+1,curSum+i,k-1,target,output,answer);
            output.pop_back();
        }
    }
};
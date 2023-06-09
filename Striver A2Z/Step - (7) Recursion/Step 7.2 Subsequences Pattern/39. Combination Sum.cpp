class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        vector<int> output;
        set<vector<int>> s;
        helperFunc(0,0,nums,target,output,s);
        answer = vector<vector<int>>(s.begin(),s.end());
        return answer;
    }
private:
    
    void helperFunc(int curIdx , int curSum , vector<int> & nums ,int target , vector<int>& output, set<vector<int>> & answer){
        if(curIdx==nums.size()){
            if(curSum==target){
                answer.insert(output);
            }
            return;
        }
        if(curSum>target){
            return;
        }
        //picking current 
        output.push_back(nums[curIdx]);
        helperFunc(curIdx,curSum+nums[curIdx],nums,target,output,answer);
        output.pop_back();
        //not picking current
        helperFunc(curIdx+1,curSum,nums,target,output,answer);
    }
};
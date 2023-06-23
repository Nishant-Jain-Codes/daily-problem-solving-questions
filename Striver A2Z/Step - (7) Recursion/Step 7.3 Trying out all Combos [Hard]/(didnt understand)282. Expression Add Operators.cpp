class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        helper(num,0,target,0,0,path,ans);
        return ans;    
    }
private:
    void helper(const string& num , int curVal , const int target, int idx , long long prevVal , string path , vector<string>& ans){
        if(idx==num.size()){
            if(curVal==target){
                ans.push_back(path);
            }
            return;
        }
        for(int i=idx ; i<num.size();i++){
            if(i!=idx && num[idx]=='0'){
                break;
            }
            string curStr = num.substr(idx,i-idx+1);
            long long curNum = stoll(curStr);
            if(idx==0){
                helper(num,curNum,target,i+1,curNum,curStr,ans);
            }
            else{
                helper(num,curVal+curNum,target,i+1,curNum,path+"+"+curStr,ans);
                helper(num,curVal-curNum,target,i+1,-curNum,path+"-"+curStr,ans);
                helper(num,curVal-prevVal+prevVal*curNum,target,i+1,prevVal*curNum,path+"*"+curStr,ans);
            }
        }
    }
};
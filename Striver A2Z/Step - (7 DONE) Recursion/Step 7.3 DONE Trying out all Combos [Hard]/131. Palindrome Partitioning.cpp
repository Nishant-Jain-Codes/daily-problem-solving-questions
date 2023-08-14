class Solution {

private:
    bool isPalindrome(const string & s , int start , int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void dfs(int idx , const string & s , vector<string> & output , vector<vector<string>> & result){
        if(idx == s.size()){
            result.push_back(output);
            return;
        }
        
        for(int i = idx ;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                output.push_back(s.substr(idx,i-idx+1));
                dfs(i+1,s,output,result);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> output;
        dfs(0,s,output,result);
        return result ;
    }
};
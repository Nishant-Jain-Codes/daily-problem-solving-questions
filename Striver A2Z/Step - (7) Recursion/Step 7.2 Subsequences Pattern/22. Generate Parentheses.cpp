class Solution {
private:
    void helper(int size , int curOpen , int curClosed , string & output , vector<string> & ans){
        if(curOpen==size && curClosed==size){
            ans.push_back(output);
            return;
        }
        if(curOpen<size){
            output.push_back('(');
            helper(size,curOpen+1,curClosed,output,ans);
            output.pop_back();
        }
        if(curClosed<curOpen){
            output.push_back(')');
            helper(size,curOpen,curClosed+1,output,ans);
            output.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        helper(n,0,0,output,ans);
        return ans;
    }
};
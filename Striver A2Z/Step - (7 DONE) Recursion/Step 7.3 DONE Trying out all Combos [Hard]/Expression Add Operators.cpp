//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> addOperators(string S, int target)
    {
        // code here
        vector<string> answer;
        string path = "";
        dfs(S, target, 0, 0, 0, path, answer);
        return answer;
    }

private:
    void dfs(string & s , int target , int idx , int curVal ,long long prevVal, string path , vector<string>& answer){
        if(idx==s.size()){
            if(curVal==target){
                answer.push_back(path);
            }
            return;
        }
        for(int i=idx ; i<s.size() ; i++){
            if(i!=idx && s[idx]=='0'){
                break;
            }
            string curStr = s.substr(idx,i-idx+1);//to take number from idx to i
            long long curNum = stoll(curStr);
            //if path is empty
            if(idx==0){
                dfs(s,target,i+1,curNum,curNum,curStr,answer);
            }
            //if path is not empty
            else{
                dfs(s,target,i+1,curVal+curNum,curNum,path+"+"+curStr,answer);
                dfs(s,target,i+1,curVal-curNum,-curNum,path+"-"+curStr,answer);
                //to handle multiplication
                dfs(s,target,i+1,curVal-prevVal+prevVal*curNum,prevVal*curNum,path+"*"+curStr,answer);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
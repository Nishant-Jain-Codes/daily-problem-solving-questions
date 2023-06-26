//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<string> answer;
    int target ;
    string S;
public:
    vector<string> addOperators(string s, int t) {
        // code here
        S = s;
        target = t;
        recursion(0,"","",'!',0,0);//(index,previous digit, previous sign , current value , s , target , path , answer)
        return answer;
    }
    void recursion(int idx ,string current , string last , char lastOp , long long lastVal ,long long res  ){
        if(idx == S.size()){
            if(last.size()==0 && res == (long long)target){
                answer.push_back(current);
            }
            return ;
        }
        last += S[idx];
        if(last!="0")
            recursion(idx+1,current,last,lastOp,lastVal,res);
        string x , y , z; 
        x = y = z = current;

        if(x.size()==0)
            recursion(idx+1, last , "",'!',stol(last),stol(last));
        else{
            x += "+" + last;
            y += "-" + last;
            z += "*" + last;
            recursion(idx+1,x,last,'+',stol(last),res+stol(last));
            recursion(idx+1,y,last,'-',stol(last),res-stol(last));
            if(lastOp == '-'){
                res+= lastVal ;
                lastVal *= stol(last);
                res+= lastVal ;
                recursion(idx+1,z,"",lastOp,lastVal,res);
            }
            else if(lastOp == '+'){
                res-= lastVal ;
                lastVal *= stol(last);
                res-= lastVal ;
                recursion(idx+1,z,"",lastOp,lastVal,res);
            }
            else {
                recursion(idx+1, z, "",lastOp , stol(last),stol(last)*res);
            }

        } 

    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
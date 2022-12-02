// https://leetcode.com/problems/generate-parentheses/

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)         cout<<x<<endl;
const string yes = "YES";
const string no = "NO";
void solution();
void YorN(bool ans)
{
    if(ans)
        {
            co(yes);
            
        }
    else 
        {
            co(no);
        }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    // your code goes here
    int t;
    cin>>t;

    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(2^n)
// space complexity : O(2^n)
void generateParenthesis2(int O,int C,int n,string s,vector<string> &ans)
    {
        if(O==0)
        {
            for(int i=0;i<C;i++)
            {
                s.push_back(')');
            }
            ans.push_back(s);
            return ;
        }
        if(O==n||(s[s.size()-1]==')'&&O==C))
        {
            s.push_back('(');
            generateParenthesis2(O-1,C,n,s,ans);
        }
        else
        {
            generateParenthesis2(O-1,C,n,s+'(',ans);
            generateParenthesis2(O,C-1,n,s+')',ans);
        }
        return;
    }
vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesis2(n,n,n,"",ans);
        return ans;
    }
void solution()
{
   int n;
   cin>>n;
   vector<string> ans = generateParenthesis(n);
   co(ans.size());
   for(auto x:ans)
   {
    co(x);
   }

}

//CODE ENDS HERE----------------------------------------------------------------------------------------------
//psuedo code
// if left bracket == n add '('
// if ouput[last] == ')' add '('
//add open bracket or close bracket and callthe 
//recursive function with changed O and C number
//if O ==0 put all C brackets 
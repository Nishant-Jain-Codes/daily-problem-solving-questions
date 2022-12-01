// https://leetcode.com/problems/valid-parentheses/
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
// time complexity :  O(nlogn)
// space complexity : O(n)
bool comp(pair<string,int>p1,pair<string,int>p2)
{
    if(p1.second>p2.second)
        return true;
    else if(p1.second==p2.second)
    {
        if(p1.first<p2.first)
            return true;
        else 
            return false;
    }
    else 
        return false;
}
void solution()
{
    string s;
    cin>>s;
    stack<char> stk;
    bool isBal = true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{'||s[i]=='('||s[i]=='[')
            stk.push(s[i]);
        else 
        {
            if(stk.empty())
            {
                isBal = false;
                break;
            }

            char st = stk.top();
            char t=s[i];
            stk.pop();
            if((st=='{'&&t=='}')||(st=='('&&t==')')||(st=='['&&t==']'))
                continue;
            else 
            {
                isBal = false;
                break;
            }

        }
    }  
    if(!stk.empty())
        isBal=false;
    YorN(isBal);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
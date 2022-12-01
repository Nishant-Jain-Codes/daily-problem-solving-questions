// https://www.hackerrank.com/contests/second/challenges/next-greater-element/submissions/code/1353050672

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
//#define int             long long int
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
t=1;
    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(n)
// space complexity : O(n)
vector<int> nextGreater(vector <int>& v,int n)
    {
        vector<int> nge(n);
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty()&&(v[i]>v[stk.top()]))
            {
                nge[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            nge[stk.top()]=-1;
            stk.pop();
        }
        return nge;
    }
void solution()
{
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        v.push_back(in);
    }
    vector<int> nge = nextGreater(v,n);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" "<<(nge[i]==-1?-1:v[nge[i]])<<endl;
    }
    //cout<<endl;
    
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
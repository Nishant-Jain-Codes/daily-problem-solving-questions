// https://www.codechef.com/problems/MUSROD?tab=statement

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
bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first*p2.second>p2.first*p1.second)
        return true;
    else 
        return false;
}
void solution()
{
    int n;cin>>n;
    int a[n],b[n];
    in(a,n);in(b,n);
    vector<pair<int,int>> in;
    for(int i=0;i<n;i++)
    {
        in.push_back({a[i],b[i]});
    }
    sort(in.begin(),in.end(),comp);
    int pre[n+1];
    pre[0]=0;
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+in[i].first;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+= pre[i]*in[i].second;
    }
    co(ans);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
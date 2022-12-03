// https://www.codechef.com/LP2TO303/problems/FORESTGA?tab=solution


// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)         cout<<x<<endl;
const string yes = "YES";
const string no = "NO";
void solution();
//===============SHORTCUT FUNCTIONS===================
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
void inVec(vector<int>&v,int &n)
{
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        v.push_back(in);
    }
    return;
}
//=============MAIN FUNCTION===============
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
// time complexity :  O(nlogn)
// space complexity : O(n)
const int N = 1e5+10;
int  H[N];
int  R[N];
int n,w,l;
bool grown(int m)
{
    int netreq=w;
    for(int i=0;i<n;i++)
    {
        int add = H[i]+(R[i]*m);
        if(add>=l)
            netreq-=add;
        if(netreq<=0)
            break;
    }
    return netreq<=0;
}
void solution()
{
    cin>>n>>w>>l;
    for(int i=0;i<n;i++)
    {
        cin>>H[i]>>R[i];
    }
    int lo=0,hi=1e18,mid;
    while(hi-lo>1)
    {
        mid = (hi+lo)/2;
        if(grown(mid))
            hi=mid;
        else 
            lo=mid+1;
    }
    if(grown(lo))
    {
        co(lo);
    }
    else
        co(hi);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

// https://www.codechef.com/LP2TO308/problems/MEX

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
    cin>>t;

    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(n)
// space complexity : O(n)
const int N = 1e5+10;
int  arr[N];
void solution()
{
    int n,k;cin>>n>>k;
    int m=INT_MIN;
    unordered_map<int,bool> map;
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        map[in]=true;
        m=max(m,in);
    }
    vector<int> vec;
    for(int i=0;i<=m;i++)
    {
        if(map[i])
            continue;
        else 
            vec.push_back(i);
    }
    int ans;
    if(k<vec.size())
    {
        ans=vec[k];
    }
    else 
    {
        ans = m + 1 +(k-vec.size());
    }
    co(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

// https://www.codechef.com/LP2TO306/problems/SUBINC

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
    int n;cin>>n;
    in(arr,n);
    vector<int> dp(n+1,1);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])
        {
            dp[i]+=dp[i-1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=dp[i];
    }
    co(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

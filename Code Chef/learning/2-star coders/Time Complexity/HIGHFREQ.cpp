// https://www.codechef.com/LP2TO308/problems/HIGHFREQ

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
    unordered_map<int,int> m;
    int mx2=INT_MIN;
    int am1=-1;
    int mx=INT_MIN;
    
    for(int i =0;i<n;i++)
    {
        m[arr[i]]++;
        if(m[arr[i]]>mx)
        {
            mx=m[arr[i]];
            am1=arr[i];
        }

        if(arr[i]!=am1)
        mx2=max(mx2,m[arr[i]]);
    }
    int ans=(mx+1)/2;
    ans=max(ans,mx2);
    co(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

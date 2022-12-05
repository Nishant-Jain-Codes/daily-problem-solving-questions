// https://www.codechef.com/LP2TO308/problems/NODRUGS
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
    int n,k,l;cin>>n>>k>>l;
    int m=INT_MIN,me;
    for(int i=0;i<n-1;i++)
    {
        int in;cin>>in;
        m=max(m,in);
    }
    cin>>me;
    bool ans;
    l--;
    if(k<0)
        ans=me>m;
    else
        ans = me+(l*k)>m;
    YorN(ans);
    
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

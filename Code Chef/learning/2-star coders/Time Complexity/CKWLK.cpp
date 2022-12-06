// https://www.codechef.com/LP2TO308/problems/CKWLK

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)         cout<<x<<endl;
const string yes = "Yes";
const string no = "No";
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
// time complexity :  O(logn)
// space complexity : O(1)
const int N = 1e5+10;
int  arr[N];
bool rec(int n)
{
    if(n<10)
        return n==1;
    return( n%10==0&&rec(n/10))||(n%20==0&&rec(n/20));
}
void solution()
{
    int n;cin>>n;
    bool ans = rec(n);
    YorN(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

// https://www.codechef.com/START69C/problems/PERMUTATION

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
// time complexity :  O(nlogn)
// space complexity : O(n)
const int N = 1e5+10;
int  A[N];
int  B[N];
void solution()
{
    int n;cin>>n;
    in(A,n);
    sort(A,A+n);
    int ans=0;
    if(A[n-1]>n)
        ans=-1;
    if(ans!=-1)
    {
        int i=1;
        while(i<=n)
        {

            if(A[i-1]<i)
            {
                ans+=i-A[i-1];
                i++;
            }
            else if(A[i-1]==i)
            {
                i++;
            }
            else 
            {
                ans=-1;
                break;
            }
        }
    }
    co(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

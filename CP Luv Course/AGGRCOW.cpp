// https://www.spoj.com/problems/AGGRCOW/


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
int n,c;
const int N = 1e5 +10;
int p[N];
bool canPlaceCows(int md)
{
    int lastPos=-1;
    int cow_ct=c;
    for(int i=0;i<n;i++)
    {
        if(p[i]-lastPos>=md||lastPos==-1)
            {
                cow_ct--;
                lastPos=p[i];
            }
            if(cow_ct==0)
                break;
    }
    return cow_ct==0;
}
void solution()
{

    cin>>n>>c;
    in(p,n);
    //binary search
    // TTTTTTTFFFFF
    sort(p,p+n);
    int lo=0,hi=1e9,mid;

    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(canPlaceCows(mid))
            lo=mid;
        else 
            hi=mid-1;
    }
    if(canPlaceCows(hi))
       { co(hi);}
    else
        {co(lo);}
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

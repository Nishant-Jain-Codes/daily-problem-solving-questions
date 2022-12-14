// https://www.codechef.com/START69C/problems/DISTINCTSEQ

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
bool comp(pair<int,int> p1,pair<int,int>p2)
{
    return p1.first<p2.first;
}
void solution()
{
   int n;cin>>n;
   string s;cin>>s;
   vector<pair<char,int>>vp(2*n,{' ',-1});
   for(int i=0;i<2*n;i++)
   {
    vp[i].first=s[i];
    vp[i].second=i+1;
   }
   sort(vp.begin(),vp.end(),comp);
   string p="",q="";
   vector<int>ans;
   for(int i=0;i<n;i++)
   {
    //cout<<vp[i].first;
    p.push_back(vp[i].first);
    ans.push_back(vp[i].second);
   }
   //cout<<endl;
   for(int i=n;i<2*n;i++)
   {
    //cout<<vp[i].first;
    q.push_back(vp[i].first);

   }
   //cout<<endl;
   //co(p);
   //co(q);
   if(p==q)
    {co(-1);}
    else 
    {
        for(auto x :ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
   
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

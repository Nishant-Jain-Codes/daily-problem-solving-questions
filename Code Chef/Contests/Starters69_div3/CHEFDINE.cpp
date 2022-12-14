// https://www.codechef.com/START69C/problems/CHEFDINE
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
    return p1.second<p2.second;
}
void solution()
{
   int n,k;cin>>n>>k;
   vector<pair<int,int>>vp(n,{0,0});
   for(int i=0;i<n;i++)
   {
    int in;
    cin>>in;
    vp[i].first=in;
   } 
   for(int i=0;i<n;i++)
   {
    int in;
    cin>>in;
    vp[i].second=in;
   } 
   sort(vp.begin(),vp.end(),comp);
   //int prevK=-1;
   int ans=0;
   unordered_map<int,bool>map;
   for(auto x : vp)
   {
    if(!k)
    break;
    if(map.count(x.first)>0)
        continue;
    else 
    {
        ans+=x.second;
        k--;
        map[x.first]=true;
    }

   }
   if(k)
    ans=-1;
    co(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

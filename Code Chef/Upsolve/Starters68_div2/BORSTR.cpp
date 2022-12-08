// https://www.codechef.com/problems/BORSTR

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
   string s;cin>>s;
   s.push_back('-');
   vector<pair<int,int>>v(26,{0,0});
   
   int i=0;
   while(i<n)
   {if(s[i]=='-')
    break;
    int cnt=1;
    char curcar = s[i];
    while(s[i]==s[i+1])
    {
        i++;
        cnt++;
    }
    int idx = curcar-'a';
    if(v[idx].first<cnt)
    {
        v[idx].first = cnt;
        v[idx].second = 1;
    }
    else if(v[idx].first==cnt)
    {
        v[idx].second++;
    }
    i++;
   }
   int a1=0;
   for(auto x:v)
   {
    if(x.first>a1)
    {
        if(x.second>1)
        {
            a1=x.first;
        }
        else 
        {
            a1=x.first-1;
        }
    }
   }
   co(a1);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

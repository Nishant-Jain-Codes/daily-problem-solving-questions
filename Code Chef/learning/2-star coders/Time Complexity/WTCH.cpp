// https://www.codechef.com/LP2TO308/problems/WTCH?tab=statement

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
   s='0'+s+'0';
   int ans=0;
   for(int i=1;i<=n;i++)
   {
    if(s[i-1]=='0'&&s[i+1]=='0'&&s[i]=='0')
    {
        ans++;
        s[i]='1';
    }
   }
   co(ans);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

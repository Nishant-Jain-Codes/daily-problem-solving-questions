/*

https://www.codechef.com/START61C/problems/SUBARRAYREM

*/

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define lb             lower_bound
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define mp             make_pair  
#define ub             upper_bound
#define F              first
#define S              second
#define co(x)         cout<<x<<endl;
#define loop(i,a,n)    for(int i=a;i<n;i++)
#define rep(i,a,n)     for(ll i=a;i<n;i++)
#define lop(i,a,n)     for(int i=a;i>n;i--) 
#define rip(i,a,n)     for( ll i=a;i>n;i--)
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
const string yes = "YES";
const string no = "NO";
void solution();
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

int32_t main()
{
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        solution();
     
    }
    return 0;
}


/*

    int n;cin>>n;
    int a[n];
    in(a,n);
    
    int a;cin>>a;
    
    int b;cin>>b;
    
    int c;cin>>c;
    
    int x;cin>>x;
    
    int y;cin>>y;
    
    int z;cin>>z;
    
    int p;cin>>p;
    
    int q;cin>>q;
    
    int r;cin>>r;
    
    int k;cin>>k;
    
    unordered_map<int,int> map;
*/



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)

void solution()
{
    int n;
    cin>>n;
    int c1=0,c0=0;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        if(in==1)
            c1++;
        else 
            c0++;
    }
    int ans=0;
    if(c1==0)
        {
            ans=0;
        }
    else if(c0==0&&c1>0)
        {ans=c1/3;}
    else 
    {
        int c2=c0;

            if((c1-c0)>0)
            {
                c2=c0+((c1-c0)/3);
            }
            ans=min(c1,c2);
        
    }
    cout<<ans<<endl;
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------
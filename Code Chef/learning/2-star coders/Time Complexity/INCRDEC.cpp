// https://www.codechef.com/LP2TO308/problems/INCRDEC

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
int  arr[N];
void solution()
{
    int n;cin>>n;
    in(arr,n);
    vector<int>inc,dec;
    unordered_map<int,int> map;
    bool ans = true;
    for(int i=0;i<n;i++)
    {
        if(map.count(arr[i])>0)
        {
            if(map[arr[i]]==1)
            {
                map[arr[i]]++;
                dec.push_back(arr[i]);
            }
            else
            {
                ans=false;
                break;
            }
        }
        else
        {
            map[arr[i]]=1;
            inc.push_back(arr[i]);
        }
    }
    sort(inc.begin(),inc.end());
    sort(dec.begin(),dec.end(),greater<int>());
    int m1=*max_element(inc.begin(),inc.end());
    int m2=INT_MAX;
    if(dec.size()!=0)
    m2=*max_element(dec.begin(),dec.end());
    if(m1==m2)
        ans=false;
    YorN(ans);
    if(ans)
    {
        for(auto x:inc)
        {
            cout<<x<<" ";
        }
        for(auto x:dec)
        {
            cout<<x<<" ";
        }
         cout<<"\n";
    }
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------

/*

https://www.codechef.com/LP2TO304/problems/CHFPLN?tab=statement

*/

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)	      cout<<x<<endl;
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




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(n)
// space complexity : O(n)

void solution()
{
  
    int n;
    cin>>n;
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        if(map.count(in)>0)
            map[in]++;
        else 
            map[in]=1;
    }
    int ans=0;
    for(auto x:map)
    {
        int add = 0;
        if(x.second>1)
        {
            add = min(x.second,(x.first)-1);
        }
        else 
            add=1;
        ans+=add;
    }
    co(ans);
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
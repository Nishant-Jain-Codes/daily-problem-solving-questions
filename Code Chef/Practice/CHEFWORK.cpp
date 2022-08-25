/*
There are NN workers; each worker is of one of the following three types:

A translator translates some text from Chef's language to another langague.
An author writes some text in Chef's language.
An author-translator can both write a text in Chef's language and translate it to another language.
Chef wants to have some text written and translated into some language (different from Chef's language). Chef can't do either of those tasks, but he can hire workers. For each ii (1 \le i \le N1≤i≤N), if he hires the ii-th worker, he must pay that worker c_ic 
i
​
  coins.

Help Chef find the minimum total number of coins he needs to pay to have a text written and translated. It is guaranteed that it is possible to write and translate a text.

Input
The first line of the input contains a single integer NN denoting the number of workers.
The second line contins NN space-separated integers c_1, c_2, ..., c_Nc 
1
​
 ,c 
2
​
 ,...,c 
N
​
  denoting the numbers of coins Chef has to pay each hired worker.
The third line contains NN space-separated integers t_1, t_2, ..., t_Nt 
1
​
 ,t 
2
​
 ,...,t 
N
​
  denoting the types of workers. For each valid ii, the ii-th worker is a translator if t_i = 1t 
i
​
 =1, an author if t_i = 2t 
i
​
 =2 or an author-translator if t_i = 3t 
i
​
 =3.
Output
Print a single line containing one integer — the minimum number of coins Chef has to pay.

Constraints
1 \le N \le 1,0001≤N≤1,000
1 \le c_i \le 100,0001≤c 
i
​
 ≤100,000 for each valid ii
1 \le t_i \le 31≤t 
i
​
 ≤3 for each valid ii
Subtasks
Subtask #1 (15 points): all workers are author-translators

Subtask #2 (85 points): original constraints

Sample 1:
Input
Output
5
1 3 4 6 8
1 2 1 2 3
4
Explanation:
Chef can hire 2 workers: worker 1, who is a translator, and worker 2, who is an author. In total, he pays them 1 + 3 = 41+3=4 coins.
*/

// solution 

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
#define co(x)	      cout<<x<<endl;
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

int32_t main()
{
	// your code goes here
	

	    solution();
	 
	
	return 0;
}


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : o(N)
// time complexity : O(N)
void solution()
{
    int N;
    cin>>N;
    int c[N],t[N];
    in(c,N);
    in(t,N);
    int min1=INT_MAX;
    int min2=INT_MAX;
    int min3=INT_MAX;
    for(int i =0;i<N;i++)
    {
        if(t[i]==1)
        {
            if(c[i]<min1)
                min1=c[i];
        }
        else if(t[i]==2)
        {
             if(c[i]<min2)
                min2=c[i];
        }
        else 
        {
             if(c[i]<min3)
                min3=c[i];
        }
    }
    int ans=min(min3,min1+min2);
    co(ans);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------

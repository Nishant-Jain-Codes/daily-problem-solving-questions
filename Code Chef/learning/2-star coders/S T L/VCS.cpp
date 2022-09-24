/*

https://www.codechef.com/LP2TO304/problems/VCS

*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n,m,k;
  cin>>n>>m>>k;
    unordered_map<int,bool> ignored;
    for(int i=0;i<m;i++)
    {
        int in;
        cin>>in;
        ignored[in]=true;
    }
    unordered_map<int,bool> tracked;
    for(int i=0;i<k;i++)
    {
        int in;
        cin>>in;
        tracked[in]=true;
    }
    
    int TandI=0;
    int UTandUI=0;
    for(int i=1;i<=n;i++)
    {
        if(ignored.count(i)>0&&tracked.count(i)>0)
        {
            TandI++;
        }
        else if(ignored.count(i)<=0&&tracked.count(i)<=0)
        {
            UTandUI++;
        }
    }
  
  cout<<TandI<<" "<<UTandUI<<endl;
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------

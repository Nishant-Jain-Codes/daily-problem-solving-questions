/*

https://www.codechef.com/submit/SUBSEQDIST?tab=statement

*/


// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  
    int n;cin>>n;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
        int in;cin>>in;
        if(map.count(in)>0)
            map[in]++;
        else 
            map[in]=1;
    }
    int m=0;
  for(auto x:map)
  {
      m=max(m,x.second);
  }
  co(ceil(log2(m)));
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------

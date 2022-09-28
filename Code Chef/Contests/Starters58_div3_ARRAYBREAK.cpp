/*

https://www.codechef.com/START58C/problems/ARRAYBREAK

*/


// solution

// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
  int e=0;
  bool odd=false;
  for(int i=0;i<n;i++)
  {
      int in;cin>>in;
      if(in%2==0)
        e++;
        else 
        odd=true;
  }
    
    int ans;
    if(odd)
    {
        co(e);
    }
    else 
    {
        co(0);
    }
    
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------

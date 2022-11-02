/*

https://www.codechef.com/LP2TO304/problems/SUDBOOKS

*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  stack<int> shelf;
  int q;cin>>q;
  while(q--)
  {
      int in;
      cin>>in;
      if(in==-1)
      {
          if(shelf.empty())
          {
              co("kuchbhi?");
          }
          else 
          {
              co(shelf.top());
              shelf.pop();
          }
      }
      else 
      { int no;cin>>no;
          shelf.push(no);
      }
  }
    
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------

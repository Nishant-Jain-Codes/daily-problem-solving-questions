/*

https://www.codechef.com/LTIME112C/problems/PERMCREATE

*/

// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(1)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
    if(n<4)
    {
        co(-1);
        return ;
    }
    else if(n==4)
    {
        co("2 4 1 3");
    }
    else 
    {
        int n1;
        int n2;
        if(n%2==0)
        {
            n1=n;
            n2=n-1;
        }
        else 
        {
            n1=n-1;
            n2=n;
        }
        while(n1>1)
        {
            cout<<n1<<" ";
            n1-=2;
        }
        while(n2>0)
        {
            
            cout<<n2<<" ";
            n2-=2;
        }
        cout<<endl;
    }
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------

/*

You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9

*/

// solution 


// dynamic programming 
int editDistance_DP(string a,string b)
{
   int **arr=new int*[a.size()+1];
    for(int i=0;i<=a.size();i++)
    {
        arr[i]=new int[b.size()+1];
    }
    arr[0][0]=0;
    for(int i=1;i<=a.size();i++)
    {
        arr[i][0]=i;
    }
    for(int j=1;j<=b.size();j++)
    {
        arr[0][j]=j;
    }
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[a.size()-i]==b[b.size()-j])
                arr[i][j]=arr[i-1][j-1];
            else 
            {
                int x,y,z;
                x=1+arr[i][j-1];
                y=1+arr[i-1][j-1];
                z=1+arr[i-1][j];
                arr[i][j]=min(x,min(y,z));
            }
        }
    }
    return arr[a.size()][b.size()];
}


//memoisation 
int editDistance_memo(string a,string b,int ** arr)
{
    if(a.size()==0||b.size()==0)
    {
        return a.size()+b.size();
    }
    if(arr[a.size()][b.size()]!=-1)
        return arr[a.size()][b.size()];
    int ans;
    if(a[0]==b[0])
    {
        ans= editDistance_memo(a.substr(1),b.substr(1),arr);
    }
    else 
    {
        int aa,bb,cc;
        //delete
        aa=1+editDistance_memo(a,b.substr(1),arr);
        //insert
        bb=1+editDistance_memo(a.substr(1),b,arr);
        //swap
        cc=1+editDistance_memo(a.substr(1),b.substr(1),arr);
        ans= min(aa,min(bb,cc));
    }
    arr[a.size()][b.size()]=ans;
    return ans;
}

int editDistance_memo(string a,string b)
{
    int **arr=new int*[a.size()+1];
    for(int i=0;i<=a.size();i++)
    {
        arr[i]=new int[b.size()+1];
        for(int j=0;j<=b.size();j++)
            arr[i][j]=-1;
    }
    return editDistance_memo(a,b,arr);
}

int editDistance(string s1, string s2)
{
	//Write your code here
    return editDistance_DP(s1,s2);
}

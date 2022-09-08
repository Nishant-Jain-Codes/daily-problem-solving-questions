/*
https://www.codechef.com/problems/DIET



Problem
Read problems statements in Hindi, Mandarin Chinese, Russian, Vietnamese, and Bengali as well.
Chef decided to go on a diet during the following NN days (numbered 11 through NN). Part of the diet plan is to eat KK grams of protein during each day. For each valid ii, Chef wants to buy A_iA 
i
​
  grams of protein in the morning of the ii-th day and then eat KK grams of protein as part of his dinner. If he has any protein remaining, he can store it and use it in later dinners. Initially, Chef is storing 00 grams of protein.

Determine whether Chef will have enough protein all the time during his diet. In case he will not have enough, find the first day on which Chef will be unable to eat KK grams of protein.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains two space-separated integers NN and KK.
The second line contains NN space-separated integers A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
Output
For each test case:

If Chef will have enough protein during his diet, print a single line containing the string "YES".
Otherwise, print a single line containing the string "NO", followed by a space and one integer — the first day when Chef will be unable to eat KK grams of protein.
Constraints
1 \le T \le 2001≤T≤200
1 \le N \le 1001≤N≤100
1 \le K \le 10^61≤K≤10 
6
 
1 \le A_i \le 10^61≤A 
i
​
 ≤10 
6
  for each valid ii
Sample 1:
Input
Output
3
4 5
7 3 6 5
3 4
3 10 10
3 4
8 1 1
YES
NO 1
NO 3
Explanation:
Example case 1: On the first day, Chef buys 77 grams, eats 55 and stores 22 grams for later. On the second day, he buys 33 grams, so he has 55 grams, which is just enough for the dinner on this day. On the third day, he buys 66 grams, eats 55 and stores 11, and on the fourth day, he buys 55 grams, so he has 66 grams — enough for dinner. In the end, he had enough protein to eat during all four dinners.

Example case 2: Chef needs to eat 44 grams of protein on the first day, but he only has 33 grams, so he does not have a sufficient amount of protein already for the first dinner.
*/

// solution 

void solution()
{
        int n;cin>>n;
        int k;cin>>k;
        int a[n];
        in(a,n);
        for(int i=0;i<n;i++)
        {
            if(a[i]>=k)
            {
                if(i==n-1)
                    continue;
                else
                a[i+1]+=(a[i]-k);
            }
            else
                {
                    cout<<"NO "<< i+1<<endl;
                    return ;
                }
                
            
        }
        co(yes);
}

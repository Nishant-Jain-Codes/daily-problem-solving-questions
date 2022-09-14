/*
https://www.codechef.com/LP2TO301/problems/MINPIZZAS?tab=statement

Problem
Chef is throwing a party for his NN friends. There is a pizza store nearby and he wants to buy pizza for his friends. Each pizza has exactly KK slices. Chef's friends get sad if one gets more slices than the other. Also, Chef gets sad if there are some pizza slices left. More formally, suppose Chef buys PP pizzas, then everyone is happy if and only if there is a way to distribute K \cdot PK⋅P slices between NN friends.

You need to find the minimum number of pizzas Chef has to buy to share all the slices among his friends so that none of his friends gets sad. Note that Chef hates pizza and doesn't take any slices.

Input Format
First line of input contains TT, the number of test cases. Then the test cases follow.
Each test case contains two space-separated integers NN and KK, where NN is the number of friends of chef and KK is the number of slices in a pizza.
Output Format
For each test case, print the minimum number of pizzas chef has to buy to share among his friends so that none of his friends gets sad.

Constraints
1 \leq T \leq 2 \cdot 10^51≤T≤2⋅10 
5
 
1 \leq N, K \leq 10^91≤N,K≤10 
9
 
Subtasks
Subtask 1 (100 points): Original constraints
Sample 1:
Input
Output
3
2 2
2 3
4 2
1
2
2
Explanation:
Test case 11: One pizza has 22 slices. And there are 22 friends. So chef can just buy one pizza and give one slice to one friend and another slice to another friend.
Test case 22: One pizza has 33 slices. And there are 22 friends. So chef can't share one pizza without being left out with a slice. So he needs to buy at least 22 pizzas. And if he buys 22 pizzas, he can give 33 slices to one friend and 33 to another. So the minimum number of pizzas chef needs to buy is equal to 22.
Test case 33: One pizza has 22 slices. And there are 44 friends. So chef can't share one pizza among the 44 friends. So he needs to buy at least 22 pizzas. And if he buys 22 pizzas, he can give 11 slice to each of his friends. So the minimum number of pizzas chef needs to buy is equal to 22.
*/

// solution 



void solution()
{
  int n,k;cin>>n>>k;
  int ans=((n*k)/__gcd(n,k))/k;
    co(ans);
  
  
  
}

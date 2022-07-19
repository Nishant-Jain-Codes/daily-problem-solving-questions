/*

Pair Sum
Difficulty: EASY
Contributed By
Deep Mavani
|
Level 1
Avg. time to solve
15 min
Success Rate
85%
Problem Statement
You are given an array/list ‘ARR’ consisting of ‘N’ distinct integers arranged in ascending order. You are also given an integer ‘TARGET’. Your task is to count all the distinct pairs in ‘ARR’ such that their sum is equal to ‘TARGET’.
Note:
1. Pair (x,y) and Pair(y,x) are considered as the same pair. 

2. If there exists no such pair with sum equals to 'TARGET', then return -1.
Example:
Let ‘ARR’ = [1 2 3] and ‘TARGET’ = 4. Then, there exists only one pair in ‘ARR’ with a sum of 4 which is (1, 3). (1, 3) and (3, 1) are counted as only one pair.
Input Format:
The first line of input contains an integer ‘T’ which denotes the number of test cases. 

The first line of each test case contains two single space-separated integers ‘N’ and ‘TARGET’ representing the number of elements in the array/list ‘ARR’ and the required pair-sum respectively.

The next line of each test case contains ‘N’ single space-separated integers denoting the elements of  ‘ARR’.
Output Format :
For each test case, return the numbers of pairs in  ‘ARR’ whose sum is equal to ‘TARGET’.
Note:
You don't need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= ‘T’ <= 100
2 <= ‘N’ <= 5000
1 <= ‘ARR[i]’, ‘TARGET’ <= 10^5

Where ARR[i]’ represents the elements of array/list ‘ARR’. 

Time Limit: 1 sec
Sample Input 1:
2
5 6
1 2 3 4 5
6 7
1 2 3 4 5 6
Sample Output 1:
2
3
Explanation for Sample Output 1:
In test case 1, there exist only 2 pairs whose sum is equal to ‘TARGET’ i.e (1, 5) and (2, 4).

In test case 2, there are 3 pairs whose sum is equal to ‘TARGET’ which are  (1, 6), (2, 5), and (3, 4).
Sample Input 2:
2
4 10
1 3 5 6
5 12
1 3 6 9 11
Sample Output 2:
-1
 2
Explanation for Sample Output 2:
In test case 1, there is not a pair whose sum is equal to ‘TARGET’. So we return -1.

In test case 2, there are 2 pairs whose sum is equal to ‘TARGET’, (1, 11) and (3, 9) respectively.

*/

// solution 


int pairSum(vector<int> &arr, int n, int k){
	
    int size = n;
    int ri = size-1;
    int li=0;
    int count = 0;
    while(li<ri)
    {
        if((arr[li]+arr[ri])==k)
        {
            count++;
            li++;
            ri--;
        }
        else if((arr[li]+arr[ri])>k)
        {
            ri--;
        }
        else
        {
            li++;
        }
    }
    if(count)
    {
        return count ;
    }
    else
    {
        return -1;
    }
}


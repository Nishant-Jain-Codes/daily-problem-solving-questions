/*
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/

// solution 

bool isPalindromePair(vector<string> vect) {
        // Write your code here
        for(int i=0;i<vect.size();i++)
        {
            string target=vect[i];
            for(int j=0;j<target.size();j++)
            {
                add(target.substr(j));
            }
            for(int j=0;j<target.size();j++)
            {
               	add(target.substr(0,j+1));
            }
        }
        bool ans=false;
        for(int i=0;i<vect.size();i++)
        {	
            string str=vect[i];
           	reverse(str.begin(), str.end());
            ans = search(str);
            if(ans)
                return true;
        }
        return false;
    }

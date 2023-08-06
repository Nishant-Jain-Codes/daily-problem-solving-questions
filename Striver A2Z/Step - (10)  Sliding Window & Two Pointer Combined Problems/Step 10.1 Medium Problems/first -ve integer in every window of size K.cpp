#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> input, int k)
{
    vector<int> sol;
    queue<int> q;
    int i = 0;
    int j = 0;
    while (j < input.size())
    {
        if (input[j] < 0)
        {
            q.push(j); // store the index of negative number
        }
        if (j - i + 1 < k) // j - i + 1 = window size
        {
            j++;
        }
        else
        {
            //calculating the answer for the window
            if (q.empty())
                sol.push_back(0);
            else
                sol.push_back(input[q.front()]);
            //sliding the window
            if (!q.empty() && q.front() == i)
                q.pop();
            i++;
            j++;
        }
    }
    return sol;
}
int main()
{
    int n;
    int k;
    cout << "enter n \n";
    cin >> n;
    cout << "enter k \n";
    cin >> k;
    cout << "enter elements \n";
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> sol = solution(input, k);
    cout << "solution \n";
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    return 0;
}
// ouput
// enter n
// 8
// enter k
// 3
// enter elements
// 12 -1 -7 8 -15 30 16 28
// solution
// -1 -1 -7 -15 -15 0
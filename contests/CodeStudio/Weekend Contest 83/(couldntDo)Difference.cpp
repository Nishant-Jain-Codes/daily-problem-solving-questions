vector<int> sieve(int n)
{
    vector<int> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    return primes;
}

vector<int> insertAllPossible(int num, vector<int> &prime)
{
    int i = 0;
    vector<int> arr;
    while (primeArr[i] < num)
    {
        while (num % primeArr[i] == 0)
        {
            arr.push_back(num);
            num /= primeArr[i];
        }
        i++;
    }
    return arr;
}
int difference(vector<int> &a)
{
    // Write your code here
    vector<int> primeArray = sieve(1e4 + 10);
    vector<int> all[a.size()];
    for (int i = 0; i < a.size(); i++)
    {
        all[i] = insertAllPossible(a[i], primeArray);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < all[i].size(); j++)
        {
            cout << all[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
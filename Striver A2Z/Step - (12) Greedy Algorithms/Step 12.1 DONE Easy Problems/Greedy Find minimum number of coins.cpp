vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> answer;
    int minCoins = 0;
    for(int i=coins.size()-1;i>=0;i--){
        while(n>=coins[i]){
            n-=coins[i];
            answer.push_back(coins[i]);
            minCoins++;
        }
    }
    return answer;
}
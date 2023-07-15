bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first < p2.first;
}
int minMoves(int n, vector<int> a)
{
    // Write your code here.
    vector<pair<int, int>> perfectSquaresCost(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        int sqrtNum = sqrt(num);
        int diff = min(abs(num - sqrtNum * sqrtNum), abs((sqrtNum + 1) * (sqrtNum + 1) - num));
        perfectSquaresCost[i].first = diff;
        perfectSquaresCost[i].second = i;
        if(num==0){
            perfectSquaresCost[i].first = 1;
        }
    }

    sort(perfectSquaresCost.begin(), perfectSquaresCost.end(), comp);
//for(int i=0;i<n;i++){
    //    cout<<perfectSquaresCost[i].first<<" ";
    //}
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int cost = perfectSquaresCost[i].first;
        ans += cost;
        //cout<<a[perfectSquaresCost[i].second]<<" "<<cost<<" "<<endl;
    }
    for (int i = n / 2; i < n; i++)
    {
        int cost = 0;
        int no = a[perfectSquaresCost[i].second];
        int sqrtNo = sqrt(no);
        if ( sqrtNo * sqrtNo == no)
        {
            cost = 1;
        }
        ans += cost;
        //cout<<cost<<" ";
    }
    //cout<<endl; 
    return ans;
}

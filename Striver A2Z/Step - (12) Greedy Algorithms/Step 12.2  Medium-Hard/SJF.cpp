#include <bits/stdc++.h>
struct comp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime)
{
    // Write your code here.
    vector<pair<int, int>> processes;
    for (int i = 0; i < n; i++)
    {
        processes.push_back({arrivalTime[i], burstTime[i]});
    }
    sort(processes.begin(), processes.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first; });
    // for(auto x : processes){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    int totalWT = 0;
    int cpuTime = processes[0].first;
    int processIdx = 0;
    int processExec = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    while (processExec < n)
    {
        while (processIdx < n && cpuTime >= processes[processIdx].first)
        {
            pq.push(processes[processIdx]);
            processIdx++;
        }
        if (!pq.empty())
        {
            int AT = pq.top().first;
            int BT = pq.top().second;
            pq.pop();
            totalWT += cpuTime - AT;
            // cout<<processIdx<<" "<<cpuTime<<" "<<AT<<" "<<BT<<" "<<cpuTime-AT<<endl;

            cpuTime += BT;
            processExec++;
        }
        else
        {
            cpuTime++;
        }
    }
    return (float)totalWT / n;
}
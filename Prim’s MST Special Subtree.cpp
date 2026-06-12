#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int> > graph[3001];

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int start;
    cin >> start;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int> >,
        greater<pair<int,int> >
    > pq;

    vector<bool> visited(n + 1, false);

    pq.push({0, start});

    int mstWeight = 0;

    while(!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        mstWeight += weight;

        for(int i = 0; i < graph[node].size(); i++)
        {
            int nextWeight = graph[node][i].first;
            int nextNode = graph[node][i].second;

            if(!visited[nextNode])
            {
                pq.push({nextWeight, nextNode});
            }
        }
    }

    cout << mstWeight << endl;

    return 0;
}

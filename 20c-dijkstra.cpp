#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;

    int node = n;

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";

    cout << endl;

    return 0;
}

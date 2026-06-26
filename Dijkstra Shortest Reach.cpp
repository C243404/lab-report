#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int n, vector<pair<int,int>> adj[], int source) {

    vector<int> dist(n + 1, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {

        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currDist > dist[node])
            continue;

        for (auto neighbor : adj[node]) {

            int next = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[next]) {

                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Shortest Distances:\n";

    for (int i = 1; i <= n; i++) {

        if (i == source)
            continue;

        if (dist[i] == INT_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }

    cout << endl;
}

int main() {

    int n = 4;

    vector<pair<int,int>> adj[n + 1];

    // Graph
    adj[1].push_back({2,24});
    adj[2].push_back({1,24});

    adj[1].push_back({4,20});
    adj[4].push_back({1,20});

    adj[3].push_back({1,3});
    adj[1].push_back({3,3});

    adj[4].push_back({3,12});
    adj[3].push_back({4,12});

    dijkstra(n, adj, 1);

    return 0;
}

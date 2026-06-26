#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights,
                      int src, int dst, int k) {

    vector<pair<int, int>> adj[n];

    for (auto flight : flights) {

        int u = flight[0];
        int v = flight[1];
        int price = flight[2];

        adj[u].push_back({v, price});
    }

    vector<int> cost(n, INT_MAX);

    queue<vector<int>> q;

    q.push({0, src, 0});
    cost[src] = 0;

    while (!q.empty()) {

        int stops = q.front()[0];
        int node = q.front()[1];
        int currCost = q.front()[2];
        q.pop();

        if (stops > k)
            continue;

        for (auto neighbor : adj[node]) {

            int nextNode = neighbor.first;
            int price = neighbor.second;

            if (currCost + price < cost[nextNode]) {

                cost[nextNode] = currCost + price;

                q.push({stops + 1, nextNode, cost[nextNode]});
            }
        }
    }

    if (cost[dst] == INT_MAX)
        return -1;

    return cost[dst];
}

int main() {

    int n = 4;

    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {2,3,100},
        {0,2,500}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    cout << "Cheapest Price = "
         << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> adj;
double ans = 0;

void dfs(int node, int parent, double prob, int depth) {

    int children = 0;

    for (int child : adj[node]) {
        if (child != parent)
            children++;
    }

    if (children == 0) {
        ans += prob * depth;
        return;
    }

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, prob / children, depth + 1);
        }
    }
}

int main() {

    int n;
    cin >> n;

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1.0, 0);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}

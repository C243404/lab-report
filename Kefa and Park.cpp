
#include <iostream>
#include <vector>
using namespace std;

vector<int> cat;
vector<vector<int>> adj;
int n, m, ans = 0;

void dfs(int node, int parent, int consecutiveCats) {

    if (cat[node] == 1)
        consecutiveCats++;
    else
        consecutiveCats = 0;

    if (consecutiveCats > m)
        return;

    bool leaf = true;

    for (int child : adj[node]) {
        if (child != parent) {
            leaf = false;
            dfs(child, node, consecutiveCats);
        }
    }

    if (leaf)
        ans++;
}

int main() {

    cin >> n >> m;

    cat.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << ans << endl;

    return 0;
}

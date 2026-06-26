#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n = grid.size();

    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    queue<vector<int>> q;
    q.push({0, 0, 1});

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;

    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    while (!q.empty()) {

        auto curr = q.front();
        q.pop();

        int r = curr[0];
        int c = curr[1];
        int dist = curr[2];

        if (r == n-1 && c == n-1)
            return dist;

        for (int i = 0; i < 8; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < n
                && grid[nr][nc] == 0
                && !vis[nr][nc]) {

                vis[nr][nc] = 1;
                q.push({nr, nc, dist + 1});
            }
        }
    }

    return -1;
}

int main() {

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    cout << shortestPathBinaryMatrix(grid) << endl;

    return 0;
}

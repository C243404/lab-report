#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int swimInWater(vector<vector<int>>& grid) {

    int n = grid.size();

    vector<vector<int>> time(n, vector<int>(n, INT_MAX));

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    time[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {

        int currTime = pq.top()[0];
        int row = pq.top()[1];
        int col = pq.top()[2];
        pq.pop();

        if (row == n - 1 && col == n - 1)
            return currTime;

        for (int i = 0; i < 4; i++) {

            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < n) {

                int newTime = max(currTime, grid[newRow][newCol]);

                if (newTime < time[newRow][newCol]) {

                    time[newRow][newCol] = newTime;

                    pq.push({newTime, newRow, newCol});
                }
            }
        }
    }

    return -1;
}

int main() {

    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };

    cout << "Minimum Time = " << swimInWater(grid) << endl;

    return 0;
}

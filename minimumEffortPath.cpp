#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {

    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {

        int effort = pq.top()[0];
        int row = pq.top()[1];
        int col = pq.top()[2];
        pq.pop();

        if (row == rows - 1 && col == cols - 1)
            return effort;

        for (int i = 0; i < 4; i++) {

            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols) {

                int edgeCost = abs(heights[row][col] - heights[newRow][newCol]);

                int newEffort = max(effort, edgeCost);

                if (newEffort < dist[newRow][newCol]) {

                    dist[newRow][newCol] = newEffort;

                    pq.push({newEffort, newRow, newCol});
                }
            }
        }
    }

    return 0;
}

int main() {

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort = " << minimumEffortPath(heights) << endl;

    return 0;
}

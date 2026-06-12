#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int,int> getPosition(int num, int n)
{
    int row = n - 1 - (num - 1) / n;
    int col = (num - 1) % n;

    if ((n - 1 - row) % 2 == 1)
    {
        col = n - 1 - col;
    }

    return {row, col};
}

int snakesAndLadders(vector<vector<int> >& board)
{
    int n = board.size();

    queue<pair<int,int> > q;
    vector<bool> visited(n * n + 1, false);

    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        int current = q.front().first;
        int moves = q.front().second;
        q.pop();

        if (current == n * n)
        {
            return moves;
        }

        for (int dice = 1; dice <= 6; dice++)
        {
            int next = current + dice;

            if (next > n * n)
                break;

            pair<int,int> pos = getPosition(next, n);

            int row = pos.first;
            int col = pos.second;

            if (board[row][col] != -1)
            {
                next = board[row][col];
            }

            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, moves + 1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int> > board =
    {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    cout << snakesAndLadders(board);

    return 0;
}

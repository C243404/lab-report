#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int cost;
    int u;
    int v;
};

vector<int> parent;

int findParent(int node)
{
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void Union(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if(a != b)
        parent[b] = a;
}

bool compareEdge(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for(int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    vector<Edge> edges;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int cost =
                abs(points[i][0] - points[j][0]) +
                abs(points[i][1] - points[j][1]);

            edges.push_back({cost,i,j});
        }
    }

    sort(edges.begin(), edges.end(), compareEdge);

    parent.resize(n);

    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int answer = 0;

    for(int i = 0; i < edges.size(); i++)
    {
        if(findParent(edges[i].u) != findParent(edges[i].v))
        {
            Union(edges[i].u, edges[i].v);
            answer += edges[i].cost;
        }
    }

    cout << answer << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u;
    int v;
    int w;
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
    int parentA = findParent(a);
    int parentB = findParent(b);

    if(parentA != parentB)
    {
        parent[parentB] = parentA;
    }
}

bool compareEdges(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int nodes, edgesCount;

    cin >> nodes >> edgesCount;

    vector<Edge> edges;

    for(int i = 0; i < edgesCount; i++)
    {
        Edge e;

        cin >> e.u >> e.v >> e.w;

        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), compareEdges);

    parent.resize(nodes + 1);

    for(int i = 1; i <= nodes; i++)
    {
        parent[i] = i;
    }

    int mstWeight = 0;

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(findParent(u) != findParent(v))
        {
            mstWeight += w;
            Union(u, v);
        }
    }

    cout << "MST Weight = " << mstWeight << endl;

    return 0;
}

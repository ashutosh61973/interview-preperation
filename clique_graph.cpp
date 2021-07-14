#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long

bool check_bipartite(vector<vector<int>> &g, int n)
{
    vector<int> side(n + 1, -1);
    queue<int> q;
    q.push(0);
    side[0] = 0;
    bool is_bipartite = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : g[node])
        {
            if (side[child] == -1)
            {
                side[child] = side[node] ^ 1;
                q.push(child);
            }
            else
            {
                is_bipartite &= side[child] != side[node];
            }
        }
    }
    return is_bipartite;
}
int main()
{

    int n;
    int e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1), cgraph(n + 1);
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < e; i++)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        v[x][y] = 1;
        v[y][x] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int child = 0; child < n; child++)
        {
            if (child == i)
            {
                continue;
            }
            if (!v[i][child])
            {
                cgraph[i].push_back(child);
            }
        }
    }

    if (check_bipartite(cgraph, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<int> adj[], int start)
{
    queue<int> q;
    bool visited[10] = {0};
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        cout << " " << x;

        int n = adj[x].size();

        for (int i = 0; i < n; i++)
        {
            if (!visited[adj[x][i]])
            {
                q.push(adj[x][i]);
                visited[adj[x][i]] = 1;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> u >> v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    cout << endl;
    bfsTraversal(adj, 1);
}
/*
9 9
1 2
1 6
2 3
2 4
6 7
6 9
4 5
7 8
5 8
*/
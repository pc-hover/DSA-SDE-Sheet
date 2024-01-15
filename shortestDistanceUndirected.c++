#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int src, vector<int> &dist, vector<int> adj[])
    {
        queue<pair<int, int>> Q;
        Q.push({src, 0}); // {node,distance}
        dist[src] = 0;
        while (!Q.empty())
        {
            int node = Q.front().first;
            int curr_dist = Q.front().second;

            Q.pop();

            for (auto it : adj[node])
            {
                int newNode = it;
                int distance = curr_dist + 1;
                if (distance < dist[it])
                {
                    Q.push({newNode, distance});
                    dist[it] = distance;
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        int visit[N] = {0};
        vector<int> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(N, 1e6);

        for (int i = 0; i < M; i++)
        {
            if (!visit[i])
            {
                bfs(src, dist, adj);
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e6)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};

int main()
{
    int n = 9;  // Number of nodes
    int m = 10; // Number of edges

    // Edge list representation
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {1, 2},
        {2, 6},
        {6, 7},
        {7, 8},
        {6, 8}};

    int src = 0; // Source node
    Solution s;
    vector<int> ans = s.shortestPath(edges, n, m, src);
    for (auto it : ans)
        cout << " " << it;

    cout << endl;
    return 0;
}

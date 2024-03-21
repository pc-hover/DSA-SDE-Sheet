#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{

public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1); //{0,1,2...}
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node) // find ultimate parent
    {
        if (node == parent[node])
        {
            return node;
        }
        // here we are also performing path compression.
        return parent[node] = findUPar(parent[node]); // here we are simply asigning whole branch parent[] as node
    }
    void unionByRank(int u, int v)
    {
        int ulP_u = findUPar(u);
        int ulP_v = findUPar(v);

        if (ulP_u == ulP_v)
            return;
        if (rank[ulP_u] < rank[ulP_v])
        {
            parent[ulP_u] = ulP_v;
        }
        else if (rank[ulP_v] < rank[ulP_u])
        {
            parent[ulP_v] = ulP_u;
        }
        else
        {
            parent[ulP_v] = ulP_u;
            rank[ulP_u]++;
        }
    }
};
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // Task 1:Find extra edges
        // Task 12: Find required Edges (Number of Components - 1)
        DisjointSet ds(n);
        int extraEdges = 0;
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                ds.unionByRank(u, v);
            }
            else
            {
                extraEdges++;
            }
        }
        int nComponents = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
            {
                nComponents++;
            }
        }
        int ans = nComponents - 1;
        if (extraEdges >= ans)
        {
            return ans;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

    cout << s.makeConnected(n, connections);
    return 0;
}